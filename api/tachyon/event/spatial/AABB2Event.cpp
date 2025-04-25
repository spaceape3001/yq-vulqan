////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/AABB2Event.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AABB²Event)

namespace yq::tachyon {
    AABB²Event::AABB²Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    AABB²Event::AABB²Event(const Header&h, const AxBox2D& v) : 
        SpatialEvent(h), m_aabb(v)
    {
    }

    AABB²Event::AABB²Event(const AABB²Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_aabb(cp.m_aabb)
    {
    }

    AABB²Event::~AABB²Event()
    {
    }

    PostCPtr    AABB²Event::clone(rebind_k, const Header& h) const 
    {
        return new AABB²Event(*this, h);
    }
   
    void AABB²Event::init_info()
    {
        auto w = writer<AABB²Event>();
        w.description("AABB Changed Event in 2D");
        w.property("lx", &AABB²Event::lx).tag(kTag_Log);
        w.property("ly", &AABB²Event::ly).tag(kTag_Log);
        w.property("hx", &AABB²Event::hx).tag(kTag_Log);
        w.property("hy", &AABB²Event::hy).tag(kTag_Log);
        w.property("aabb", &AABB²Event::m_aabb).tag(kTag_Save);
    }
}
