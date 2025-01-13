////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QSimLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SimEvent : public Event {
        YQ_OBJECT_DECLARE(SimEvent, Event)
    public:
    
        static void init_info();

    protected:
        SimEvent(const Header&);
        SimEvent(const SimEvent&, const Header&);
        ~SimEvent();
    
    private:
        SimEvent(const SimEvent&) = delete;
        SimEvent(SimEvent&&) = delete;
        SimEvent& operator=(const SimEvent&) = delete;
        SimEvent& operator=(SimEvent&&) = delete;
    };
}
