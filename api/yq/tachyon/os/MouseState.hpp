////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/MouseButton.hpp>
#include <tachyon/os/MouseMode.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    struct MouseState {
        Vector2D                position{};     //!< Cursor position
        MouseButtons            buttons{};      //!< Buttons down
        MouseMode               mode = MouseMode::Normal;
    };
}
