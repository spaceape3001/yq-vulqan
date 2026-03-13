////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize3MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize³MEvent)

namespace yq::tachyon {
    MinSize³MEvent::MinSize³MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize³MEvent::MinSize³MEvent(const Header&h, const Size3M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize³MEvent::MinSize³MEvent(const MinSize³MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize³MEvent::~MinSize³MEvent()
    {
    }

    PostCPtr    MinSize³MEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize³MEvent(*this, h);
    }
   
    void MinSize³MEvent::init_meta()
    {
        auto w = writer<MinSize³MEvent>();
        w.description("Min Size Event in 3D");
        w.property("x", &MinSize³MEvent::x).tag(kTag_Log);
        w.property("y", &MinSize³MEvent::y).tag(kTag_Log);
        w.property("z", &MinSize³MEvent::z).tag(kTag_Log);
        w.property("size", &MinSize³MEvent::m_size).tag(kTag_Save);
    }
}
