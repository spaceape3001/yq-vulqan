////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/os/HatState.hpp>
#include <yt/typedef/gamepad.hpp>

namespace yq::tachyon {
    struct GamepadSnap : public TachyonSnap {
        std::vector<float>      axes;
        std::vector<bool>       buttons;
        std::vector<HatState>   hats;
    };
    
    struct GamepadData : public TachyonData {
    };
}
