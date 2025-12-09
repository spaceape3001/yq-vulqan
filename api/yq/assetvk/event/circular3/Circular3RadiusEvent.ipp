////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3RadiusEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³RadiusEvent)

namespace yq::tachyon {
    Circular³RadiusEvent::Circular³RadiusEvent(const Header& h, double _radius) : Circular³Event(h), m_radius(_radius)
    {
    }
    
    Circular³RadiusEvent::Circular³RadiusEvent(const Circular³RadiusEvent&cp, const Header&h) : 
        Circular³Event(cp, h), m_radius(cp.m_radius)
    {
    }

    Circular³RadiusEvent::~Circular³RadiusEvent()
    {
    }
    
    PostCPtr    Circular³RadiusEvent::clone(rebind_k, const Header&h) const
    {
        return new Circular³RadiusEvent(*this, h);
    }

    void Circular³RadiusEvent::init_meta()
    {
        auto w = writer<Circular³RadiusEvent>();
        w.description("Circular³ Radius Event");
        w.property("radius", &Circular³RadiusEvent::m_radius);
    }
}
