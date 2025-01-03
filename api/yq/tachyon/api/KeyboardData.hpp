////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/keyboard.hpp>

namespace yq::tachyon {
    struct KeyboardSnap : public TachyonSnap {
    };
    
    struct KeyboardData : public TachyonData {
    };
}
