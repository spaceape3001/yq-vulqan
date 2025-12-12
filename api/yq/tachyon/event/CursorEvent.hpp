////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QCursorLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's count
    class CursorEvent : public Event {
        YQ_OBJECT_DECLARE(CursorEvent, Event)
    public:
    
        static void init_meta();

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
