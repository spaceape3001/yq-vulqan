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

    void    Proxy::dispatch(ProxyFN&& fn)
    {
        if(m_tachyon){
            m_tachyon -> proxy(std::move(fn));
        }
    }
}
