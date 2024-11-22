////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/RenderedBind.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/api/RenderedInfoWriter.hpp>

namespace yq::tachyon {
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

    Tachyon::PostAdvice    Rendered::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const RenderedBind* p = dynamic_cast<const RenderedBind*>(&pp)){
            if(p->rendered() != id())
                return REJECT;
        }
        return {};
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

    void            Rendered::set_pipeline(clear_t)
    {
        m_pipeline  = nullptr;
    }

    void            Rendered::set_pipeline(nullptr_t)
    {
        m_pipeline  = nullptr;
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
    }

    void            Rendered::set_wireframe(Tristate v)
    {
        m_wireframe = v;
    }
    
    void Rendered::snap(RenderedSnap&sn) const
    {
        Tachyon::snap(sn);
    }

    void Rendered::init_info()
    {
        auto w = writer<Rendered>();
        w.description("Render object base");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Rendered)
