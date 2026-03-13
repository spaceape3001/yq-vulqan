////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count4UEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count⁴UEvent)

namespace yq::tachyon {
    Count⁴UEvent::Count⁴UEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Count⁴UEvent::Count⁴UEvent(const Header&h, const Vector4U& v) : 
        SpatialEvent(h), m_count(v)
    {
    }

    Count⁴UEvent::Count⁴UEvent(const Count⁴UEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_count(cp.m_count)
    {
    }

    Count⁴UEvent::~Count⁴UEvent()
    {
    }

    PostCPtr    Count⁴UEvent::clone(rebind_k, const Header& h) const 
    {
        return new Count⁴UEvent(*this, h);
    }
   
    void Count⁴UEvent::init_meta()
    {
        auto w = writer<Count⁴UEvent>();
        w.description("Count Countd Event in 4D");
        w.property("x", &Count⁴UEvent::x).tag(kTag_Log);
        w.property("y", &Count⁴UEvent::y).tag(kTag_Log);
        w.property("z", &Count⁴UEvent::z).tag(kTag_Log);
        w.property("w", &Count⁴UEvent::w).tag(kTag_Log);
        w.property("count", &Count⁴UEvent::m_count).tag(kTag_Save);
    }
}
