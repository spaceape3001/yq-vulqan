////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/joystick.hpp>
#include <yq/tachyon/os/HatState.hpp>

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
