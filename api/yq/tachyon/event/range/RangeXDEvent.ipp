////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeXDEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeˣDEvent)

namespace yq::tachyon {
    RangeˣDEvent::RangeˣDEvent(const Header& h) : 
        RangeEvent(h)
    {
    }

    RangeˣDEvent::RangeˣDEvent(const Header& h, const RangeD& v) : 
        RangeEvent(h), m_xRange(v)
    {
    }

    RangeˣDEvent::RangeˣDEvent(const RangeˣDEvent& cp, const Header& h) : 
        RangeEvent(cp, h), m_xRange(cp.m_xRange)
    {
    }
    
    RangeˣDEvent::~RangeˣDEvent()
    {
    }

    PostCPtr    RangeˣDEvent::clone(rebind_k, const Header&h) const 
    {
        return new RangeˣDEvent(*this, h);
    }
    
    void RangeˣDEvent::init_meta()
    {
        auto w = writer<RangeˣDEvent>();
        w.description(" Range Event in X");
        w.property("x_range", &RangeˣDEvent::m_xRange).tag(kTag_Log).tag(kTag_Save);
    }
}
