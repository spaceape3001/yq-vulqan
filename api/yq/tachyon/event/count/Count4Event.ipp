////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count4Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count⁴Event)

namespace yq::tachyon {
    Count⁴Event::Count⁴Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Count⁴Event::Count⁴Event(const Header&h, const Vector4U& v) : 
        SpatialEvent(h), m_count(v)
    {
    }

    Count⁴Event::Count⁴Event(const Count⁴Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_count(cp.m_count)
    {
    }

    Count⁴Event::~Count⁴Event()
    {
    }

    PostCPtr    Count⁴Event::clone(rebind_k, const Header& h) const 
    {
        return new Count⁴Event(*this, h);
    }
   
    void Count⁴Event::init_meta()
    {
        auto w = writer<Count⁴Event>();
        w.description("Count Countd Event in 4D");
        w.property("x", &Count⁴Event::x).tag(kTag_Log);
        w.property("y", &Count⁴Event::y).tag(kTag_Log);
        w.property("z", &Count⁴Event::z).tag(kTag_Log);
        w.property("w", &Count⁴Event::w).tag(kTag_Log);
        w.property("count", &Count⁴Event::m_count).tag(kTag_Save);
    }
}
