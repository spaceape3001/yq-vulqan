////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeWDEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeʷDEvent)

namespace yq::tachyon {
    RangeʷDEvent::RangeʷDEvent(const Header& h) : 
        RangeEvent(h)
    {
    }

    RangeʷDEvent::RangeʷDEvent(const Header& h, const RangeD& v) : 
        RangeEvent(h), m_wRange(v)
    {
    }

    RangeʷDEvent::RangeʷDEvent(const RangeʷDEvent& cp, const Header& h) : 
        RangeEvent(cp, h), m_wRange(cp.m_wRange)
    {
    }
    
    RangeʷDEvent::~RangeʷDEvent()
    {
    }

    PostCPtr    RangeʷDEvent::clone(rebind_k, const Header&h) const 
    {
        return new RangeʷDEvent(*this, h);
    }
    
    void RangeʷDEvent::init_meta()
    {
        auto w = writer<RangeʷDEvent>();
        w.description(" Range Event in X");
        w.property("w_range", &RangeʷDEvent::m_wRange).tag(kTag_Log).tag(kTag_Save);
    }
}
