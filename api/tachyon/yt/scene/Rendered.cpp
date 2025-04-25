////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/msg/Post.hpp>
#include <yt/scene/Rendered.hpp>
#include <yt/scene/RenderedData.hpp>
#include <yt/scene/RenderedInfoWriter.hpp>
#include <tachyon/vulkan/ViBuffer.hpp>
#include <tachyon/vulkan/ViTexture.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    RenderedData::RenderedData()    = default;
    RenderedData::~RenderedData() = default;

    RenderedSnap::RenderedSnap()    = default;
    RenderedSnap::~RenderedSnap() = default;


    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    RenderedInfo::RenderedInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Flag::RENDERED);
        set(Type::Rendered);
    }

    const Pipeline*    RenderedInfo::pipeline(Pipeline::Role r) const
    {
        auto i = m_pipelines.find(r);
        if(i != m_pipelines.end())
            return i->second;
        return {};
    }

    Pipeline*       RenderedInfo::create_pipeline(Pipeline::Role r, std::function<Pipeline*(Pipeline::Role)> make)
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

    Rendered::Rendered(const Param&p) : Tachyon(p)
    {
    }
    
    Rendered::~Rendered()
    {
    }

    const Pipeline* Rendered::pipeline() const
    {
        if(m_pipeline)
            return m_pipeline;
        return metaInfo().default_pipeline();
    }

    Pipeline::Role  Rendered::role() const
    {
        const Pipeline* p   = pipeline();
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
        m_pipeline  = nullptr;
        mark();
    }

    void            Rendered::set_pipeline(nullptr_t)
    {
        m_pipeline  = nullptr;
        mark();
    }
    
    void            Rendered::set_pipeline(Pipeline::Role role)
    {
        if(role == Pipeline::Role::Invalid){
            m_pipeline  = nullptr;
        } else {
            const Pipeline*   p   = metaInfo().pipeline(role);
            if(p){
                m_pipeline  = p;
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
        
        sn.pipeline         = pipeline();
        sn.wireframe        = m_wireframe;
        //sn.draw_vertex      = m_draw.vertex_count;
        //sn.draw_instance    = m_draw.instance_count;
        sn.culled           = m_culled;
        
        if(!sn.pipeline)    // nothing more to do, the rest requires a pipeline
            return ;
        
        const auto& push    = sn.pipeline->push();
        if(push.fetch)
            push.fetch(this, sn.push);

        const auto& ibos    = sn.pipeline->index_buffers();
        if(!ibos.empty()){
            sn.ibos.reserve(ibos.size());
            for(const auto& ibo : ibos){
                if(ibo.fetch){
                    sn.ibos.push_back(ibo.fetch(this));
                } else {
                    sn.ibos.push_back({});
                }
            }
        }
        
        const auto& sbos    = sn.pipeline->storage_buffers();
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
        
        const auto& texs    = sn.pipeline->textures();
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
        
        const auto& ubos    = sn.pipeline->uniform_buffers();
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
        
        const auto& vbos    = sn.pipeline->vertex_buffers();
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
    }

    void Rendered::init_info()
    {
        auto w = writer<Rendered>();
        w.description("Render object base");

        auto wt = writer<RenderedID>();
        wt.description("Rendered Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Rendered)
YQ_TYPE_IMPLEMENT(yq::tachyon::RenderedID)
