////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QColorLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class ColorEvent : public Event {
        YQ_OBJECT_DECLARE(ColorEvent, Event)
    public:
    
        static void init_meta();

    protected:
        ColorEvent(const Header&);
        ColorEvent(const ColorEvent&, const Header&);
        ~ColorEvent();
    
    private:
        ColorEvent(const ColorEvent&) = delete;
        ColorEvent(ColorEvent&&) = delete;
        ColorEvent& operator=(const ColorEvent&) = delete;
        ColorEvent& operator=(ColorEvent&&) = delete;
    };
}
