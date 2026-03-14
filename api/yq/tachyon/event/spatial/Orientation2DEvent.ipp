////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Orientation2DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>
#include <yq/vector/Spinor2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Orientation²DEvent)

namespace yq::tachyon {
    Orientation²DEvent::Orientation²DEvent(const Header&h, const Spinor2D& v) : 
        SpatialEvent(h), m_orientation(v)
    {
    }
    
    Orientation²DEvent::Orientation²DEvent(const Header&h) : 
        SpatialEvent(h) 
    {
    }

    Orientation²DEvent::Orientation²DEvent(const Orientation²DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_orientation(cp.m_orientation)
    {
    }

    Orientation²DEvent::~Orientation²DEvent()
    {
    }

    PostCPtr    Orientation²DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Orientation²DEvent(*this, h);
    }
   
    Radian  Orientation²DEvent::heading() const
    {
        return m_orientation.angle();
    }
    
    void Orientation²DEvent::init_meta()
    {
        auto w = writer<Orientation²DEvent>();
        w.description("Orientation Event in 2D");
        w.property("a", &Orientation²DEvent::a).tag(kTag_Log);
        w.property("xy", &Orientation²DEvent::xy).tag(kTag_Log);
        w.property("orientation", &Orientation²DEvent::m_orientation).tag(kTag_Save);
    }
}
