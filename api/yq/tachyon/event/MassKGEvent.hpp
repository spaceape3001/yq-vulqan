////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QMassLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/MassEvent.hpp>

namespace yq::tachyon {

    //! Event that notifies that it's mass related
    class MassKGEvent : public MassEvent {
        YQ_OBJECT_DECLARE(MassKGEvent, MassEvent)
    public:
    
        static void init_meta();

        MassKGEvent(const Header&, unit::Kilogram);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        unit::Kilogram      mass() const { return m_mass; }

    protected:
        MassKGEvent(const MassKGEvent&, const Header&);
        ~MassKGEvent();
    
    private:
    
        unit::Kilogram      m_mass;
    
        MassKGEvent(const MassKGEvent&) = delete;
        MassKGEvent(MassKGEvent&&) = delete;
        MassKGEvent& operator=(const MassKGEvent&) = delete;
        MassKGEvent& operator=(MassKGEvent&&) = delete;
    };
}
