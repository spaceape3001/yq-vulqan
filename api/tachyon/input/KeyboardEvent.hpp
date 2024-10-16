////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>

namespace yq::tachyon {
    class Window;

    class KeyboardEventInfo : public InputEventInfo {
    public:
        KeyboardEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class KeyboardEvent : public InputEvent {
        YQ_OBJECT_INFO(KeyboardEventInfo)
        YQ_OBJECT_DECLARE(KeyboardEvent, InputEvent)
    public:
    
        //  EVENT TODO
    
        KeyboardEvent(Window* w);
        virtual ~KeyboardEvent();
    
        Window* window() const { return m_window; }
        
    private:
        Window*     m_window;
    };
}
