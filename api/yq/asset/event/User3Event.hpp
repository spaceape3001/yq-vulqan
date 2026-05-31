////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class User³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(User³Event, SpatialEvent)
    public:
    
        static void init_meta();

    protected:
        User³Event(const Header&);
        User³Event(const User³Event&, const Header&);
        ~User³Event();
        
    private:
        User³Event(const User³Event&) = delete;
        User³Event(User³Event&&) = delete;
        User³Event& operator=(const User³Event&) = delete;
        User³Event& operator=(User³Event&&) = delete;
    };
}
