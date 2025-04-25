////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Proxy.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    Proxy::Proxy()
    {
    }
    
    Proxy::~Proxy()
    {
    }

    void    Proxy::mail(const PostCPtr& pp)
    {
        if(m_tachyon && pp){
            m_tachyon -> mail(pp);
        }
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
