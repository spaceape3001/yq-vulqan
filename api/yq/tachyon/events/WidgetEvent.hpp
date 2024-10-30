////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>

namespace yq::tachyon {
    class Widget;
    
    class WidgetEventInfo : public post::EventInfo {
    public:
        WidgetEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class WidgetEvent : public post::Event {
        YQ_OBJECT_INFO(WidgetEventInfo)
        YQ_OBJECT_DECLARE(WidgetEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
        };
    
        //  EVENT TODO
    
        WidgetEvent(Widget*, const Param& p={});
        virtual ~WidgetEvent();
        
        Widget*     widget() const { return m_widget; }
        
    private:
        Widget*     m_widget;
    };

}
