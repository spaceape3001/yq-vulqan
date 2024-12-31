////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PSpatial3.hpp"
#include <yq/core/Any.hpp>

namespace yq::tachyon {
    PSpatial3::PSpatial3(const ISpatial3&i) : 
        m_domain(i.spatial3(DOMAIN)), 
        m_L2D(i.spatial3(L2D)),
        m_D2L(i.spatial3(D2L))
    {
    }
    
    PSpatial3::~PSpatial3()
    {
    }

    TachyonID           PSpatial3::spatial(domain_k) const 
    {
        return m_domain;
    }
    
    Any                 PSpatial3::spatial(l2d_k) const 
    {
        return Any(m_L2D);
    }
    
    Any                 PSpatial3::spatial(d2l_k) const 
    {
        return Any(m_D2L);
    }
    
    TachyonID           PSpatial3::spatial3(domain_k) const 
    {
        return m_domain;
    }
    
    Tensor44D           PSpatial3::spatial3(l2d_k) const 
    {
        return m_L2D;
    }
    
    Tensor44D           PSpatial3::spatial3(d2l_k) const 
    {
        return m_D2L;
    }
}
