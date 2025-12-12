////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count2Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count²Event)

namespace yq::tachyon {
    Count²Event::Count²Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Count²Event::Count²Event(const Header&h, const Vector2U& v) : 
        SpatialEvent(h), m_count(v)
    {
    }

    Count²Event::Count²Event(const Count²Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_count(cp.m_count)
    {
    }

    Count²Event::~Count²Event()
    {
    }

    PostCPtr    Count²Event::clone(rebind_k, const Header& h) const 
    {
        return new Count²Event(*this, h);
    }
   
    void Count²Event::init_meta()
    {
        auto w = writer<Count²Event>();
        w.description("Count Countd Event in 2D");
        w.property("x", &Count²Event::x).tag(kTag_Log);
        w.property("y", &Count²Event::y).tag(kTag_Log);
        w.property("count", &Count²Event::m_count).tag(kTag_Save);
    }
}
