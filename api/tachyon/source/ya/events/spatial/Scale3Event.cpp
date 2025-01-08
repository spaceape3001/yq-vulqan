////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/Scale3Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale³Event)

namespace yq::tachyon {
    Scale³Event::Scale³Event(const Header&h, const Vector3D& v) : 
        SpatialEvent(h), m_scale(v)
    {
    }
    
    Scale³Event::Scale³Event(const Scale³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_scale(cp.m_scale)
    {
    }

    Scale³Event::~Scale³Event()
    {
    }

    PostCPtr    Scale³Event::clone(rebind_k, const Header& h) const 
    {
        return new Scale³Event(*this, h);
    }
   
    void Scale³Event::init_info()
    {
        auto w = writer<Scale³Event>();
        w.description("Scaled Event in 3D");
        w.property("x", &Scale³Event::x);
        w.property("y", &Scale³Event::y);
        w.property("z", &Scale³Event::z);
    }
}
