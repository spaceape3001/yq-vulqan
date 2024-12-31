////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/scene/SpatialData.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Spatial3Snap : public SpatialSnap {
    
        // make sure your sub-class sets these!

        Tensor44D       local2domain    = IDENTITY;
        Tensor44D       domain2local    = IDENTITY;
    };
    
    struct Spatial3Data : public SpatialData {
    };
}
