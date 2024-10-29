////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/InputEvent.hpp>
#include <yq/tachyon/ModifierKey.hpp>

namespace yq::tachyon {
    class Window;
    class Viewer;

    class KeyboardEventInfo : public InputEventInfo {
    public:
        KeyboardEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class KeyboardEvent : public InputEvent {
        YQ_OBJECT_INFO(KeyboardEventInfo)
        YQ_OBJECT_DECLARE(KeyboardEvent, InputEvent)
        
        template <typename> friend class Ref;
    public:
    
        struct Param : public InputEvent::Param {
            ModifierKeys    modifiers   = {};
        };

        //  EVENT TODO
 
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
        KeyboardEvent(const Param& p);
        virtual ~KeyboardEvent();

    private:
        ModifierKeys        m_modifiers;
    };
}
