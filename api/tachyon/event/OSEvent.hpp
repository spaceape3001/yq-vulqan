////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QOSLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Event.hpp>
#include <tachyon/typedef/spatial.hpp>

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
