////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/KeyboardEvent.hpp>
#include <tachyon/os/KeyCode.hpp>

namespace yq::tachyon {
    class KeyRepeatEvent : public KeyboardEvent {
        YQ_OBJECT_DECLARE(KeyRepeatEvent, KeyboardEvent)
    public:
    
        KeyRepeatEvent(const Header&, ModifierKeys, int scan, KeyCode key);
        
        //! Scan code from the operating system (no interpretation)
        int                 scan() const { return m_scan; }
        
        //! Our internal keycode
        KeyCode             key() const { return m_key; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
        
    protected:
        KeyRepeatEvent(const KeyRepeatEvent&, const Header&);
        virtual ~KeyRepeatEvent();
    
    private:
    
        //! 
        int             m_scan;
        KeyCode         m_key;
        
        KeyRepeatEvent(const KeyRepeatEvent&) = delete;
        KeyRepeatEvent(KeyRepeatEvent&&) = delete;
        KeyRepeatEvent& operator=(const KeyRepeatEvent&) = delete;
        KeyRepeatEvent& operator=(KeyRepeatEvent&&) = delete;
    };
}
