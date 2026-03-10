////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QMassLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Event that notifies that it's mass related
    class MassEvent : public Event {
        YQ_OBJECT_DECLARE(MassEvent, Event)
    public:
    
        static void init_meta();

    protected:
        MassEvent(const Header&);
        MassEvent(const MassEvent&, const Header&);
        ~MassEvent();
    
    private:
    
        MassEvent(const MassEvent&) = delete;
        MassEvent(MassEvent&&) = delete;
        MassEvent& operator=(const MassEvent&) = delete;
        MassEvent& operator=(MassEvent&&) = delete;
    };
}
