////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize4CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize⁴CMEvent)

namespace yq::tachyon {
    MinSize⁴CMEvent::MinSize⁴CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize⁴CMEvent::MinSize⁴CMEvent(const Header&h, const Size4CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize⁴CMEvent::MinSize⁴CMEvent(const MinSize⁴CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize⁴CMEvent::~MinSize⁴CMEvent()
    {
    }

    PostCPtr    MinSize⁴CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize⁴CMEvent(*this, h);
    }
   
    void MinSize⁴CMEvent::init_meta()
    {
        auto w = writer<MinSize⁴CMEvent>();
        w.description("Min Size Event in 4D");
        w.property("x", &MinSize⁴CMEvent::x).tag(kTag_Log);
        w.property("y", &MinSize⁴CMEvent::y).tag(kTag_Log);
        w.property("z", &MinSize⁴CMEvent::z).tag(kTag_Log);
        w.property("w", &MinSize⁴CMEvent::w).tag(kTag_Log);
        w.property("size", &MinSize⁴CMEvent::m_size).tag(kTag_Save);
    }
}
