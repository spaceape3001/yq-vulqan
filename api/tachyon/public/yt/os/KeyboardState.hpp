////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/container/BitArray.hpp>
#include <yt/os/ModifierKey.hpp>

namespace yq::tachyon {
    struct KeyboardState {
        BitArray<uint64_t,8>    keys;           //!< Keys down
        ModifierKeys            modifiers;      //!< Current modifiers
    };
}
