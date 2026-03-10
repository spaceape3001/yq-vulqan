////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QMassLL
//
////////////////////////////////////////////////////////////////////////////////

#include "MassGramEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MassGramEvent)

namespace yq::tachyon {
    MassGramEvent::MassGramEvent(const Header& h, unit::Gram kg) : MassEvent(h), m_mass(kg)
    {
    }
    
    MassGramEvent::MassGramEvent(const MassGramEvent&cp, const Header&h) : MassEvent(cp, h), m_mass(cp.m_mass)
    {
    }

    MassGramEvent::~MassGramEvent()
    {
    }
    
    PostCPtr    MassGramEvent::clone(rebind_k, const Header&h) const 
    {
        return new MassGramEvent(*this, h);
    }

    void MassGramEvent::init_meta()
    {
        auto w = writer<MassGramEvent>();
        w.description("Mass (Gram) Event");
        w.property("mass", &MassGramEvent::m_mass).tag(kTag_Log).tag(kTag_Save);
    }
}
