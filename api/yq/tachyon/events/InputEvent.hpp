////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/api/WindowBind.hpp>
#include <yq/tachyon/enum/ModifierKey.hpp>

namespace yq::tachyon {
    class InputEventInfo : public EventInfo {
    public:
        InputEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };
    
    class Window;

    /*! \brief Input event 
    
        This is a common base class for keyboard/mouse events since 
        they both need modifier keys & are attached to windows.
    */
    class InputEvent : public Event, public WindowBind {
        YQ_OBJECT_INFO(InputEventInfo)
        YQ_OBJECT_DECLARE(InputEvent, Event)
    public:
    
        static void init_info();
    
        struct Param : public Event::Param {
            ModifierKeys    modifiers   = {};
        };
    
        //  EVENT TODO
    
        virtual ~InputEvent();
        
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
        InputEvent(WindowID, const Param&);
        InputEvent(const Window*, const Param&);

    private:
        const ModifierKeys    m_modifiers;
    };
}
