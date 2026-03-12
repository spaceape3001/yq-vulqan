////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize4DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize⁴DEvent)

namespace yq::tachyon {
    MinSize⁴DEvent::MinSize⁴DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize⁴DEvent::MinSize⁴DEvent(const Header&h, const Size4D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize⁴DEvent::MinSize⁴DEvent(const MinSize⁴DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize⁴DEvent::~MinSize⁴DEvent()
    {
    }

    PostCPtr    MinSize⁴DEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize⁴DEvent(*this, h);
    }
   
    void MinSize⁴DEvent::init_meta()
    {
        auto w = writer<MinSize⁴DEvent>();
        w.description("Min Size Event in 4D");
        w.property("x", &MinSize⁴DEvent::x).tag(kTag_Log);
        w.property("y", &MinSize⁴DEvent::y).tag(kTag_Log);
        w.property("z", &MinSize⁴DEvent::z).tag(kTag_Log);
        w.property("w", &MinSize⁴DEvent::w).tag(kTag_Log);
        w.property("size", &MinSize⁴DEvent::m_size).tag(kTag_Save);
    }
}
