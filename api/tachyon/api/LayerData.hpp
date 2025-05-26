////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TachyonData.hpp>
#include <tachyon/api/TypedID.hpp>
#include <tachyon/typedef/scene.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    struct LayerSnap : public TachyonSnap {
        int         order = 0;
    };
    
    struct LayerData : public TachyonData {
    };
}
