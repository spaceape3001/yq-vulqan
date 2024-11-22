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

    void    Proxy::dispatch(const PostCPtr& pp)
    {
        if(m_tachyon && pp){
            m_tachyon -> mail(pp);
        }
    }

    TachyonID   Proxy::object() const
    {
        if(!m_tachyon)
            return {};
        return m_tachyon->id();
    }
}
