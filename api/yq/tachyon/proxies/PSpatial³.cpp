////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PSpatial³.hpp"
#include <yq/core/Any.hpp>

namespace yq::tachyon {
    PSpatial³::PSpatial³(const ISpatial³&i) : 
        m_domain(i.spatial³(DOMAIN)), 
        m_L2D(i.spatial³(L2D)),
        m_D2L(i.spatial³(D2L))
    {
    }
    
    PSpatial³::~PSpatial³()
    {
    }

    TachyonID           PSpatial³::spatial(domain_k) const 
    {
        return m_domain;
    }
    
    Any                 PSpatial³::spatial(l2d_k) const 
    {
        return Any(m_L2D);
    }
    
    Any                 PSpatial³::spatial(d2l_k) const 
    {
        return Any(m_D2L);
    }
    
    TachyonID           PSpatial³::spatial³(domain_k) const 
    {
        return m_domain;
    }
    
    Tensor44D           PSpatial³::spatial³(l2d_k) const 
    {
        return m_L2D;
    }
    
    Tensor44D           PSpatial³::spatial³(d2l_k) const 
    {
        return m_D2L;
    }
}
