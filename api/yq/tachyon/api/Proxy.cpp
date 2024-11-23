////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Proxy.hpp"
#include "Tachyon.hpp"

namespace yq::tachyon {
    Proxy::Proxy()
    {
    }
    
    Proxy::~Proxy()
    {
    }

    void    Proxy::dispatch(const PostCPtr& pp)
    {
        if(m_tachyon && pp){
            m_tachyon -> mail(pp);
        }
    }

    TypedID   Proxy::object() const
    {
        return TypedID(m_tachyon);
    }
}
