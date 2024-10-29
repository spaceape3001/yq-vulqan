////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/Event.hpp>

namespace yq::tachyon {
    class WidgetEventInfo : public InputEventInfo {
    public:
        WidgetEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class WidgetEvent : public InputEvent {
        YQ_OBJECT_INFO(WidgetEventInfo)
        YQ_OBJECT_DECLARE(WidgetEvent, InputEvent)
    public:
    
        struct Param : public InputEvent {
        };
    
        //  EVENT TODO
    
        WidgetEvent(const Param&);
        virtual ~WidgetEvent();
    };

}
