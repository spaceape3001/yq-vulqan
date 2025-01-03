////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/keyboard.hpp>

namespace yq::tachyon {
    class Keyboard;

    //! Utiltity to bind a viewer to the whatever...
    class KeyboardBind {
    public:
        KeyboardID    keyboard() const { return m_keyboard; }
        
    protected:
        KeyboardBind(KeyboardID v) : m_keyboard(v) {}
        KeyboardBind(const Keyboard* v);
        virtual ~KeyboardBind() {}
        
        KeyboardID const m_keyboard;
    };
}
