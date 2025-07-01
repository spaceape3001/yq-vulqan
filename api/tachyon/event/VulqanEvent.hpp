////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Event.hpp>

namespace yq::tachyon {
    class VulqanEventMeta : public EventMeta {
    public:
        VulqanEventMeta(std::string_view zName, EventMeta& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class VulqanEvent : public Event {
        YQ_OBJECT_INFO(VulqanEventMeta)
        YQ_OBJECT_DECLARE(VulqanEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        VulqanEvent(const Param& p = {});
        virtual ~VulqanEvent();
        static void init_meta();
    };
}
