////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yt/typedef/joystick.hpp>

namespace yq::tachyon {
    struct JoystickSnap : public TachyonSnap {
    };
    
    struct JoystickData : public TachyonData {
    };
}
