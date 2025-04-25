////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <tachyon/typedef/joystick.hpp>
#include <tachyon/os/HatState.hpp>

namespace yq::tachyon {
    struct JoystickSnap : public TachyonSnap {
        std::string             name, guid;
        std::vector<float>      axes;
        std::vector<bool>       buttons;
        std::vector<HatState>   hats;
    };
    
    struct JoystickData : public TachyonData {
    };
}
