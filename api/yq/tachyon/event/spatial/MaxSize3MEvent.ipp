////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize3DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize³MEvent)

namespace yq::tachyon {
    MaxSize³MEvent::MaxSize³MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize³MEvent::MaxSize³MEvent(const Header&h, const Size3M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize³MEvent::MaxSize³MEvent(const MaxSize³MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize³MEvent::~MaxSize³MEvent()
    {
    }

    PostCPtr    MaxSize³MEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize³MEvent(*this, h);
    }
   
    void MaxSize³MEvent::init_meta()
    {
        auto w = writer<MaxSize³MEvent>();
        w.description("Max Size Event in 3D");
        w.property("x", &MaxSize³MEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize³MEvent::y).tag(kTag_Log);
        w.property("z", &MaxSize³MEvent::z).tag(kTag_Log);
        w.property("size", &MaxSize³MEvent::m_size).tag(kTag_Save);
    }
}
