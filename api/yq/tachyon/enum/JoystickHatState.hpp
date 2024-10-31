////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/core/Flag.hpp>

namespace yq::tachyon {
    YQ_ENUM(JoystickHatState, ,
        Centered        = 0,
        Up              = 1,
        Right           = 2,
        Down            = 4,
        Left            = 8,
        RightUp         = 3,
        RightDown       = 6,
        LeftUp          = 9,
        LeftDown        = 12
    )
}

YQ_TYPE_DECLARE(yq::tachyon::JoystickHatState)
