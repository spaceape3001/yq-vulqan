////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/KeyboardEvent.hpp>
#include <yq/tachyon/KeyCode.hpp>

namespace yq::tachyon {
    class KeyPressEvent : public KeyboardEvent {
        YQ_OBJECT_DECLARE(KeyPressEvent, KeyboardEvent)
    public:
    
        struct Param : public KeyboardEvent::Param {
            int             scan        = 0;
            KeyCode         key         = KeyCode::Unknown;
        };
    
        KeyPressEvent(const Param&);
        
        //! Scan code from the operating system (no interpretation)
        int                 scan() const { return m_scan; }
        
        //! Our internal keycode
        KeyCode             key() const { return m_key; }
        
        
        virtual ~KeyPressEvent();
        
    private:
    
        //! 
        int             m_scan;
        KeyCode         m_key;
    };
}
