////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Tristate.hpp>
#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Sphere3.hpp>
#include <yq/tachyon/api/3DData.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/typedef/bounds3.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Rendered³Snap : public RenderedSnap, public ③Snap {
        Tensor44D       vm_tensor       = NAN;
        Vector3D        bias{};
        
        Tensor44D       R2L             = IDENTITY;    // thus, local = R2L * rendered
        
        // Our "bounds" in model coordinates
        bounds³_t       bounds;

        //! Override to the view*model matrix (used for billboarding & other effects)  
        bool            vm_override     = false;
        
        Camera³ID       camera;         // this can override the view/projection matrix (optional)

        Rendered³Snap();
        ~Rendered³Snap();
    };
    
    struct Rendered³Data : public RenderedData, public ③Data {
    };
    
/*

    Coordinate transforms... 
    
        P   => projection matrix, maps view space to camera space
        V   => view matrix, maps world space to camera space (which, to compute, is really the inverse of the camera's model matrix)
        D   => domain space (these will have to stack as they may be nested)
        L   => local space (for the rendered/asset)
        R   => rendered space
        M   => model matrix
        
        So, when a bit is missing, use the identity matrix
*/
    
}
