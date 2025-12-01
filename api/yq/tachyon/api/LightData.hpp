////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/light.hpp>

namespace yq::tachyon {
    struct LightSnap : public TachyonSnap {
        RGB3F       color       = {1., 1., 1. };
        float       intensity   = 1.f;
    };
    
    struct LightData : public TachyonData {
    };
}
