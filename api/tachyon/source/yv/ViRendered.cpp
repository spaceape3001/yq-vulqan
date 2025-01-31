////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViRendered.hpp>

#include <yq/core/FirstSeen.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/stream/Logger.hpp>
#include <yq/stream/Text.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yt/3D/Rendered3.hpp>
#include <yt/3D/Rendered3Data.hpp>
#include <yt/gfx/PushData.hpp>
#include <yt/gfx/Pipeline.hpp>
#include <yt/scene/Rendered.hpp>
#include <yt/scene/RenderedData.hpp>
#include <yv/VqEnums.hpp>
#include <yv/ViContext.hpp>
#include <yv/ViLogging.hpp>
#include <yv/ViManager.hpp>
#include <yv/ViPipeline.hpp>
#include <yv/ViPipelineLayout.hpp>
#include <yv/ViVisualizer.hpp>


namespace yq::tachyon {
    namespace errors {
        using rendered_bad_state            = error_db::entry<"Rendered is in a bad state">;
        using rendered_existing             = error_db::entry<"Rendered has already been created">;
        using rendered_null_pointer         = error_db::entry<"Rendered pointer is null">;
        using rendered_missing_pipeline     = error_db::entry<"Rendered missing a valid pipeline">;
        using rendered_null_pipeline        = error_db::entry<"Rendered unable to use null pipeline">;
        using rendered_bad_pipeline_layout  = error_db::entry<"Rendered unable to use bad pipeline layout">;
        using rendered_bad_pipeline         = error_db::entry<"Rendered unable to use bad pipeline">;
    }
    
    static constexpr bool       RENDERED_DEBUG_REPORT  = true;
    
    //////////////////////////////////

    ViRendered::ViRendered()
    {
    }
    
    ViRendered::ViRendered(ViVisualizer&viz, const RenderedSnap* ren, const ViRenderedOptions& options)
    {
        if(!viz.device())
            return;
        if(!ren)
            return;
        std::error_code ec  = _init(viz, ren, options);
        if(ec != std::error_code()){
            vizWarning << "ViRendered -- unable to initialize: " << ec.message();
        }
    }
    
    ViRendered::~ViRendered()
    {
        kill();
    }
    
    void            ViRendered::_descriptors()
    {
        _publish_data();
    }
    
    std::error_code ViRendered::_init(ViVisualizer& viz, const RenderedSnap* ren, const ViRenderedOptions& options)
    {
        m_viz           = &viz;
        m_config        = ren->pipeline;
        if(!m_config){
            return errors::rendered_null_pipeline();
        }
        m_id            = ren->id();
        
        m_layout        = viz.pipeline_layout_create(m_config);
        if(!m_layout){
            return errors::rendered_bad_pipeline_layout();
        }
        
        if(options.pipelines){
            m_pipeline  = options.pipelines->create(m_config);
        } else {
            m_pipeline  = viz.pipeline_create(m_config);
        }
        if(!m_pipeline){
            return errors::rendered_bad_pipeline();
        }
        
        ViDataOptions       dataOptions;
        
        if(ren->wireframe == Tristate::YES){
            m_status |= S::Wireframe;
        } else {
            m_status -= S::Wireframe;
        }
        if(ren->self(Type::Rendered³))
            m_status |= S::R3;
        dataOptions.snap    = ren;
        
        if(m_layout->descriptors_defined()){
            dataOptions.layout      = m_layout -> descriptor_set_layout();
            if(options.descriptor_pool){
                dataOptions.pool    = options.descriptor_pool;
            } else {
                dataOptions.pool    = viz.descriptor_pool();
            }
            if(dataOptions.pool){
                m_status    |= S::Descriptors;
                dataOptions.descriptors = ALLOCATE;
            }
        }
        dataOptions.shaders     = m_layout -> shader_mask();
        
        std::error_code ec  = _init_data(*m_layout, dataOptions);
        if(ec != std::error_code())
            return ec;
        
        if(m_vertex.count){
            m_status |= S::Vertex;
        }
        if(m_index.count){
            m_status |= S::Index;
        }
        
        if(m_config->push().type != PushConfigType::None){
            m_status |= S::Push;
        }

        _import_data(ren);

        if(m_status(S::Descriptors)){
            _publish_data(true);
        }
        
        return {};
    }
    
