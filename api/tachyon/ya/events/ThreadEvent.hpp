////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>

namespace yq::tachyon {
    class ThreadEvent : public Event {
        YQ_OBJECT_DECLARE(ThreadEvent, Event)
    public:
    
        static void init_info();

    protected:
        ThreadEvent(const Header&);
        ThreadEvent(const ThreadEvent&, const Header&);
        virtual ~ThreadEvent();
    
    private:
        ThreadEvent(const ThreadEvent&) = delete;
        ThreadEvent(ThreadEvent&&) = delete;
        ThreadEvent& operator=(const ThreadEvent&) = delete;
        ThreadEvent& operator=(ThreadEvent&&) = delete;
    };
}
