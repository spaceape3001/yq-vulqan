////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/Scale2DEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale²DEvent)

namespace yq::tachyon {
    Scale²DEvent::Scale²DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Scale²DEvent::Scale²DEvent(const Header&h, const Vector2D& v) : 
        SpatialEvent(h), m_scale(v)
    {
    }
    
    Scale²DEvent::Scale²DEvent(const Scale²DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_scale(cp.m_scale)
    {
    }

    Scale²DEvent::~Scale²DEvent()
    {
    }

    PostCPtr    Scale²DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Scale²DEvent(*this, h);
    }
   
    void Scale²DEvent::init_meta()
    {
        auto w = writer<Scale²DEvent>();
        w.description("Scaled Event in 2D");
        w.property("x", &Scale²DEvent::x).tag(kTag_Log);
        w.property("y", &Scale²DEvent::y).tag(kTag_Log);
        w.property("scale", &Scale²DEvent::m_scale).tag(kTag_Save);
    }
}
