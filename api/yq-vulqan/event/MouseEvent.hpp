////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/event/Event.hpp>

namespace yq::tachyon {
    class MouseEventInfo : public EventInfo {
    public:
        template <typename C> class Writer;

        MouseEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class MouseEvent : public Event {
        YQ_OBJECT_INFO(MouseEventInfo)
        YQ_OBJECT_DECLARE(MouseEvent, Event)
    public:
    
        //  EVENT TODO
    
        MouseEvent();
        virtual ~MouseEvent();
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class MouseEventInfo::Writer : public EventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(MouseEventInfo* mouseInputInfo) : EventInfo::Writer<C>(mouseInputInfo), m_meta(mouseInputInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(MouseEventInfo& mouseInputInfo) : Writer(&mouseInputInfo)
        {
        }

    private:
        MouseEventInfo* m_meta;
    };
}
