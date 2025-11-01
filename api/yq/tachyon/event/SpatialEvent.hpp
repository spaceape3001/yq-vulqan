////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SpatialEvent : public Event {
        YQ_OBJECT_DECLARE(SpatialEvent, Event)
    public:
    
        static void init_meta();

    protected:
        SpatialEvent(const Header&);
        SpatialEvent(const SpatialEvent&, const Header&);
        ~SpatialEvent();
    
    private:
        SpatialEvent(const SpatialEvent&) = delete;
        SpatialEvent(SpatialEvent&&) = delete;
        SpatialEvent& operator=(const SpatialEvent&) = delete;
        SpatialEvent& operator=(SpatialEvent&&) = delete;
    };
}
