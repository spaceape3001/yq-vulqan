////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QLightLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class LightEvent : public Event {
        YQ_OBJECT_DECLARE(LightEvent, Event)
    public:
    
        static void init_meta();

    protected:
        LightEvent(const Header&);
        LightEvent(const LightEvent&, const Header&);
        ~LightEvent();
    
    private:
        LightEvent(const LightEvent&) = delete;
        LightEvent(LightEvent&&) = delete;
        LightEvent& operator=(const LightEvent&) = delete;
        LightEvent& operator=(LightEvent&&) = delete;
    };
}
