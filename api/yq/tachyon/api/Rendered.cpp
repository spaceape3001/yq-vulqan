////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/api/RenderedMetaWriter.hpp>
#include <yq/tachyon/command/rendered/SetWireframeCommand.hpp>
#include <yq/tachyon/pipeline/DrawCall.hpp>
#include <yq/tachyon/vulkan/ViBuffer.hpp>
#include <yq/tachyon/vulkan/ViTexture.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    RenderedData::RenderedData()    = default;
    RenderedData::~RenderedData() = default;

    RenderedSnap::RenderedSnap()    = default;
    RenderedSnap::~RenderedSnap() = default;

    const Pipeline* RenderedSnap::pipeline(RenderMode rm) const
    {
        switch(rm){
        case RenderMode::Ray:
            return pipeline_ray;
        case RenderMode::Light:
            return pipeline_light;
        case RenderMode::Simple:
        default:
            return pipeline_simple;
        }
    }

    struct RenderedMeta::Repo {
        std::vector<const RenderedMeta*>    all;
    };
    
    RenderedMeta::Repo& RenderedMeta::repo()
    {
        static Repo s_repo;
        return s_repo;
    }

    const std::vector<const RenderedMeta*>& RenderedMeta::all()
    {
        return repo().all;
    }

    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    RenderedMeta::RenderedMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
    {
        set(Flag::RENDERED);
        set(Type::Rendered);
        repo().all.push_back(this);
    }

    const Pipeline*    RenderedMeta::pipeline(Pipeline::Role r) const
    {
        auto i = m_pipelines.find(r);
        if(i != m_pipelines.end())
            return i->second;
        return {};
    }

    Pipeline*       RenderedMeta::create_pipeline(Pipeline::Role r, std::function<Pipeline*(Pipeline::Role)> make)
    {
        assert(Meta::thread_safe_write());
        
        auto [i,f] = m_pipelines.insert({r, nullptr});
        if(!f)
            return i->second;
        Pipeline*   p   = make(r);
        i->second       = p;
        if(!m_default){
            m_default                               = p;
            m_pipelines[Pipeline::Role::Default]    = p;
        }
        return p;
    }

    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    Rendered::Rendered(const Param&p) : Tachyon(p), m_pipelines(nullptr)
    {
    }
    
    Rendered::~Rendered()
    {
    }

    void    Rendered::on_set_wireframe_command(const SetWireframeCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        set_wireframe(cmd.wireframe());
    }

    const Pipeline* Rendered::pipeline(RenderMode rm) const
    {
        int     r   = rm.value();
        do {
            if(m_pipelines[(RenderMode::enum_t) r])
                return m_pipelines[(RenderMode::enum_t) r];
        } while(r-- > (int) RenderMode::Simple);
        return metaInfo().default_pipeline();
    }

    Pipeline::Role  Rendered::role(RenderMode rm) const
    {
        const Pipeline* p   = m_pipelines[rm];
        if(!p)
            return Pipeline::Role::Invalid;
        return p->role();
    }

    void            Rendered::set_culled(Tristate v)
    {
        m_culled    = v;
        mark();
    }

    void            Rendered::set_pipeline(clear_k)
    {
        set_pipeline(RenderMode::Simple, CLEAR);
    }
    
    void            Rendered::set_pipeline(nullptr_t)
    {
        set_pipeline(RenderMode::Simple, nullptr);
    }
    
    void            Rendered::set_pipeline(Pipeline::Role r)
    {
        set_pipeline(RenderMode::Simple, r);
    }

    void            Rendered::set_pipeline(RenderMode rm, clear_k)
    {
        m_pipelines[rm]  = nullptr;
        mark();
    }

    void            Rendered::set_pipeline(RenderMode rm, nullptr_t)
    {
        m_pipelines[rm]  = nullptr;
        mark();
    }
    
    void            Rendered::set_pipeline(RenderMode rm, Pipeline::Role role)
    {
        if(role == Pipeline::Role::Invalid){
            m_pipelines[rm]  = nullptr;
        } else {
            const Pipeline*   p   = metaInfo().pipeline(role);
            if(p){
                m_pipelines[rm]  = p;
            } else {
                tachyonWarning << ident() << "::set_pipeline( " << (uint16_t) role << ") cannot find selected pipeline";
            }
        }
        mark();
    }

    void            Rendered::set_wireframe(Tristate v)
    {
        m_wireframe = v;
        mark();
    }
    
    void Rendered::snap(RenderedSnap&sn) const
    {
        Tachyon::snap(sn);
        
        if(m_pipelines[RenderMode::Simple])
            sn.pipeline_simple  = m_pipelines[RenderMode::Simple];
        else
            sn.pipeline_simple  = metaInfo().default_pipeline();
        if(m_pipelines[RenderMode::Light])
            sn.pipeline_light   = m_pipelines[RenderMode::Light];
        else
            sn.pipeline_light   = sn.pipeline_simple;
        if(m_pipelines[RenderMode::Ray])
            sn.pipeline_ray     = m_pipelines[RenderMode::Ray];
        else
            sn.pipeline_ray     = sn.pipeline_light;
        
        sn.wireframe        = m_wireframe;
        //sn.draw_vertex      = m_draw.vertex_count;
        //sn.draw_instance    = m_draw.instance_count;
        sn.culled           = m_culled;
        sn.good             = m_good;
        
        if(!sn.pipeline_light)    // nothing more to do, the rest requires a pipeline
            return ;
        
        const auto& push    = sn.pipeline_light->push();
        if(push.fetch)
            push.fetch(this, sn.push);

        const auto& ibo    = sn.pipeline_light->index_buffer();
        if(ibo && ibo->fetch)
            sn.ibo  = ibo->fetch(this);
        
        const auto& sbos    = sn.pipeline_light->storage_buffers();
        if(!sbos.empty()){
            sn.sbos.reserve(sbos.size());
            for(const auto& sbo : sbos){
                if(sbo.fetch){
                    sn.sbos.push_back(sbo.fetch(this));
                } else {
                    sn.sbos.push_back({});
                }
            }
        }
        
        const auto& texs    = sn.pipeline_light->textures();
        if(!texs.empty()){
            sn.texs.reserve(texs.size());
            for(const auto& tex : texs){
                if(tex.fetch){
                    sn.texs.push_back(tex.fetch(this));
                } else {
                    sn.texs.push_back({});
                }
            }
        }
        
        const auto& ubos    = sn.pipeline_light->uniform_buffers();
        if(!ubos.empty()){
            sn.ubos.reserve(ubos.size());
            for(const auto& ubo : ubos){
                if(ubo.fetch){
                    sn.ubos.push_back(ubo.fetch(this));
                } else {
                    sn.ubos.push_back({});
                }
            }
        }
        
        const auto& vbos    = sn.pipeline_light->vertex_buffers();
        if(!vbos.empty()){
            sn.vbos.reserve(vbos.size());
            for(const auto& vbo : vbos){
                if(vbo.fetch){
                    sn.vbos.push_back(vbo.fetch(this));
                } else {
                    sn.vbos.push_back({});
                }
            }
        }
        
        sn.index_draws  = m_indexDraws;
        sn.vertex_draws = m_vertexDraws;
    }

    void Rendered::init_meta()
    {
        auto w = writer<Rendered>();
        w.description("Render object base");
        w.icon(48, "openicon/icons/png/48x48/actions/format-stroke-color.png");
        w.abstract();
        w.slot(&Rendered::on_set_wireframe_command);

        auto wt = writer<RenderedID>();
        wt.description("Rendered Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Rendered>);
        wt.casts<TachyonID>();
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Rendered)
YQ_TYPE_IMPLEMENT(yq::tachyon::RenderedID)
