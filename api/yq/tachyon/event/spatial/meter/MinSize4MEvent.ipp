////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize4MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize⁴MEvent)

namespace yq::tachyon {
    MinSize⁴MEvent::MinSize⁴MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize⁴MEvent::MinSize⁴MEvent(const Header&h, const Size4M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize⁴MEvent::MinSize⁴MEvent(const MinSize⁴MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize⁴MEvent::~MinSize⁴MEvent()
    {
    }

    PostCPtr    MinSize⁴MEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize⁴MEvent(*this, h);
    }
   
    void MinSize⁴MEvent::init_meta()
    {
        auto w = writer<MinSize⁴MEvent>();
        w.description("Min Size Event in 4D");
        w.property("x", &MinSize⁴MEvent::x).tag(kTag_Log);
        w.property("y", &MinSize⁴MEvent::y).tag(kTag_Log);
        w.property("z", &MinSize⁴MEvent::z).tag(kTag_Log);
        w.property("w", &MinSize⁴MEvent::w).tag(kTag_Log);
        w.property("size", &MinSize⁴MEvent::m_size).tag(kTag_Save);
    }
}
