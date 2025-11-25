////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>

namespace yq::tachyon {
    enum class DlgButton : uint8_t {
        None = 0,
        Okay,
        Cancel,
        Yes,
        No
    };
    
    using DlgButtons = Flags<DlgButton>;
}
