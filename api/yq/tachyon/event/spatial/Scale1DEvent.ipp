////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/Scale1DEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale¹DEvent)

namespace yq::tachyon {
    Scale¹DEvent::Scale¹DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Scale¹DEvent::Scale¹DEvent(const Header&h, const Vector1D& v) : 
        SpatialEvent(h), m_scale(v)
    {
    }

    Scale¹DEvent::Scale¹DEvent(const Scale¹DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_scale(cp.m_scale)
    {
    }

    Scale¹DEvent::~Scale¹DEvent()
    {
    }

    PostCPtr    Scale¹DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Scale¹DEvent(*this, h);
    }
   
    void Scale¹DEvent::init_meta()
    {
        auto w = writer<Scale¹DEvent>();
        w.description("Scaled Event in 1D");
        w.property("x", &Scale¹DEvent::x).tag(kTag_Log);
        w.property("scale", &Scale¹DEvent::m_scale).tag(kTag_Save);
    }
}
