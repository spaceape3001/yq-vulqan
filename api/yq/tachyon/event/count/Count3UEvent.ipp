////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count3UEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count³UEvent)

namespace yq::tachyon {
    Count³UEvent::Count³UEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Count³UEvent::Count³UEvent(const Header&h, const Vector3U& v) : 
        SpatialEvent(h), m_count(v)
    {
    }

    Count³UEvent::Count³UEvent(const Count³UEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_count(cp.m_count)
    {
    }

    Count³UEvent::~Count³UEvent()
    {
    }

    PostCPtr    Count³UEvent::clone(rebind_k, const Header& h) const 
    {
        return new Count³UEvent(*this, h);
    }
   
    void Count³UEvent::init_meta()
    {
        auto w = writer<Count³UEvent>();
        w.description("Count Countd Event in 3D");
        w.property("x", &Count³UEvent::x).tag(kTag_Log);
        w.property("y", &Count³UEvent::y).tag(kTag_Log);
        w.property("z", &Count³UEvent::z).tag(kTag_Log);
        w.property("count", &Count³UEvent::m_count).tag(kTag_Save);
    }
}
