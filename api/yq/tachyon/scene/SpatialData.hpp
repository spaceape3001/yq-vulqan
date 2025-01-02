////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {
    struct SpatialSnap : public TachyonSnap {
        SpatialID   domain;
    };
    
    struct SpatialData : public TachyonData {
    };
}
