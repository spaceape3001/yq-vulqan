////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>

namespace yq {
    namespace engine {
        enum PushConfigType : uint8_t {
            None        = 0,
            Full,
            View,
            Custom
        };
    }
}
