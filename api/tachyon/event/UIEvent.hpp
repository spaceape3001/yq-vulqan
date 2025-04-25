////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Event.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class UIEvent : public Event {
        YQ_OBJECT_DECLARE(UIEvent, Event)
    public:
    
        static void init_info();

    protected:
        UIEvent(const Header&);
        UIEvent(const UIEvent&, const Header&);
        ~UIEvent();
    
    private:
        UIEvent(const UIEvent&) = delete;
        UIEvent(UIEvent&&) = delete;
        UIEvent& operator=(const UIEvent&) = delete;
        UIEvent& operator=(UIEvent&&) = delete;
    };
}
