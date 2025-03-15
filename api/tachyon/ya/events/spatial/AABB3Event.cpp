////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/AABB3Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AABB³Event)

namespace yq::tachyon {
    AABB³Event::AABB³Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    AABB³Event::AABB³Event(const Header&h, const AxBox3D& v) : 
        SpatialEvent(h), m_bounds(v)
    {
    }

    AABB³Event::AABB³Event(const AABB³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_bounds(cp.m_bounds)
    {
    }

    AABB³Event::~AABB³Event()
    {
    }

    PostCPtr    AABB³Event::clone(rebind_k, const Header& h) const 
    {
        return new AABB³Event(*this, h);
    }
   
    void AABB³Event::init_info()
    {
        auto w = writer<AABB³Event>();
        w.description("AABB AABBd Event in 3D");
        w.property("lx", &AABB³Event::lx).tag(kTag_Log);
        w.property("ly", &AABB³Event::ly).tag(kTag_Log);
        w.property("lz", &AABB³Event::lz).tag(kTag_Log);
        w.property("hx", &AABB³Event::hx).tag(kTag_Log);
        w.property("hy", &AABB³Event::hy).tag(kTag_Log);
        w.property("hz", &AABB³Event::hz).tag(kTag_Log);
        w.property("bounds", &AABB³Event::m_bounds).tag(kTag_Save);
    }
}
