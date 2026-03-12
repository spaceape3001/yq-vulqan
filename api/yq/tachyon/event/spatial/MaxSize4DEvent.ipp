////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize4DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize⁴DEvent)

namespace yq::tachyon {
    MaxSize⁴DEvent::MaxSize⁴DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize⁴DEvent::MaxSize⁴DEvent(const Header&h, const Size4D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize⁴DEvent::MaxSize⁴DEvent(const MaxSize⁴DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize⁴DEvent::~MaxSize⁴DEvent()
    {
    }

    PostCPtr    MaxSize⁴DEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize⁴DEvent(*this, h);
    }
   
    void MaxSize⁴DEvent::init_meta()
    {
        auto w = writer<MaxSize⁴DEvent>();
        w.description("Max Size Event in 4D");
        w.property("x", &MaxSize⁴DEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize⁴DEvent::y).tag(kTag_Log);
        w.property("z", &MaxSize⁴DEvent::z).tag(kTag_Log);
        w.property("w", &MaxSize⁴DEvent::w).tag(kTag_Log);
        w.property("size", &MaxSize⁴DEvent::m_size).tag(kTag_Save);
    }
}
