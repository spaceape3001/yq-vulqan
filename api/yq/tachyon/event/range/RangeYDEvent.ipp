////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeYDEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeʸDEvent)

namespace yq::tachyon {
    RangeʸDEvent::RangeʸDEvent(const Header& h) : 
        RangeEvent(h)
    {
    }

    RangeʸDEvent::RangeʸDEvent(const Header& h, const RangeD& v) : 
        RangeEvent(h), m_yRange(v)
    {
    }

    RangeʸDEvent::RangeʸDEvent(const RangeʸDEvent& cp, const Header& h) : 
        RangeEvent(cp, h), m_yRange(cp.m_yRange)
    {
    }
    
    RangeʸDEvent::~RangeʸDEvent()
    {
    }

    PostCPtr    RangeʸDEvent::clone(rebind_k, const Header&h) const 
    {
        return new RangeʸDEvent(*this, h);
    }
    
    void RangeʸDEvent::init_meta()
    {
        auto w = writer<RangeʸDEvent>();
        w.description(" Range Event in Y");
        w.property("y_range", &RangeʸDEvent::m_yRange).tag(kTag_Log).tag(kTag_Save);
    }
}
