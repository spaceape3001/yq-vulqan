////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Event.hpp>

namespace yq::tachyon {
    class VulqanEventInfo : public EventInfo {
    public:
        VulqanEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class VulqanEvent : public Event {
        YQ_OBJECT_INFO(VulqanEventInfo)
        YQ_OBJECT_DECLARE(VulqanEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        VulqanEvent(const Param& p = {});
        virtual ~VulqanEvent();
        static void init_info();
    };
}
