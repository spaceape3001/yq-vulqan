////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize2DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize²DEvent)

namespace yq::tachyon {
    MinSize²DEvent::MinSize²DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize²DEvent::MinSize²DEvent(const Header&h, const Size2D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MinSize²DEvent::MinSize²DEvent(const MinSize²DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize²DEvent::~MinSize²DEvent()
    {
    }

    PostCPtr    MinSize²DEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize²DEvent(*this, h);
    }
   
    void MinSize²DEvent::init_meta()
    {
        auto w = writer<MinSize²DEvent>();
        w.description("Min Size Event in 2D");
        w.property("x", &MinSize²DEvent::x).tag(kTag_Log);
        w.property("y", &MinSize²DEvent::y).tag(kTag_Log);
        w.property("size", &MinSize²DEvent::m_size).tag(kTag_Save);
    }
}
