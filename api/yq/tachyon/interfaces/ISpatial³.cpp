////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ISpatial³.hpp"

#include <yq/core/Any.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {

    TachyonID           ISpatial³::spatial(domain_k) const 
    {
        return spatial³(DOMAIN);
    }
    
    Any                 ISpatial³::spatial(l2d_k) const 
    {
        return Any(spatial³(L2D));
    }
    
    Any                 ISpatial³::spatial(d2l_k) const 
    {
        return Any(spatial³(D2L));
    }
}

