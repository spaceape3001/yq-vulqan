////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize4CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize⁴CEvent)

namespace yq::tachyon {
    MaxSize⁴CEvent::MaxSize⁴CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize⁴CEvent::MaxSize⁴CEvent(const Header&h, const Size4CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize⁴CEvent::MaxSize⁴CEvent(const MaxSize⁴CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize⁴CEvent::~MaxSize⁴CEvent()
    {
    }

    PostCPtr    MaxSize⁴CEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize⁴CEvent(*this, h);
    }
   
    void MaxSize⁴CEvent::init_meta()
    {
        auto w = writer<MaxSize⁴CEvent>();
        w.description("Max Size Event in 4D");
        w.property("x", &MaxSize⁴CEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize⁴CEvent::y).tag(kTag_Log);
        w.property("z", &MaxSize⁴CEvent::z).tag(kTag_Log);
        w.property("w", &MaxSize⁴CEvent::w).tag(kTag_Log);
        w.property("size", &MaxSize⁴CEvent::m_size).tag(kTag_Save);
    }
}
