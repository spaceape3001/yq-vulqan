////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/MouseButton.hpp>
#include <yq/tachyon/os/MouseMode.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    struct MouseState {
        Vector2D                position{};     //!< Cursor position
        MouseButtons            buttons{};      //!< Buttons down
        MouseMode               mode = MouseMode::Normal;
    };
}
