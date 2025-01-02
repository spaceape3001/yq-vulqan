////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>

namespace yq::tachyon {
    class Widget;
    
    class WidgetEventInfo : public EventInfo {
    public:
        WidgetEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class WidgetEvent : public Event {
        YQ_OBJECT_INFO(WidgetEventInfo)
        YQ_OBJECT_DECLARE(WidgetEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        //  EVENT TODO
    
        WidgetEvent(Widget*, const Param& p={});
        virtual ~WidgetEvent();
        
        Widget*     widget() const { return m_widget; }
        
        static void init_info();
        
    private:
        Widget*     m_widget;
    };

}
