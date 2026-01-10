////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/key_array.hpp>
#include <yq/tachyon/os/ModifierKey.hpp>

namespace yq::tachyon {
    struct KeyboardState {
        key_array_t     keys;           //!< Keys down
        ModifierKeys    modifiers;      //!< Current modifiers
    };
}
