////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>

namespace yq::tachyon {
    class AppEventInfo : public post::EventInfo {
    public:
        AppEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class AppEvent : public post::Event {
        YQ_OBJECT_INFO(AppEventInfo)
        YQ_OBJECT_DECLARE(AppEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
        };
    
        AppEvent(const Param& p = {});
        virtual ~AppEvent();
        
        static void init_info();
    };
}
