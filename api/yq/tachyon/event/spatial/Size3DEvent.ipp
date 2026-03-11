////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/Size3DEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size³DEvent)

namespace yq::tachyon {
    Size³DEvent::Size³DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size³DEvent::Size³DEvent(const Header&h, const Size3D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size³DEvent::Size³DEvent(const Size³DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size³DEvent::~Size³DEvent()
    {
    }

    PostCPtr    Size³DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size³DEvent(*this, h);
    }
   
    void Size³DEvent::init_meta()
    {
        auto w = writer<Size³DEvent>();
        w.description("Size Event in 3D");
        w.property("x", &Size³DEvent::x).tag(kTag_Log);
        w.property("y", &Size³DEvent::y).tag(kTag_Log);
        w.property("z", &Size³DEvent::z).tag(kTag_Log);
        w.property("size", &Size³DEvent::m_size).tag(kTag_Save);
    }
}
