////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize2MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize²MEvent)

namespace yq::tachyon {
    MaxSize²MEvent::MaxSize²MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize²MEvent::MaxSize²MEvent(const Header&h, const Size2M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MaxSize²MEvent::MaxSize²MEvent(const MaxSize²MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize²MEvent::~MaxSize²MEvent()
    {
    }

    PostCPtr    MaxSize²MEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize²MEvent(*this, h);
    }
   
    void MaxSize²MEvent::init_meta()
    {
        auto w = writer<MaxSize²MEvent>();
        w.description("Max Size Event in 2D");
        w.property("x", &MaxSize²MEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize²MEvent::y).tag(kTag_Log);
        w.property("size", &MaxSize²MEvent::m_size).tag(kTag_Save);
    }
}
