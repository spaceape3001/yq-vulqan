////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/enum/MouseButton.hpp>
#include <yq/tachyon/enum/MouseMode.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    struct MouseState {
        Vector2D                position{};     //!< Cursor position
        MouseButtons            buttons{};      //!< Buttons down
        MouseMode               mode = MouseMode::Normal;
    };
}
