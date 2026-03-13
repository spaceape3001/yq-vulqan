////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scale4DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale⁴DEvent)

namespace yq::tachyon {
    Scale⁴DEvent::Scale⁴DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Scale⁴DEvent::Scale⁴DEvent(const Header&h, const Vector4D& v) : 
        SpatialEvent(h), m_scale(v)
    {
    }

    Scale⁴DEvent::Scale⁴DEvent(const Scale⁴DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_scale(cp.m_scale)
    {
    }

    Scale⁴DEvent::~Scale⁴DEvent()
    {
    }

    PostCPtr    Scale⁴DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Scale⁴DEvent(*this, h);
    }
   
    void Scale⁴DEvent::init_meta()
    {
        auto w = writer<Scale⁴DEvent>();
        w.description("Scaled Event in 3D");
        w.property("w", &Scale⁴DEvent::w).tag(kTag_Log);
        w.property("x", &Scale⁴DEvent::x).tag(kTag_Log);
        w.property("y", &Scale⁴DEvent::y).tag(kTag_Log);
        w.property("z", &Scale⁴DEvent::z).tag(kTag_Log);
        w.property("scale", &Scale⁴DEvent::m_scale).tag(kTag_Save);
    }
}
