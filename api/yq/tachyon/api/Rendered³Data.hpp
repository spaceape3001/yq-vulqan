////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Sphere3.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/typedef/bounds³.hpp>
#include <yq/tachyon/typedef/rendered³.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Rendered³Snap : public RenderedSnap {
        
        //! Our model matrix (in domain coordinates)
        Tensor44D   model           = IDENTITY;
        
        Tensor44D   vm_tensor       = NAN;
        
        bounds³_t   bounds;

        //! Override to the view*model matrix (used for billboarding & other effects)  
        bool        vm_override     = false;
        
        //! This is who our coordinates are expressed in (Null implies world world)
        //TachyonID   domain;

        Rendered³Snap();
        ~Rendered³Snap();
    };
    
    struct Rendered³Data : public RenderedData {
    };
}
