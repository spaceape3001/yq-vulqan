////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QMasterLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class MasterEvent : public Event {
        YQ_OBJECT_DECLARE(MasterEvent, Event)
    public:
    
        static void init_meta();

    protected:
        MasterEvent(const Header&);
        MasterEvent(const MasterEvent&, const Header&);
        ~MasterEvent();
    
    private:
        MasterEvent(const MasterEvent&) = delete;
        MasterEvent(MasterEvent&&) = delete;
        MasterEvent& operator=(const MasterEvent&) = delete;
        MasterEvent& operator=(MasterEvent&&) = delete;
    };
}
