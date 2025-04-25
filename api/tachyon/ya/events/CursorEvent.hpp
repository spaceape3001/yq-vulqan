////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QCursorLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class CursorEvent : public Event {
        YQ_OBJECT_DECLARE(CursorEvent, Event)
    public:
    
        static void init_info();

    protected:
        CursorEvent(const Header&);
        CursorEvent(const CursorEvent&, const Header&);
        ~CursorEvent();
    
    private:
        CursorEvent(const CursorEvent&) = delete;
        CursorEvent(CursorEvent&&) = delete;
        CursorEvent& operator=(const CursorEvent&) = delete;
        CursorEvent& operator=(CursorEvent&&) = delete;
    };
}
