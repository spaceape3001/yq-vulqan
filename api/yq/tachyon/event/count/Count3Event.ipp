////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count3Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count³Event)

namespace yq::tachyon {
    Count³Event::Count³Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Count³Event::Count³Event(const Header&h, const Vector3U& v) : 
        SpatialEvent(h), m_count(v)
    {
    }

    Count³Event::Count³Event(const Count³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_count(cp.m_count)
    {
    }

    Count³Event::~Count³Event()
    {
    }

    PostCPtr    Count³Event::clone(rebind_k, const Header& h) const 
    {
        return new Count³Event(*this, h);
    }
   
    void Count³Event::init_meta()
    {
        auto w = writer<Count³Event>();
        w.description("Count Countd Event in 3D");
        w.property("x", &Count³Event::x).tag(kTag_Log);
        w.property("y", &Count³Event::y).tag(kTag_Log);
        w.property("z", &Count³Event::z).tag(kTag_Log);
        w.property("count", &Count³Event::m_count).tag(kTag_Save);
    }
}
