////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/event/Event.hpp>

namespace yq::tachyon {
    class WindowEventInfo : public EventInfo {
    public:
        template <typename C> class Writer;

        WindowEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class WindowEvent : public Event {
        YQ_OBJECT_INFO(WindowEventInfo)
        YQ_OBJECT_DECLARE(WindowEvent, Event)
    public:
    
        //  EVENT TODO
    
        WindowEvent();
        virtual ~WindowEvent();
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class WindowEventInfo::Writer : public EventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(WindowEventInfo* windowEventInfo) : EventInfo::Writer<C>(windowEventInfo), m_meta(windowEventInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(WindowEventInfo& windowEventInfo) : Writer(&windowEventInfo)
        {
        }

    private:
        WindowEventInfo* m_meta;
    };
}
