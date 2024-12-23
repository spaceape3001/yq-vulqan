////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/KeyboardEvent.hpp>
#include <yq/tachyon/enum/KeyCode.hpp>

namespace yq::tachyon {
    class KeyReleaseEvent : public KeyboardEvent {
        YQ_OBJECT_DECLARE(KeyReleaseEvent, KeyboardEvent)
    public:
    
        struct Param : public KeyboardEvent::Param {
            int             scan        = 0;
            KeyCode         key         = KeyCode::Unknown;
        };
    
        KeyReleaseEvent(Window*, const Param&);
        KeyReleaseEvent(WindowID, const Param&);
        
        //! Scan code from the operating system (no interpretation)
        int                 scan() const { return m_scan; }
        
        //! Our internal keycode
        KeyCode             key() const { return m_key; }
        
        virtual ~KeyReleaseEvent();
        
        static void init_info();
        
    private:
    
        //! 
        const int             m_scan;
        const KeyCode         m_key;
    };
}
