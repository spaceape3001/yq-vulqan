////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Event.hpp>

namespace yq::tachyon {
    class AppEventInfo : public EventInfo {
    public:
        AppEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class AppEvent : public Event {
        YQ_OBJECT_INFO(AppEventInfo)
        YQ_OBJECT_DECLARE(AppEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        AppEvent(const Param& p = {});
        virtual ~AppEvent();
        
        static void init_info();
    };
}
