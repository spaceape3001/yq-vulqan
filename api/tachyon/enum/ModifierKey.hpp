////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/Flag.hpp>
#include <meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(ModifierKey, , 
            Shift       = 0,
            Control,
            Alt,
            Super,
            CapsLock,
            NumLock
        )
        using ModifierKeys  = Flag<ModifierKey>;
    }
}
YQ_TYPE_DECLARE(yq::tachyon::LogicOp)
