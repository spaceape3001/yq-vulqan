////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/SpatialData.hpp>
#include <tachyon/typedef/spatial2.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Spatial²Snap : public SpatialSnap {
        // make sure your sub-class sets these!

        Tensor44D       local2domain    = IDENTITY;
        Tensor44D       domain2local    = IDENTITY;
    };
    
    struct Spatial²Data : public SpatialData {
    };
}
