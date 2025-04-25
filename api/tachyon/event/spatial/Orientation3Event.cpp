////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/Orientation3Event.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>
#include <yq/vector/Quaternion3.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Orientation³Event)

namespace yq::tachyon {
    Orientation³Event::Orientation³Event(const Header&h, const Quaternion3D& v) : 
        SpatialEvent(h), m_orientation(v)
    {
    }
    
    Orientation³Event::Orientation³Event(const Header&h) : 
        SpatialEvent(h) 
    {
    }

    Orientation³Event::Orientation³Event(const Orientation³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_orientation(cp.m_orientation)
    {
    }

    Orientation³Event::~Orientation³Event()
    {
    }

    PostCPtr    Orientation³Event::clone(rebind_k, const Header& h) const 
    {
        return new Orientation³Event(*this, h);
    }
   
    Radian  Orientation³Event::heading() const
    {
        return m_orientation.angle(ZYX, Z);
    }
    
    Radian  Orientation³Event::pitch() const
    {
        return m_orientation.angle(ZYX, Y);
    }
    
    Radian  Orientation³Event::roll() const
    {
        return m_orientation.angle(ZYX, X);
    }

    void Orientation³Event::init_info()
    {
        auto w = writer<Orientation³Event>();
        w.description("Position Orientation Event in 3D");
        w.property("w", &Orientation³Event::w).tag(kTag_Log);
        w.property("x", &Orientation³Event::x).tag(kTag_Log);
        w.property("y", &Orientation³Event::y).tag(kTag_Log);
        w.property("z", &Orientation³Event::z).tag(kTag_Log);
        w.property("orientation", &Orientation³Event::m_orientation).tag(kTag_Save);
    }
}
