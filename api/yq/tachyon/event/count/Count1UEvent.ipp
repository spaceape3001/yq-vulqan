////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count1UEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count¹UEvent)

namespace yq::tachyon {
    Count¹UEvent::Count¹UEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Count¹UEvent::Count¹UEvent(const Header&h, const Vector1U& v) : 
        SpatialEvent(h), m_count(v)
    {
    }
    
    Count¹UEvent::Count¹UEvent(const Count¹UEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_count(cp.m_count)
    {
    }

    Count¹UEvent::~Count¹UEvent()
    {
    }

    PostCPtr    Count¹UEvent::clone(rebind_k, const Header& h) const 
    {
        return new Count¹UEvent(*this, h);
    }
   
    void Count¹UEvent::init_meta()
    {
        auto w = writer<Count¹UEvent>();
        w.description("Count Countd Event in 1D");
        w.property("x", &Count¹UEvent::x).tag(kTag_Log);
        w.property("count", &Count¹UEvent::m_count).tag(kTag_Save);
    }
}
