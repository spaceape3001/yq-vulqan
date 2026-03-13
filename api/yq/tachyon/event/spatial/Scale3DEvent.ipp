////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scale3DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale³DEvent)

namespace yq::tachyon {
    Scale³DEvent::Scale³DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Scale³DEvent::Scale³DEvent(const Header&h, const Vector3D& v) : 
        SpatialEvent(h), m_scale(v)
    {
    }

    Scale³DEvent::Scale³DEvent(const Scale³DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_scale(cp.m_scale)
    {
    }

    Scale³DEvent::~Scale³DEvent()
    {
    }

    PostCPtr    Scale³DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Scale³DEvent(*this, h);
    }
   
    void Scale³DEvent::init_meta()
    {
        auto w = writer<Scale³DEvent>();
        w.description("Scaled Event in 3D");
        w.property("x", &Scale³DEvent::x).tag(kTag_Log);
        w.property("y", &Scale³DEvent::y).tag(kTag_Log);
        w.property("z", &Scale³DEvent::z).tag(kTag_Log);
        w.property("scale", &Scale³DEvent::m_scale).tag(kTag_Save);
    }
}
