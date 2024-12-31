////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Sphere3.hpp>
#include <yq/tachyon/scene/RenderedData.hpp>
#include <yq/tachyon/typedef/bounds3.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Rendered³Snap : public RenderedSnap {
        Tensor44D   vm_tensor       = NAN;
        
        // Our "bounds" in model coordinates
        bounds3_t   bounds;

        // Set this to have coordinates & model transform
        Spatial³ID  spatial;

        //! Override to the view*model matrix (used for billboarding & other effects)  
        bool        vm_override     = false;
        
        Rendered³Snap();
        ~Rendered³Snap();
    };
    
    struct Rendered³Data : public RenderedData {
    };
}
