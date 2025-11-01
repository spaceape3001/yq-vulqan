////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QAppLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class AppEvent : public Event {
        YQ_OBJECT_DECLARE(AppEvent, Event)
    public:
    
        static void init_meta();

    protected:
        AppEvent(const Header&);
        AppEvent(const AppEvent&, const Header&);
        ~AppEvent();
    
    private:
        AppEvent(const AppEvent&) = delete;
        AppEvent(AppEvent&&) = delete;
        AppEvent& operator=(const AppEvent&) = delete;
        AppEvent& operator=(AppEvent&&) = delete;
    };
}
