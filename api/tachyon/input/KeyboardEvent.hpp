////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>

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
    public:
    
        struct Param : public InputEvent::Param {
        };

        //  EVENT TODO
        
        virtual ~KeyboardEvent();
    
    protected:
        KeyboardEvent(const Param& p);

    private:
    };
}
