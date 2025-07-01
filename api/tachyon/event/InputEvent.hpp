////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Event.hpp>
#include <tachyon/os/ModifierKey.hpp>

namespace yq::tachyon {

    /*! \brief Input event 
    
        This is a common base class for keyboard/mouse events since 
        they both need modifier keys & are attached to windows.
    */
    class InputEvent : public Event {
        YQ_OBJECT_DECLARE(InputEvent, Event)
    public:
    
        static void init_meta();
        
        ModifierKeys        modifiers() const { return m_modifiers; }
        
        bool    alt() const;
        bool    alt_left() const;
        bool    alt_right() const;
        
        bool    caps_lock() const;

        bool    control() const;
        bool    control_left() const;
        bool    control_right() const;

        bool    num_lock() const;

        bool    scroll_lock() const;

        bool    shift() const;
        bool    shift_left() const;
        bool    shift_right() const;

        bool    super() const;
        bool    super_left() const;
        bool    super_right() const;
        
    protected:
        InputEvent(const Header&, ModifierKeys);
        InputEvent(const InputEvent&, const Header&);
        virtual ~InputEvent();

    private:
        ModifierKeys    m_modifiers;
        
        InputEvent(const InputEvent&) = delete;
        InputEvent(InputEvent&&) = delete;
        InputEvent& operator=(const InputEvent&) = delete;
        InputEvent& operator=(InputEvent&&) = delete;
    };
}
