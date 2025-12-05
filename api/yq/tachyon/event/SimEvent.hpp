////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QSimLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SimEvent : public Event {
        YQ_OBJECT_DECLARE(SimEvent, Event)
    public:
    
        static void init_meta();

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
