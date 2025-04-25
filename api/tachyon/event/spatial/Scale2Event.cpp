////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/Scale2Event.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale²Event)

namespace yq::tachyon {
    Scale²Event::Scale²Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Scale²Event::Scale²Event(const Header&h, const Vector2D& v) : 
        SpatialEvent(h), m_scale(v)
    {
    }
    
    Scale²Event::Scale²Event(const Scale²Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_scale(cp.m_scale)
    {
    }

    Scale²Event::~Scale²Event()
    {
    }

    PostCPtr    Scale²Event::clone(rebind_k, const Header& h) const 
    {
        return new Scale²Event(*this, h);
    }
   
    void Scale²Event::init_info()
    {
        auto w = writer<Scale²Event>();
        w.description("Scaled Event in 2D");
        w.property("x", &Scale²Event::x).tag(kTag_Log);
        w.property("y", &Scale²Event::y).tag(kTag_Log);
        w.property("scale", &Scale²Event::m_scale).tag(kTag_Save);
    }
}
