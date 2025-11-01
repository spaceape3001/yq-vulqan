////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    struct LayerSnap : public TachyonSnap {
        int         order = 0;
    };
    
    struct LayerData : public TachyonData {
    };
}
