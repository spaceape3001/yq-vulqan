////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViRendered.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/pipeline/Pipeline.hpp>
#include <yq-vulqan/pipeline/PushData.hpp>
#include <yq-vulqan/render/Render3D.hpp>
#include <yq-vulqan/render/Rendered.hpp>
#include <yq-vulqan/viz/ViContext.hpp>
#include <yq-vulqan/viz/ViManager.hpp>
#include <yq-vulqan/viz/ViPipeline.hpp>
#include <yq-vulqan/viz/ViPipelineLayout.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

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
    
    ViRendered::ViRendered()
    {
    }
    
    ViRendered::ViRendered(ViVisualizer&viz, const RenderedCPtr& ren, const ViRenderedOptions& opts)
    {
        if(!viz.device())
            return;
        if(!ren)
            return;
        PipelineCPtr    pipe    = ren->pipeline();
        if(!pipe)
            return ;

        std::error_code ec  = _init(viz, ren, pipe, opts);
        if(ec != std::error_code()){
            vizWarning << "ViRendered -- unable to initialize: " << ec.message();
        }
    }
    
    ViRendered::ViRendered(ViVisualizer& viz, const RenderedCPtr& ren, const PipelineCPtr& pipe, const ViRenderedOptions& opts)
    {
        if(!viz.device())
            return;
        if(!ren)
            return;
        if(!pipe)
            return ;

        std::error_code ec  = _init(viz, ren, pipe, opts);
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
    
    
    std::error_code ViRendered::_init(ViVisualizer& viz, const RenderedCPtr& ren, const PipelineCPtr& pipe, const ViRenderedOptions& opts)
    {
        m_viz           = &viz;
        m_pipeline0     = pipe;
        m_layout        = viz.pipeline_layout_create(*pipe);
        if(!m_layout){
            return errors::rendered_bad_pipeline_layout();
        }
        m_rendered      = ren;
        m_render3d      = dynamic_cast<const Render3D*>(m_rendered.ptr());
        
        if(opts.pipelines){
            m_pipeline  = opts.pipelines->create(*pipe);
        } else {
            m_pipeline  = viz.pipeline_create(*pipe);
        }
        if(!m_pipeline){
            return errors::rendered_bad_pipeline();
        }
        
        ViDataOptions       options;
        options.object      = ren.ptr();
        
        if(m_layout->descriptor_count()){
            options.layout      = m_layout -> descriptor_set_layout();
            if(opts.descriptor_pool){
                options.pool    = opts.descriptor_pool;
            } else {
                options.pool    = viz.descriptor_pool();
            }
            if(options.pool){
                m_status    |= S::Descriptors;
                options.descriptors = ALLOCATE;
            }
        }
        options.shaders     = m_layout -> shader_mask();
        
        std::error_code ec  = _init_data(*m_layout, options);
        if(ec != std::error_code())
            return ec;
        
        if(m_layout -> push_enabled()){
            switch(m_config -> push.type){
            case PushConfigType::Full:
                m_status |= S::Push;
                if(m_render3d){
                    m_status   |= S::FullPush;
                } else {
                    m_status   |= S::ViewPush;
                }
                break;
            case PushConfigType::View:
                m_status |= S::Push;
                m_status |= S::ViewPush;
                break;
            case PushConfigType::Custom:
                if(m_config->push.fetch){
                    m_status |= S::Push;
                    m_status |= S::CustomPush;
                }
                break;
            case PushConfigType::None:
            default:
                break;
            }
        }
        
        if(m_vertex.count){
            m_status |= S::Vertex;
        }
        if(m_index.count){
            m_status |= S::Index;
        }
        
        _import_data();

        if(m_status(S::Descriptors)){
            _publish_data(true);
        }
        return {};
    }
    
    void            ViRendered::_kill()
    {
        _kill_data();
        m_rendered      = {};
        m_pipeline      = {};
        m_pipeline0     = {};
        m_layout        = {};
        m_config        = {};
        m_viz           = nullptr;
    }
    
    void            ViRendered::_record(ViContext& u)
    {
        if(m_pipeline -> bind_point() != VK_PIPELINE_BIND_POINT_GRAPHICS)
            return ;

        Tristate        wireframe   = (u.wireframe == Tristate::INHERIT) ? m_rendered->wireframe() : u.wireframe;
        VkPipeline      vkpipe      = (wireframe == Tristate::YES) ? m_pipeline->wireframe_pipeline() : m_pipeline->pipeline();
        if(vkpipe && (vkpipe != u.pipeline)){
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
                vkCmdBindIndexBuffer(u.command_buffer, m_index.buffers[i], 0, (VkIndexType)(m_config->ibos[i].type.value()));
                vkCmdDrawIndexed(u.command_buffer, m_index.sizes[i], 1, 0, 0, 0);  // possible point of speedup in future
            }
        } else {
            vkCmdDraw(u.command_buffer, m_vertex.maxSize, 1, 0, 0);
        }
    }

    void            ViRendered::_update(ViContext& u)
    {
        _update_data();
        
        if(u.pipeline_rebuild){
            if(u.pipelines){
                m_pipeline      = u.pipelines->create(*m_pipeline0);
            //} else if(u.viz){
                //m_pipeline      = u.viz -> pipeline_create(*m_pipeline0);
            } else {
                m_pipeline      = m_viz -> pipeline_create(*m_pipeline0);
            }
        }
        
        if(m_status(S::FullPush)){
            StdPushData*    push = m_push.create_single<StdPushData>();
            push->time      = u.time;
            push->matrix    = u.world2eye * m_render3d ->model2world();
        } else if(m_status(S::ViewPush)){
            StdPushData*    push = m_push.create_single<StdPushData>();
            push->time      = u.time;
            push->matrix    = u.world2eye;
        } else if(m_status(S::CustomPush)){
            m_push.clear();
            m_config->push.fetch(m_rendered.ptr(), m_push);
        }
    }
    
    bool    ViRendered::consistent() const
    {
        return m_viz ? (m_rendered && m_pipeline && m_layout && m_viz->device()) : (!m_rendered && !m_pipeline && !m_layout);
    }

    void    ViRendered::descriptors()
    {
        if(valid()){
            _descriptors();
        }
    }
    
    std::error_code ViRendered::init(ViVisualizer&viz, const RenderedCPtr& ren, const ViRenderedOptions& opts)
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

        PipelineCPtr    pipe    = ren->pipeline();
        if(!pipe)
            return errors::rendered_missing_pipeline();
        
        std::error_code ec  = _init(viz, ren, pipe, opts);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }
    
    std::error_code ViRendered::init(ViVisualizer&viz, const RenderedCPtr& ren, const PipelineCPtr& pipe, const ViRenderedOptions& opts)
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
        if(!pipe)
            return errors::rendered_null_pipeline();
            
        std::error_code ec  = _init(viz, ren, pipe, opts);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }

    void    ViRendered::kill()
    {
        _kill();
    }
    
    void    ViRendered::record(ViContext& ctx)
    {
        if(valid() && m_pipeline)
            _record(ctx);
    }
    
    void    ViRendered::update(ViContext& u)
    {
        if(valid()){
            _update(u);
        }
    }
    
    bool    ViRendered::valid() const
    {
        return (m_viz && m_viz->device() && m_rendered && m_layout);
    }
}
