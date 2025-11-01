////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/logging.hpp>

namespace yq::tachyon {
    Proxy::Proxy()
    {
    }
    
    Proxy::~Proxy()
    {
    }

    bool    Proxy::disabled() const
    {
        return m_flags(F::Disabled);
    }

    void    Proxy::mail(const PostCPtr& pp)
    {
        if(!pp){
            tachyonWarning << "Proxy::mail() -- null post pointer!";
            return;
        }
        
        if(!m_tachyon){
            tachyonWarning << "Proxy::mail({" << pp->metaInfo().name() << ":" << pp->id() << "}) -- null tachyon";
            return ;
        }
        
        m_tachyon -> mail(pp);
    }

    TypedID   Proxy::object() const
    {
        if(!m_tachyon)
            return {};
        return TypedID(m_tachyon);
    }

    TachyonID Proxy::id() const
    {
        if(!m_tachyon)
            return {};
        return m_tachyon -> id();
    }
    
    Types       Proxy::types() const
    {
        if(!m_tachyon)
            return {};
        return m_tachyon->metaInfo().types();
    }
}
