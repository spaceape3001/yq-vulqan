////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize4CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize⁴CMEvent)

namespace yq::tachyon {
    MaxSize⁴CMEvent::MaxSize⁴CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize⁴CMEvent::MaxSize⁴CMEvent(const Header&h, const Size4CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize⁴CMEvent::MaxSize⁴CMEvent(const MaxSize⁴CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize⁴CMEvent::~MaxSize⁴CMEvent()
    {
    }

    PostCPtr    MaxSize⁴CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize⁴CMEvent(*this, h);
    }
   
    void MaxSize⁴CMEvent::init_meta()
    {
        auto w = writer<MaxSize⁴CMEvent>();
        w.description("Max Size Event in 4D");
        w.property("x", &MaxSize⁴CMEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize⁴CMEvent::y).tag(kTag_Log);
        w.property("z", &MaxSize⁴CMEvent::z).tag(kTag_Log);
        w.property("w", &MaxSize⁴CMEvent::w).tag(kTag_Log);
        w.property("size", &MaxSize⁴CMEvent::m_size).tag(kTag_Save);
    }
}
