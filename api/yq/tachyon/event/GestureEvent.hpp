////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QGestureLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class GestureEvent : public Event {
        YQ_OBJECT_DECLARE(GestureEvent, Event)
    public:
    
        static void init_meta();

    protected:
        GestureEvent(const Header&);
        GestureEvent(const GestureEvent&, const Header&);
        ~GestureEvent();
    
    private:
        GestureEvent(const GestureEvent&) = delete;
        GestureEvent(GestureEvent&&) = delete;
        GestureEvent& operator=(const GestureEvent&) = delete;
        GestureEvent& operator=(GestureEvent&&) = delete;
    };
}
