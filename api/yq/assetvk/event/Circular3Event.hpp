////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Circular³Event, SpatialEvent)
    public:
    
        static void init_meta();

    protected:
        Circular³Event(const Header&);
        Circular³Event(const Circular³Event&, const Header&);
        ~Circular³Event();
        
    private:
        Circular³Event(const Circular³Event&) = delete;
        Circular³Event(Circular³Event&&) = delete;
        Circular³Event& operator=(const Circular³Event&) = delete;
        Circular³Event& operator=(Circular³Event&&) = delete;
    };
}
