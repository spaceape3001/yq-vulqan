////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Tristate.hpp>
#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Sphere3.hpp>
#include <yt/3D/3DData.hpp>
#include <yt/scene/RenderedData.hpp>
#include <yt/typedef/bounds3.hpp>
#include <yt/typedef/rendered3.hpp>
#include <yt/typedef/spatial3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Rendered³Snap : public RenderedSnap, public ③Snap {
        Tensor44D       vm_tensor       = NAN;
        
        // Our "bounds" in model coordinates
        bounds³_t       bounds;

        //! Override to the view*model matrix (used for billboarding & other effects)  
        bool            vm_override     = false;
        
        Rendered³Snap();
        ~Rendered³Snap();
    };
    
    struct Rendered³Data : public RenderedData, public ③Data {
    };
}
