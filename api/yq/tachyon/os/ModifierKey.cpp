////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/os/ModifierKey.hpp>

#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    bool    has_shift(ModifierKeys keys)
    {
        return keys(ModifierKey::ShiftLeft) || keys(ModifierKey::ShiftRight);
    }
    
    bool    has_control(ModifierKeys keys)
    {
        return keys(ModifierKey::ControlLeft) || keys(ModifierKey::ControlRight);
    }
    
    bool    has_alt(ModifierKeys keys)
    {
        return keys(ModifierKey::AltLeft) || keys(ModifierKey::AltRight);
    }
    
    bool    has_super(ModifierKeys keys)
    {
        return keys(ModifierKey::SuperLeft) || keys(ModifierKey::SuperRight);
    }
    
    bool    has_caps_lock(ModifierKeys keys)
    {
        return keys(ModifierKey::CapsLock);
    }
    
    bool    has_num_lock(ModifierKeys keys)
    {
        return keys(ModifierKey::NumLock);
    }
    
    bool    has_scroll_lock(ModifierKeys keys)
    {
        return keys(ModifierKey::ScrollLock);
    }
}

YQ_TYPE_IMPLEMENT(yq::tachyon::ModifierKey)
YQ_TYPE_IMPLEMENT(yq::tachyon::ModifierKeys)
