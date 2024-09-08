////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Enum.hpp>
#include <yq-toolbox/basic/Flag.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>

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
