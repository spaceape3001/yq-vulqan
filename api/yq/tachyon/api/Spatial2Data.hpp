////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/SpatialData.hpp>
#include <yq/tachyon/typedef/spatial2.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    class Spatial²Snap : public SpatialSnap {
        YQ_OBJECT_DECLARE(Spatial²Snap, SpatialSnap)
    public:
        // make sure your sub-class sets these!

        Tensor44D       local2domain    = IDENTITY;
        Tensor44D       domain2local    = IDENTITY;
        
        Spatial²Snap();
        virtual ~Spatial²Snap();
        static void init_meta();
    };
    
    class Spatial²Data : public SpatialData {
        YQ_OBJECT_DECLARE(Spatial²Data, SpatialData)
    public:
        Spatial²Data();
        virtual ~Spatial²Data();
        static void init_meta();
    };
}
