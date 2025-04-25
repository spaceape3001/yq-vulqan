////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <tachyon/os/HatState.hpp>
#include <tachyon/typedef/gamepad.hpp>

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
