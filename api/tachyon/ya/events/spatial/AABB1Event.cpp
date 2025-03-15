////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/AABB1Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AABB¹Event)

namespace yq::tachyon {
    AABB¹Event::AABB¹Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    AABB¹Event::AABB¹Event(const Header&h, const AxBox1D& v) : 
        SpatialEvent(h), m_bounds(v)
    {
    }
    
    AABB¹Event::AABB¹Event(const AABB¹Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_bounds(cp.m_bounds)
    {
    }

    AABB¹Event::~AABB¹Event()
    {
    }

    PostCPtr    AABB¹Event::clone(rebind_k, const Header& h) const 
    {
        return new AABB¹Event(*this, h);
    }
   
    void AABB¹Event::init_info()
    {
        auto w = writer<AABB¹Event>();
        w.description("AABB AABBd Event in 1D");
        w.property("lx", &AABB¹Event::lx).tag(kTag_Log);
        w.property("hx", &AABB¹Event::hx).tag(kTag_Log);
        w.property("bounds", &AABB¹Event::m_bounds).tag(kTag_Save);
    }
}
