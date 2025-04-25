////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/KeyboardEvent.hpp>
#include <tachyon/os/KeyCode.hpp>

namespace yq::tachyon {
    class KeyPressEvent : public KeyboardEvent {
        YQ_OBJECT_DECLARE(KeyPressEvent, KeyboardEvent)
    public:
    
        KeyPressEvent(const Header&, ModifierKeys, int, KeyCode);
        
        //! Scan code from the operating system (no interpretation)
        int                 scan() const { return m_scan; }
        
        //! Our internal keycode
        KeyCode             key() const { return m_key; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        static void init_info();

    protected:
        KeyPressEvent(const KeyPressEvent&, const Header&);
        virtual ~KeyPressEvent();
        
    private:
        int             m_scan;
        KeyCode         m_key;
        
        KeyPressEvent(const KeyPressEvent&) = delete;
        KeyPressEvent(KeyPressEvent&&) = delete;
        KeyPressEvent& operator=(const KeyPressEvent&) = delete;
        KeyPressEvent& operator=(KeyPressEvent&&) = delete;
    };
}
