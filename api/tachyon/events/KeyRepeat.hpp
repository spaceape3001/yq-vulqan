////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/KeyEvent.hpp>
#include <tachyon/enum/KeyCode.hpp>

namespace yq::tachyon {
    class KeyRepeat : public KeyEvent {
        YQ_OBJECT_DECLARE(KeyRepeat, KeyEvent)
    public:
    
        struct Param : public KeyEvent::Param {
            int             scan        = 0;
            KeyCode         key         = KeyCode::Unknown;
        };
    
        KeyRepeat(const Param&);
        
        //! Scan code from the operating system (no interpretation)
        int                 scan() const { return m_int; }
        
        //! Our internal keycode
        KeyCode             key() const { return m_key; }
        
        
        virtual ~KeyRepeat();
        
    private:
    
        //! 
        int             m_scan;
        KeyCode         m_key;
    };
}
