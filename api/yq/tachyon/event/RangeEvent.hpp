////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class RangeEvent : public Event {
        YQ_OBJECT_DECLARE(RangeEvent, Event)
    public:
    
        static void init_meta();

    protected:
        RangeEvent(const Header&);
        RangeEvent(const RangeEvent&, const Header&);
        ~RangeEvent();
        
    private:
        RangeEvent(const RangeEvent&) = delete;
        RangeEvent(RangeEvent&&) = delete;
        RangeEvent& operator=(const RangeEvent&) = delete;
        RangeEvent& operator=(RangeEvent&&) = delete;
    };
}
