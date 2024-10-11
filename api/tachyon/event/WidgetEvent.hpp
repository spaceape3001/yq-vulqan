////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>

namespace yq::tachyon {
    class WidgetEventInfo : public EventInfo {
    public:
        template <typename C> class Writer;

        WidgetEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class WidgetEvent : public Event {
        YQ_OBJECT_INFO(WidgetEventInfo)
        YQ_OBJECT_DECLARE(WidgetEvent, Event)
    public:
    
        //  EVENT TODO
    
        WidgetEvent();
        virtual ~WidgetEvent();
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class WidgetEventInfo::Writer : public EventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(WidgetEventInfo* widgetEventInfo) : EventInfo::Writer<C>(widgetEventInfo), m_meta(widgetEventInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(WidgetEventInfo& widgetEventInfo) : Writer(&widgetEventInfo)
        {
        }

    private:
        WidgetEventInfo* m_meta;
    };
}
