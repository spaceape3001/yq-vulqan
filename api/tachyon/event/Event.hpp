////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <tachyon/typedef/event.hpp>

namespace yq::tachyon {
    class EventInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        EventInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Something happens
    
        An event is something that happens/commanded (ie, inputs, triggers, windows, etc).
        
        EventProducer is something that can generate events (ie GLFW)
        
        EventSocket is something that can receive events
        
        EventMapper is something that translates between events (ie maps "spacebar" to "a jump command")
        
        EventFrame is a collection of events (and its technically an event socket)
    */
    class Event : public Object, public RefCount, public UniqueID {
        YQ_OBJECT_INFO(EventInfo)
        YQ_OBJECT_DECLARE(Event, Object)
    public:
    
        bool    is_command() const;
        bool    is_input() const;
    
        Event();
        virtual ~Event();
        virtual void        dispatch() {}
        EventProducer*      producer() const { return m_producer; }
        
    private:
        friend class EventProducer;
        
        EventProducer*      m_producer  = nullptr;
        std::atomic<bool>   m_handled{ false };
    };

}
