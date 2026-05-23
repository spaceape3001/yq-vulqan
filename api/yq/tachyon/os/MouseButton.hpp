////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    enum class MouseButton : uint8_t {
        Button1 = 0,
        Button2 = 1,
        Button3 = 2,
        Button4 = 3,
        Button5 = 4,
        Button6 = 5,
        Button7 = 6,
        Button8 = 7,
        
        Left    = Button1,
        Right   = Button2,
        Middle  = Button3
    };
    
    using MouseButtons  = Flags<MouseButton,uint8_t>;
}
YQ_TYPE_DECLARE(yq::tachyon::MouseButton)
YQ_TYPE_DECLARE(yq::tachyon::MouseButtons)
