////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QVulqanLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class VulqanEvent : public Event {
        YQ_OBJECT_DECLARE(VulqanEvent, Event)
    public:
    
        static void init_meta();

    protected:
        VulqanEvent(const Header&);
        VulqanEvent(const VulqanEvent&, const Header&);
        ~VulqanEvent();
    
    private:
        VulqanEvent(const VulqanEvent&) = delete;
        VulqanEvent(VulqanEvent&&) = delete;
        VulqanEvent& operator=(const VulqanEvent&) = delete;
        VulqanEvent& operator=(VulqanEvent&&) = delete;
    };
}
