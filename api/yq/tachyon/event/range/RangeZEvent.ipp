////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeZEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeᶻEvent)

namespace yq::tachyon {
    RangeᶻEvent::RangeᶻEvent(const Header& h) : 
        RangeEvent(h)
    {
    }

    RangeᶻEvent::RangeᶻEvent(const Header& h, const RangeD& v) : 
        RangeEvent(h), m_zRange(v)
    {
    }

    RangeᶻEvent::RangeᶻEvent(const RangeᶻEvent& cp, const Header& h) : 
        RangeEvent(cp, h), m_zRange(cp.m_zRange)
    {
    }
    
    RangeᶻEvent::~RangeᶻEvent()
    {
    }

    PostCPtr    RangeᶻEvent::clone(rebind_k, const Header&h) const 
    {
        return new RangeᶻEvent(*this, h);
    }
    
    void RangeᶻEvent::init_meta()
    {
        auto w = writer<RangeᶻEvent>();
        w.description(" Range Event in Z");
        w.property("z_range", &RangeᶻEvent::m_zRange).tag(kTag_Log).tag(kTag_Save);
    }
}
