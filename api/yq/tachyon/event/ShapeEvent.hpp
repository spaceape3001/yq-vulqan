////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class ShapeEvent : public Event {
        YQ_OBJECT_DECLARE(ShapeEvent, Event)
    public:
    
        static void init_meta();

    protected:
        ShapeEvent(const Header&);
        ShapeEvent(const ShapeEvent&, const Header&);
        ~ShapeEvent();
        
    private:
        ShapeEvent(const ShapeEvent&) = delete;
        ShapeEvent(ShapeEvent&&) = delete;
        ShapeEvent& operator=(const ShapeEvent&) = delete;
        ShapeEvent& operator=(ShapeEvent&&) = delete;
    };
}
