////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count2UEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count²UEvent)

namespace yq::tachyon {
    Count²UEvent::Count²UEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Count²UEvent::Count²UEvent(const Header&h, const Vector2U& v) : 
        SpatialEvent(h), m_count(v)
    {
    }

    Count²UEvent::Count²UEvent(const Count²UEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_count(cp.m_count)
    {
    }

    Count²UEvent::~Count²UEvent()
    {
    }

    PostCPtr    Count²UEvent::clone(rebind_k, const Header& h) const 
    {
        return new Count²UEvent(*this, h);
    }
   
    void Count²UEvent::init_meta()
    {
        auto w = writer<Count²UEvent>();
        w.description("Count Countd Event in 2D");
        w.property("x", &Count²UEvent::x).tag(kTag_Log);
        w.property("y", &Count²UEvent::y).tag(kTag_Log);
        w.property("count", &Count²UEvent::m_count).tag(kTag_Save);
    }
}
