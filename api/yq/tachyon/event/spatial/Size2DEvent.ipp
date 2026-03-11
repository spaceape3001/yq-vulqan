////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/Size2DEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size²DEvent)

namespace yq::tachyon {
    Size²DEvent::Size²DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size²DEvent::Size²DEvent(const Header&h, const Size2D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    Size²DEvent::Size²DEvent(const Size²DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size²DEvent::~Size²DEvent()
    {
    }

    PostCPtr    Size²DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size²DEvent(*this, h);
    }
   
    void Size²DEvent::init_meta()
    {
        auto w = writer<Size²DEvent>();
        w.description("Size Event in 2D");
        w.property("x", &Size²DEvent::x).tag(kTag_Log);
        w.property("y", &Size²DEvent::y).tag(kTag_Log);
        w.property("size", &Size²DEvent::m_size).tag(kTag_Save);
    }
}
