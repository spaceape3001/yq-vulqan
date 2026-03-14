////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeZDEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeᶻDEvent)

namespace yq::tachyon {
    RangeᶻDEvent::RangeᶻDEvent(const Header& h) : 
        RangeEvent(h)
    {
    }

    RangeᶻDEvent::RangeᶻDEvent(const Header& h, const RangeD& v) : 
        RangeEvent(h), m_zRange(v)
    {
    }

    RangeᶻDEvent::RangeᶻDEvent(const RangeᶻDEvent& cp, const Header& h) : 
        RangeEvent(cp, h), m_zRange(cp.m_zRange)
    {
    }
    
    RangeᶻDEvent::~RangeᶻDEvent()
    {
    }

    PostCPtr    RangeᶻDEvent::clone(rebind_k, const Header&h) const 
    {
        return new RangeᶻDEvent(*this, h);
    }
    
    void RangeᶻDEvent::init_meta()
    {
        auto w = writer<RangeᶻDEvent>();
        w.description(" Range Event in Z");
        w.property("z_range", &RangeᶻDEvent::m_zRange).tag(kTag_Log).tag(kTag_Save);
    }
}
