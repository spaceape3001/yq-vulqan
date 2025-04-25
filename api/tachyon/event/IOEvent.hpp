////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QIOLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Event.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class IOEvent : public Event {
        YQ_OBJECT_DECLARE(IOEvent, Event)
    public:
    
        static void init_info();

    protected:
        IOEvent(const Header&);
        IOEvent(const IOEvent&, const Header&);
        ~IOEvent();
    
    private:
        IOEvent(const IOEvent&) = delete;
        IOEvent(IOEvent&&) = delete;
        IOEvent& operator=(const IOEvent&) = delete;
        IOEvent& operator=(IOEvent&&) = delete;
    };
}
