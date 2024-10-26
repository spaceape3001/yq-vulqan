////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/core/Flag.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(MouseButton, ,
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
    );
    
    using MouseButtons  = Flag<MouseButton,uint8_t>;
}
YQ_TYPE_DECLARE(yq::tachyon::MouseButton)
YQ_TYPE_DECLARE(yq::tachyon::MouseButtons)
