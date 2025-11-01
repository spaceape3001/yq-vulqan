////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/os/HatState.hpp>
#include <yq/tachyon/typedef/gamepad.hpp>

namespace yq::tachyon {
    struct GamepadSnap : public TachyonSnap {
        std::string             name, guid;
        std::vector<float>      axes;
        std::vector<bool>       buttons;
        std::vector<HatState>   hats;
    };
    
    struct GamepadData : public TachyonData {
    };
}
