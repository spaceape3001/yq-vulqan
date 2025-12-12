////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QCountLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's count
    class CountEvent : public Event {
        YQ_OBJECT_DECLARE(CountEvent, Event)
    public:
    
        static void init_meta();

    protected:
        CountEvent(const Header&);
        CountEvent(const CountEvent&, const Header&);
        ~CountEvent();
    
    private:
        CountEvent(const CountEvent&) = delete;
        CountEvent(CountEvent&&) = delete;
        CountEvent& operator=(const CountEvent&) = delete;
        CountEvent& operator=(CountEvent&&) = delete;
    };
}
