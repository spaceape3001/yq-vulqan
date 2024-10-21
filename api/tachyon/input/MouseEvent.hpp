////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>

namespace yq::tachyon {
    class MouseEventInfo : public InputEventInfo {
    public:
        MouseEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
    protected:
    };


    class MouseEvent : public InputEvent {
        YQ_OBJECT_INFO(MouseEventInfo)
        YQ_OBJECT_DECLARE(MouseEvent, InputEvent)
    public:
    
        struct Param : public InputEvent::Param {
        };
    
        //  EVENT TODO
    
        MouseEvent(const Param&);
        virtual ~MouseEvent();
    };
}
