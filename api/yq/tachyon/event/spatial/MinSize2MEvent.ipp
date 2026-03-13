////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize2MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize²MEvent)

namespace yq::tachyon {
    MinSize²MEvent::MinSize²MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize²MEvent::MinSize²MEvent(const Header&h, const Size2M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MinSize²MEvent::MinSize²MEvent(const MinSize²MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize²MEvent::~MinSize²MEvent()
    {
    }

    PostCPtr    MinSize²MEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize²MEvent(*this, h);
    }
   
    void MinSize²MEvent::init_meta()
    {
        auto w = writer<MinSize²MEvent>();
        w.description("Min Size Event in 2D");
        w.property("x", &MinSize²MEvent::x).tag(kTag_Log);
        w.property("y", &MinSize²MEvent::y).tag(kTag_Log);
        w.property("size", &MinSize²MEvent::m_size).tag(kTag_Save);
    }
}
