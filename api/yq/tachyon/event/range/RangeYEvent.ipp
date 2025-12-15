////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeYEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeʸEvent)

namespace yq::tachyon {
    RangeʸEvent::RangeʸEvent(const Header& h) : 
        RangeEvent(h)
    {
    }

    RangeʸEvent::RangeʸEvent(const Header& h, const RangeD& v) : 
        RangeEvent(h), m_yRange(v)
    {
    }

    RangeʸEvent::RangeʸEvent(const RangeʸEvent& cp, const Header& h) : 
        RangeEvent(cp, h), m_yRange(cp.m_yRange)
    {
    }
    
    RangeʸEvent::~RangeʸEvent()
    {
    }

    PostCPtr    RangeʸEvent::clone(rebind_k, const Header&h) const 
    {
        return new RangeʸEvent(*this, h);
    }
    
    void RangeʸEvent::init_meta()
    {
        auto w = writer<RangeʸEvent>();
        w.description(" Range Event in Y");
        w.property("y_range", &RangeʸEvent::m_yRange).tag(kTag_Log).tag(kTag_Save);
    }
}
