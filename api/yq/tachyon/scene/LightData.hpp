////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yt/typedef/light.hpp>

namespace yq::tachyon {
    struct LightSnap : public TachyonSnap {
    };
    
    struct LightData : public TachyonData {
    };
}
