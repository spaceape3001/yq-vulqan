////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/event/Event.hpp>

namespace yq::tachyon {
    class InputEventInfo : public EventInfo {
    public:
        template <typename C> class Writer;

        InputEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class InputEvent : public Event {
        YQ_OBJECT_INFO(InputEventInfo)
        YQ_OBJECT_DECLARE(InputEvent, Event)
    public:
    
        //  EVENT TODO
    
        InputEvent();
        virtual ~InputEvent();
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class InputEventInfo::Writer : public EventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(InputEventInfo* inputEventInfo) : EventInfo::Writer<C>(inputEventInfo), m_meta(inputEventInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(InputEventInfo& inputEventInfo) : Writer(&inputEventInfo)
        {
        }

    private:
        InputEventInfo* m_meta;
    };
}
