////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    enum class MouseMode {
        Normal      = 0x34001,
        Hidden      = 0x34002,
        Disabled    = 0x34003,
        Captured    = 0x34004
    };
}
YQ_TYPE_DECLARE(yq::tachyon::MouseMode)
