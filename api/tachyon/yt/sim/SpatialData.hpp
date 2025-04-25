////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {
    struct SpatialSnap : public TachyonSnap {
        SpatialID       domain;
    };
    
    struct SpatialData : public TachyonData {
    };
}
