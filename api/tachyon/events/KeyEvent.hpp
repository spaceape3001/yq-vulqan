////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>
#include <tachyon/enum/ModifierKey.hpp>

namespace yq::tachyon {
    class Window;
    class Viewer;

    class KeyEventInfo : public InputEventInfo {
    public:
        KeyEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class KeyEvent : public InputEvent {
        YQ_OBJECT_INFO(KeyEventInfo)
        YQ_OBJECT_DECLARE(KeyEvent, InputEvent)
    public:
    
        struct Param : public InputEvent::Param {
            ModifierKeys    modifiers   = {};
        };

        //  EVENT TODO
        
        virtual ~KeyEvent();
 
        ModifierKeys        modifiers() const { return m_modifiers; }
        
        bool                shift() const;
        bool                control() const;
        bool                alt() const;
        bool                caps_lock() const;
        bool                nums_lock() const;
        bool                super_key() const;
     
    protected:
        KeyEvent(const Param& p);

    private:
    
        ModifierKeys        m_modifiers;
    };
}
