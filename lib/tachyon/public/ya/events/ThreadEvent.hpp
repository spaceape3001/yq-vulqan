////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>
#include <yq/tachyon/api/ThreadBind.hpp>
#include <yt/typedef/thread.hpp>

namespace yq::tachyon {
    class Thread;

    class ThreadEventInfo : public EventInfo {
    public:
        ThreadEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ThreadEvent : public Event, public ThreadBind {
        YQ_OBJECT_INFO(ThreadEventInfo)
        YQ_OBJECT_DECLARE(ThreadEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        ThreadEvent(ThreadID, const Param& p = {});
        ThreadEvent(const Thread*, const Param& p = {});
        virtual ~ThreadEvent();
        
        static void init_info();
    };
}