    void            ViRendered::_kill()
    {
        _kill_data();
        m_pipeline      = {};
        m_config        = {};
        m_layout        = {};
        m_config        = {};
        m_viz           = nullptr;
    }
    

    void            ViRendered::_record(ViContext& u)
    {
        if constexpr (RENDERED_DEBUG_REPORT){
            //_debug_report();
        }

        if(m_pipeline -> bind_point() != VK_PIPELINE_BIND_POINT_GRAPHICS)
            return ;

        Tristate        wireframe;
        
        if(u.wireframe != Tristate::INHERIT){
            wireframe   = u.wireframe;
        } else if(m_status(S::Wireframe)){
            wireframe   = Tristate::YES;
        } else
            wireframe   = Tristate::NO;

        VkPipeline      vkpipe      = (wireframe == Tristate::YES) ? m_pipeline->wireframe_pipeline() : m_pipeline->pipeline();

        if(!vkpipe){
            if(wireframe != Tristate::YES){
                vizFirstWarning(this) << "ViRendered(" << hex(this) << ")::_record() with NULL pipeline, skipping.";
                static FirstSeen<const ViRendered*> s_first;
                if(s_first(this)){
                    std::string rep;
                    {
                        stream::Text logger(rep);
                        report(logger);
                    }
                    vizDebug << rep;
                }
            }
            return ;
        }

        if(vkpipe != u.pipeline){
            vkCmdBindPipeline(u.command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipe);
            u.pipeline          = vkpipe;
            u.pipeline_layout   = m_layout->pipeline_layout();
            u.pipeline_shaders  = m_layout->shader_mask();
        }

        if(m_status(S::Push) && !m_push.empty()){
            vkCmdPushConstants(u.command_buffer, u.pipeline_layout, u.pipeline_shaders, 0, m_push.size(), m_push.data() );
        }
        
        if(m_status(S::Descriptors)){
            vkCmdBindDescriptorSets(u.command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, u.pipeline_layout, 0, m_descriptors.size(), m_descriptors.data(), 0, nullptr);
        }
        
        if(m_status(S::Vertex)){
            vkCmdBindVertexBuffers(u.command_buffer, 0,  m_vertex.count, m_vertex.buffers, m_vertex.offsets);
        }
        
        if(m_status(S::Index)){
            for(uint32_t i=0;i<m_index.count;++i){
                vkCmdBindIndexBuffer(u.command_buffer, m_index.buffers[i], 0, (VkIndexType)(m_config->m_indexBuffers[i].type.value()));
                vkCmdDrawIndexed(u.command_buffer, m_index.sizes[i], 1, 0, 0, 0);  // possible point of speedup in future
            }
        } else {
            vkCmdDraw(u.command_buffer, m_vertex.maxSize, 1, 0, 0);
        }
    }
    
    void            ViRendered::_update(ViContext& u, const RenderedSnap* sn, const void* pb)
    {
        _update_data(sn);
        
        if(u.pipeline_rebuild){
            if(u.pipelines){
                m_pipeline      = u.pipelines->create(m_config);
            } else {
                m_pipeline      = m_viz -> pipeline_create(m_config);
            }
        }
        
        if(sn){
            if(sn->wireframe == Tristate::YES){
                m_status |= S::Wireframe;
            } else {
                m_status -= S::Wireframe;
            }
        }
        
        if(pb){
            m_push.clear();
            m_push.append(pb, std::min(m_config->push().size, PushBuffer::CAPACITY));
        } else if(m_config->push().type == PushConfigType::Custom) {
            m_push  = sn->push;
        }
    }
    
    bool    ViRendered::consistent() const
    {
        return m_viz ? (m_pipeline && m_layout && m_viz->device()) : (!m_pipeline && !m_layout);
    }

    void    ViRendered::debug_report() const
    {
        stream::Logger  logger(vizDebug);
        report(logger);
    }

    void    ViRendered::descriptors()
    {
        if(valid()){
            _descriptors();
        }
    }
    
    std::error_code ViRendered::init(ViVisualizer&viz, const RenderedSnap* ren, const ViRenderedOptions& options)
    {
        if(m_viz){
            if(!consistent()){
                return errors::rendered_bad_state();
            }
            return errors::rendered_existing();
        }

        if(!viz.device())
            return errors::visualizer_uninitialized();
        if(!ren)
            return errors::rendered_null_pointer();
            
        std::error_code ec  = _init(viz, ren, options);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }

