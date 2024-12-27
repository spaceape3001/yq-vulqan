////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/typedef/bounds³.hpp>
#include <yq/tachyon/typedef/rendered³.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Rendered³Snap : public RenderedSnap {
        //! This is who our coordinates are expressed in
        TachyonID   domain;
        
        //! Our model matrix (in domain coordinates)
        Tensor44D   model           = IDENTITY;
        
        //! Override to the view*model matrix (used for billboarding & other effects)  
        Tensor44D   vm_override     = NAN;
        
        bounds³_t   bounds;
        
        Rendered³Snap();
        ~Rendered³Snap();
    };
    
    struct Rendered³Data : public RenderedData {
    };
}
