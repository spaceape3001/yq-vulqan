////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeWEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeʷEvent)

namespace yq::tachyon {
    RangeʷEvent::RangeʷEvent(const Header& h) : 
        RangeEvent(h)
    {
    }

    RangeʷEvent::RangeʷEvent(const Header& h, const RangeD& v) : 
        RangeEvent(h), m_wRange(v)
    {
    }

    RangeʷEvent::RangeʷEvent(const RangeʷEvent& cp, const Header& h) : 
        RangeEvent(cp, h), m_wRange(cp.m_wRange)
    {
    }
    
    RangeʷEvent::~RangeʷEvent()
    {
    }

    PostCPtr    RangeʷEvent::clone(rebind_k, const Header&h) const 
    {
        return new RangeʷEvent(*this, h);
    }
    
    void RangeʷEvent::init_meta()
    {
        auto w = writer<RangeʷEvent>();
        w.description(" Range Event in X");
        w.property("w_range", &RangeʷEvent::m_wRange).tag(kTag_Log).tag(kTag_Save);
    }
}
