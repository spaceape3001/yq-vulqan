////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/Flag.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Modifier Keys
    
        These are obviously used in UI framework, expected/supported modifier keys
    */
    YQ_ENUM(ModifierKey, , 
        Shift       = 0,
        Control,
        Alt,
        Super,
        CapsLock,
        NumLock
    )
    //! Bit mask of modifier keys
    using ModifierKeys  = Flag<ModifierKey,uint8_t>;
}
YQ_TYPE_DECLARE(yq::tachyon::ModifierKey)
YQ_TYPE_DECLARE(yq::tachyon::ModifierKeys)
