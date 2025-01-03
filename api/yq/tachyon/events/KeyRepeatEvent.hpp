////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/KeyboardEvent.hpp>
#include <yq/tachyon/enum/KeyCode.hpp>

namespace yq::tachyon {
    class KeyRepeatEvent : public KeyboardEvent {
        YQ_OBJECT_DECLARE(KeyRepeatEvent, KeyboardEvent)
    public:
    
        struct Param : public KeyboardEvent::Param {
            int             scan        = 0;
            KeyCode         key         = KeyCode::Unknown;
        };
    
        KeyRepeatEvent(Window*, const Param&);
        KeyRepeatEvent(WindowID, const Param&);
        
        //! Scan code from the operating system (no interpretation)
        int                 scan() const { return m_scan; }
        
        //! Our internal keycode
        KeyCode             key() const { return m_key; }
        
        
        virtual ~KeyRepeatEvent();
        
        static void init_info();
        
    private:
    
        //! 
        const int             m_scan;
        const KeyCode         m_key;
    };
}
