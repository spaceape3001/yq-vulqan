////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

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
        if(m_tachyon && fn){
            m_tachyon -> proxy(std::move(fn));
        }
    }

    void    Proxy::dispatch(const PostCPtr& pp)
    {
        if(m_tachyon && pp){
            m_tachyon -> mail(RX, pp);
        }
    }
}
