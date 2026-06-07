////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>

namespace yq::tachyon {
    class SpatialSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(SpatialSnap,TachyonSnap)
    public:
    
        TypedID       domain;
        
        SpatialSnap();
        virtual ~SpatialSnap();
        static void init_meta();
    };
    
    class SpatialData : public TachyonData {
        YQ_OBJECT_DECLARE(SpatialData,TachyonData)
    public:
        SpatialData();
        virtual ~SpatialData();
        static void init_meta();
    };
}
