////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/tachyon/enum/JoystickHatState.hpp>
#include <vector>

namespace yq::tachyon {

    enum class JoystickFlag : uint8_t {
        Present,
        Gamepad
    };
    
    using JoystickFlags = Flags<JoystickFlag,uint8_t>;
    
    struct JoystickState {
        std::string                     name;
        std::vector<float>              axes;
        std::vector<bool>               buttons;
        std::vector<JoystickHatState>   hats;
        JoystickFlags                   flags{};
    };
}
