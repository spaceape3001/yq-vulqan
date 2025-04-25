////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/KeyboardEvent.hpp>
#include <tachyon/os/KeyCode.hpp>

namespace yq::tachyon {
    class KeyReleaseEvent : public KeyboardEvent {
        YQ_OBJECT_DECLARE(KeyReleaseEvent, KeyboardEvent)
    public:
    
        KeyReleaseEvent(const Header&, ModifierKeys, int, KeyCode);
        
        //! Scan code from the operating system (no interpretation)
        int                 scan() const { return m_scan; }
        
        //! Our internal keycode
        KeyCode             key() const { return m_key; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        static void init_info();

    protected:
        KeyReleaseEvent(const KeyReleaseEvent&, const Header&);
        virtual ~KeyReleaseEvent();
        
    private:
        int             m_scan;
        KeyCode         m_key;
        
        KeyReleaseEvent(const KeyReleaseEvent&) = delete;
        KeyReleaseEvent(KeyReleaseEvent&&) = delete;
        KeyReleaseEvent& operator=(const KeyReleaseEvent&) = delete;
        KeyReleaseEvent& operator=(KeyReleaseEvent&&) = delete;
    };
}