    void    ViRendered::kill()
    {
        _kill();
    }
    
    ViPipelineCPtr          ViRendered::pipeline() const
    {
        return m_pipeline;
    }
    
    ViPipelineLayoutCPtr    ViRendered::pipeline_layout() const
    {   
        return m_layout;
    }

    void    ViRendered::record(ViContext& ctx)
    {
        if(valid() && m_pipeline)
            _record(ctx);
    }
    
    void ViRendered::report(Stream& out, const ViRenderedReportOptions& options) const
    {
        out << "Report for ViRendered[" << hex(this) << "] " << options.message << "\n";
            //if(!m_rendered){
                //out << "    Rendered:                   [ missing ]\n";
            //} else {
                //out << "    Rendered:                   [" << m_rendered->metaInfo().name() << ":" << m_rendered->id() << "]\n";
            //}

            out << "    Rendered:                   [" << id() << "]\n";

        if(!m_pipeline){
            out << "    ViPipeline:                 [ missing ]\n";
        } else {
            out << "    ViPipeline:                 [" << hex(m_pipeline.ptr()) << "]\n";
            out << "    VkPipeline (pipeline):      [" << hex(m_pipeline->pipeline()) << "]\n";
            out << "    VkPipeline (wireframe):     [" << hex(m_pipeline->wireframe_pipeline()) << "]\n";
        }
        
        if(!m_layout){
            out << "    Pipeline Layout:            [ missing ]\n";
        } else {
            if(m_pipeline && (m_layout != m_pipeline->layout())){
                out << "    Pipeline Layout:            [ contradicts the pipeline! ]\n";
            }
        
            out << "    ViPipelineLayout:           [" << hex(m_layout.ptr()) << "]\n";
            out << "    VkPipelineLayout:           [" << hex(m_layout->pipeline_layout()) << "]\n";
        }
        
        for(uint32_t i=0;i<m_index.count;++i){
            out << "    IBO(" << i << "): " << m_index.sizes[i] << " (indices)\n";
        }
        for(uint32_t i=0;i<m_storage.count;++i){
            out << "    SBO(" << i << "): " << m_storage.bytes[i] << " (bytes)\n";
        }
        for(uint32_t i=0;i<m_uniform.count;++i){
            out << "    UBO(" << i << "): " << m_uniform.bytes[i] << " (bytes)\n";
        }
        for(uint32_t i=0;i<m_texture.count;++i){
            auto & ext = m_texture.extents[i];
            out << "    Tex(" << i << "): " << ext.width << " x " << ext.height << " x " << ext.depth << " (pixels)\n";
        }
        for(uint32_t i=0;i<m_vertex.count;++i){
            out << "    VBO(" << i << "): " << m_vertex.sizes[i] << " (vertices)\n";
        }
        
        if(!descriptors_defined()){
            out << "    >> No descriptors defined <<\n";
        } else {
            out << "    VkDescriptorPool:           [" << hex(descriptor_pool()) << "]\n";
            out << "    VkDescriptorSetLayout:      [" << hex(descriptor_set_layout()) << "]\n";
            
            for(const VkWriteDescriptorSet& w : m_writes){
                out << "        " << to_string_view(w.descriptorType) << ", binding=" << w.dstBinding << ", descriptor_set=" << hex(w.dstSet) << ", count=" << w.descriptorCount;
                if(w.pImageInfo){
                    out << ", imageInfo";
                }
                if(w.pBufferInfo){
                    out << ", bufferInfo";
                }
                out << '\n';
            }
        }

        if(m_layout && options.layout){
            m_layout -> report(out, {
                .message = "(For rendered)"
            });
        }

        if(m_pipeline && options.pipeline){
            m_pipeline -> report(out, {
                .message = "(For rendered)",
                .layout = false
            });
        }
    }

    void            ViRendered::report(const char* cat, LogPriority pri, const ViRenderedReportOptions& options) const
    {
        std::string     text;
        {
        
            stream::Text  out(text);
            report(out, options);
        }
        log_category(cat).getStream(log4cpp_priority(pri)) << text;
    }

    void    ViRendered::update(ViContext& u, const RenderedSnap* sn, const void* pb)
    {
        if(valid()){
            _update(u, sn, pb);
        }
    }

    bool    ViRendered::valid() const
    {
        return (m_viz && m_viz->device() && m_layout);
    }
}
