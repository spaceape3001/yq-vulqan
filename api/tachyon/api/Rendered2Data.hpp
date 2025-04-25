////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Tristate.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/Circle2.hpp>
#include <tachyon/api/2DData.hpp>
#include <tachyon/api/RenderedData.hpp>
#include <tachyon/typedef/bounds2.hpp>
#include <tachyon/typedef/rendered2.hpp>
#include <tachyon/typedef/spatial2.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Rendered²Snap : public RenderedSnap, public ②Snap {
    
        //  TBD....
        Tensor44D       vm_tensor       = NAN;
        
        // Our "bounds" in model coordinates
        bounds²_t       bounds;

        //! Override to the view*model matrix (used for billboarding & other effects)  
        bool            vm_override     = false;

        Rendered²Snap();
        ~Rendered²Snap();
    };
    
    struct Rendered²Data : public RenderedData, public ②Data {
    };
}
