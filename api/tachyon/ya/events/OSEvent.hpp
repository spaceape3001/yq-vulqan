////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QOSLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class OSEvent : public Event {
        YQ_OBJECT_DECLARE(OSEvent, Event)
    public:
    
        static void init_info();

    protected:
        OSEvent(const Header&);
        OSEvent(const OSEvent&, const Header&);
        ~OSEvent();
    
    private:
        OSEvent(const OSEvent&) = delete;
        OSEvent(OSEvent&&) = delete;
        OSEvent& operator=(const OSEvent&) = delete;
        OSEvent& operator=(OSEvent&&) = delete;
    };
}
