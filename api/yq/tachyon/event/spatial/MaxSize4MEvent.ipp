////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize4DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize⁴MEvent)

namespace yq::tachyon {
    MaxSize⁴MEvent::MaxSize⁴MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize⁴MEvent::MaxSize⁴MEvent(const Header&h, const Size4M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize⁴MEvent::MaxSize⁴MEvent(const MaxSize⁴MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize⁴MEvent::~MaxSize⁴MEvent()
    {
    }

    PostCPtr    MaxSize⁴MEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize⁴MEvent(*this, h);
    }
   
    void MaxSize⁴MEvent::init_meta()
    {
        auto w = writer<MaxSize⁴MEvent>();
        w.description("Max Size Event in 4D");
        w.property("x", &MaxSize⁴MEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize⁴MEvent::y).tag(kTag_Log);
        w.property("z", &MaxSize⁴MEvent::z).tag(kTag_Log);
        w.property("w", &MaxSize⁴MEvent::w).tag(kTag_Log);
        w.property("size", &MaxSize⁴MEvent::m_size).tag(kTag_Save);
    }
}
