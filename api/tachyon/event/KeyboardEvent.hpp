////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>

namespace yq::tachyon {
    class KeyboardEventInfo : public EventInfo {
    public:
        template <typename C> class Writer;

        KeyboardEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class KeyboardEvent : public Event {
        YQ_OBJECT_INFO(KeyboardEventInfo)
        YQ_OBJECT_DECLARE(KeyboardEvent, Event)
    public:
    
        //  EVENT TODO
    
        KeyboardEvent();
        virtual ~KeyboardEvent();
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class KeyboardEventInfo::Writer : public EventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(KeyboardEventInfo* keyboardInputInfo) : EventInfo::Writer<C>(keyboardInputInfo), m_meta(keyboardInputInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(KeyboardEventInfo& keyboardInputInfo) : Writer(&keyboardInputInfo)
        {
        }

    private:
        KeyboardEventInfo* m_meta;
    };
}
