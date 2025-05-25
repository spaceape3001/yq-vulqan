////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/Orientation2Event.hpp>
#include <tachyon/api/EventInfoWriter.hpp>
#include <yq/vector/Spinor2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Orientation²Event)

namespace yq::tachyon {
    Orientation²Event::Orientation²Event(const Header&h, const Spinor2D& v) : 
        SpatialEvent(h), m_orientation(v)
    {
    }
    
    Orientation²Event::Orientation²Event(const Header&h) : 
        SpatialEvent(h) 
    {
    }

    Orientation²Event::Orientation²Event(const Orientation²Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_orientation(cp.m_orientation)
    {
    }

    Orientation²Event::~Orientation²Event()
    {
    }

    PostCPtr    Orientation²Event::clone(rebind_k, const Header& h) const 
    {
        return new Orientation²Event(*this, h);
    }
   
    Radian  Orientation²Event::heading() const
    {
        return m_orientation.angle();
    }
    
    void Orientation²Event::init_info()
    {
        auto w = writer<Orientation²Event>();
        w.description("Orientation Event in 2D");
        w.property("a", &Orientation²Event::a).tag(kTag_Log);
        w.property("xy", &Orientation²Event::xy).tag(kTag_Log);
        w.property("orientation", &Orientation²Event::m_orientation).tag(kTag_Save);
    }
}
