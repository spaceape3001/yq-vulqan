////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>

namespace yq::tachyon {
    class WindowEventInfo : public InputEventInfo {
    public:
        WindowEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class WindowEvent : public InputEvent {
        YQ_OBJECT_INFO(WindowEventInfo)
        YQ_OBJECT_DECLARE(WindowEvent, InputEvent)
    public:
    
        //  EVENT TODO
    
        virtual ~WindowEvent();

    protected:
        WindowEvent(Window*);
    private:
        Window* m_window;
    };

}
