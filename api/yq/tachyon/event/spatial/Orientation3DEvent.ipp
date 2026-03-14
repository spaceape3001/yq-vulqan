////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Orientation3DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Orientation³DEvent)

namespace yq::tachyon {
    Orientation³DEvent::Orientation³DEvent(const Header&h, const Quaternion3D& v) : 
        SpatialEvent(h), m_orientation(v)
    {
    }
    
    Orientation³DEvent::Orientation³DEvent(const Header&h) : 
        SpatialEvent(h) 
    {
    }

    Orientation³DEvent::Orientation³DEvent(const Orientation³DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_orientation(cp.m_orientation)
    {
    }

    Orientation³DEvent::~Orientation³DEvent()
    {
    }

    PostCPtr    Orientation³DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Orientation³DEvent(*this, h);
    }
   
    Radian  Orientation³DEvent::heading() const
    {
        return m_orientation.angle(ZYX, Z);
    }
    
    Radian  Orientation³DEvent::pitch() const
    {
        return m_orientation.angle(ZYX, Y);
    }
    
    Radian  Orientation³DEvent::roll() const
    {
        return m_orientation.angle(ZYX, X);
    }

    void Orientation³DEvent::init_meta()
    {
        auto w = writer<Orientation³DEvent>();
        w.description("Position Orientation Event in 3D");
        w.property("w", &Orientation³DEvent::w).tag(kTag_Log);
        w.property("x", &Orientation³DEvent::x).tag(kTag_Log);
        w.property("y", &Orientation³DEvent::y).tag(kTag_Log);
        w.property("z", &Orientation³DEvent::z).tag(kTag_Log);
        w.property("orientation", &Orientation³DEvent::m_orientation).tag(kTag_Save);
    }
}
