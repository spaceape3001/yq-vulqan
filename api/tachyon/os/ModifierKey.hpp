////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/core/Flag.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    /*! \brief Modifier Keys
    
        These are obviously used in UI framework, expected/supported modifier keys
    */
    YQ_ENUM(ModifierKey, , 
        AltLeft,
        AltRight,
        CapsLock,
        ControlLeft,
        ControlRight,
        NumLock,
        ScrollLock,
        ShiftLeft,
        ShiftRight,
        SuperLeft,
        SuperRight
    )
    //! Bit mask of modifier keys
    using ModifierKeys  = Flag<ModifierKey,uint16_t>;
    
    bool    has_shift(ModifierKeys);
    bool    has_control(ModifierKeys);
    bool    has_alt(ModifierKeys);
    bool    has_super(ModifierKeys);
    bool    has_caps_lock(ModifierKeys);
    bool    has_num_lock(ModifierKeys);
    bool    has_scroll_lock(ModifierKeys);
}
YQ_TYPE_DECLARE(yq::tachyon::ModifierKey)
YQ_TYPE_DECLARE(yq::tachyon::ModifierKeys)
