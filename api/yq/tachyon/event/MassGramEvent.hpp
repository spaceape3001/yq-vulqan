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
    class MassGramEvent : public MassEvent {
        YQ_OBJECT_DECLARE(MassGramEvent, MassEvent)
    public:
    
        static void init_meta();

        MassGramEvent(const Header&, unit::Gram);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        unit::Gram      mass() const { return m_mass; }

    protected:
        MassGramEvent(const MassGramEvent&, const Header&);
        ~MassGramEvent();
    
    private:
    
        unit::Gram      m_mass;
    
        MassGramEvent(const MassGramEvent&) = delete;
        MassGramEvent(MassGramEvent&&) = delete;
        MassGramEvent& operator=(const MassGramEvent&) = delete;
        MassGramEvent& operator=(MassGramEvent&&) = delete;
    };
}
