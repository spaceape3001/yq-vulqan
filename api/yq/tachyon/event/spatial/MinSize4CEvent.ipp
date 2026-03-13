////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize4CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize⁴CEvent)

namespace yq::tachyon {
    MinSize⁴CEvent::MinSize⁴CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize⁴CEvent::MinSize⁴CEvent(const Header&h, const Size4CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize⁴CEvent::MinSize⁴CEvent(const MinSize⁴CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize⁴CEvent::~MinSize⁴CEvent()
    {
    }

    PostCPtr    MinSize⁴CEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize⁴CEvent(*this, h);
    }
   
    void MinSize⁴CEvent::init_meta()
    {
        auto w = writer<MinSize⁴CEvent>();
        w.description("Min Size Event in 4D");
        w.property("x", &MinSize⁴CEvent::x).tag(kTag_Log);
        w.property("y", &MinSize⁴CEvent::y).tag(kTag_Log);
        w.property("z", &MinSize⁴CEvent::z).tag(kTag_Log);
        w.property("w", &MinSize⁴CEvent::w).tag(kTag_Log);
        w.property("size", &MinSize⁴CEvent::m_size).tag(kTag_Save);
    }
}
