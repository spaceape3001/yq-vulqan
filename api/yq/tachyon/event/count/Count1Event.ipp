////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Count1Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Count¹Event)

namespace yq::tachyon {
    Count¹Event::Count¹Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Count¹Event::Count¹Event(const Header&h, const Vector1U& v) : 
        SpatialEvent(h), m_count(v)
    {
    }
    
    Count¹Event::Count¹Event(const Count¹Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_count(cp.m_count)
    {
    }

    Count¹Event::~Count¹Event()
    {
    }

    PostCPtr    Count¹Event::clone(rebind_k, const Header& h) const 
    {
        return new Count¹Event(*this, h);
    }
   
    void Count¹Event::init_meta()
    {
        auto w = writer<Count¹Event>();
        w.description("Count Countd Event in 1D");
        w.property("x", &Count¹Event::x).tag(kTag_Log);
        w.property("count", &Count¹Event::m_count).tag(kTag_Save);
    }
}
