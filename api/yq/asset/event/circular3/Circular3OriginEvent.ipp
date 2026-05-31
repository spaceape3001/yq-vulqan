////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3OriginEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³OriginEvent)

namespace yq::tachyon {
    Circular³OriginEvent::Circular³OriginEvent(const Header& h, const Vector3D& _origin) : Circular³Event(h), m_origin(_origin)
    {
    }
    
    Circular³OriginEvent::Circular³OriginEvent(const Circular³OriginEvent&cp, const Header&h) : 
        Circular³Event(cp, h), m_origin(cp.m_origin)
    {
    }

    Circular³OriginEvent::~Circular³OriginEvent()
    {
    }
    
    PostCPtr    Circular³OriginEvent::clone(rebind_k, const Header&h) const
    {
        return new Circular³OriginEvent(*this, h);
    }

    void Circular³OriginEvent::init_meta()
    {
        auto w = writer<Circular³OriginEvent>();
        w.description("Circular³ Origin Event");
        w.property("origin", &Circular³OriginEvent::m_origin);
    }
}
