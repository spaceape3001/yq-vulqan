////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QMassLL
//
////////////////////////////////////////////////////////////////////////////////

#include "MassKGEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MassKGEvent)

namespace yq::tachyon {
    MassKGEvent::MassKGEvent(const Header& h, unit::Kilogram kg) : MassEvent(h), m_mass(kg)
    {
    }
    
    MassKGEvent::MassKGEvent(const MassKGEvent&cp, const Header&h) : MassEvent(cp, h), m_mass(cp.m_mass)
    {
    }

    MassKGEvent::~MassKGEvent()
    {
    }
    
    PostCPtr    MassKGEvent::clone(rebind_k, const Header&h) const 
    {
        return new MassKGEvent(*this, h);
    }

    void MassKGEvent::init_meta()
    {
        auto w = writer<MassKGEvent>();
        w.description("Mass (KG) Event");
        w.property("mass", &MassKGEvent::m_mass).tag(kTag_Log).tag(kTag_Save);
    }
}
