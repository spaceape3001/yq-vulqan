////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeXEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeˣEvent)

namespace yq::tachyon {
    RangeˣEvent::RangeˣEvent(const Header& h) : 
        RangeEvent(h)
    {
    }

    RangeˣEvent::RangeˣEvent(const Header& h, const RangeD& v) : 
        RangeEvent(h), m_xRange(v)
    {
    }

    RangeˣEvent::RangeˣEvent(const RangeˣEvent& cp, const Header& h) : 
        RangeEvent(cp, h), m_xRange(cp.m_xRange)
    {
    }
    
    RangeˣEvent::~RangeˣEvent()
    {
    }

    PostCPtr    RangeˣEvent::clone(rebind_k, const Header&h) const 
    {
        return new RangeˣEvent(*this, h);
    }
    
    void RangeˣEvent::init_meta()
    {
        auto w = writer<RangeˣEvent>();
        w.description(" Range Event in X");
        w.property("x_range", &RangeˣEvent::m_xRange).tag(kTag_Log).tag(kTag_Save);
    }
}
