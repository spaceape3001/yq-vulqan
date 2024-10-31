////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>

namespace yq::tachyon {
    class VulqanEventInfo : public post::EventInfo {
    public:
        VulqanEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class VulqanEvent : public post::Event {
        YQ_OBJECT_INFO(VulqanEventInfo)
        YQ_OBJECT_DECLARE(VulqanEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
        };
    
        VulqanEvent(const Param& p = {});
        virtual ~VulqanEvent();
        static void init_info();
    };
}
