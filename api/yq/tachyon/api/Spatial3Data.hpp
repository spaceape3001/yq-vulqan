////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/SpatialData.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    class Spatial³Snap : public SpatialSnap {
        YQ_OBJECT_DECLARE(Spatial³Snap, SpatialSnap)
    public:
        // make sure your sub-class sets these!

        Tensor44D       local2domain    = IDENTITY;
        Tensor44D       domain2local    = IDENTITY;
        
        Spatial³Snap();
        virtual ~Spatial³Snap();
        static void init_meta();
    };
    
    class Spatial³Data : public SpatialData {
        YQ_OBJECT_DECLARE(Spatial³Data, SpatialData)
    public:
    
        Spatial³Data();
        virtual ~Spatial³Data();
        static void init_meta();
    };
}
