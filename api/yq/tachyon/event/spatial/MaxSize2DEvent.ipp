////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/MaxSize2DEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize²DEvent)

namespace yq::tachyon {
    MaxSize²DEvent::MaxSize²DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize²DEvent::MaxSize²DEvent(const Header&h, const Size2D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MaxSize²DEvent::MaxSize²DEvent(const MaxSize²DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize²DEvent::~MaxSize²DEvent()
    {
    }

    PostCPtr    MaxSize²DEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize²DEvent(*this, h);
    }
   
    void MaxSize²DEvent::init_meta()
    {
        auto w = writer<MaxSize²DEvent>();
        w.description("Max Size Event in 2D");
        w.property("x", &MaxSize²DEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize²DEvent::y).tag(kTag_Log);
        w.property("size", &MaxSize²DEvent::m_size).tag(kTag_Save);
    }
}
