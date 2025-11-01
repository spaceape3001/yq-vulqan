////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/AABB4Event.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AABB⁴Event)

namespace yq::tachyon {
    AABB⁴Event::AABB⁴Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    AABB⁴Event::AABB⁴Event(const Header&h, const AxBox4D& v) : 
        SpatialEvent(h), m_aabb(v)
    {
    }

    AABB⁴Event::AABB⁴Event(const AABB⁴Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_aabb(cp.m_aabb)
    {
    }

    AABB⁴Event::~AABB⁴Event()
    {
    }

    PostCPtr    AABB⁴Event::clone(rebind_k, const Header& h) const 
    {
        return new AABB⁴Event(*this, h);
    }
   
    void AABB⁴Event::init_meta()
    {
        auto w = writer<AABB⁴Event>();
        w.description("AABB Changed Event in 4D");
        w.property("lx", &AABB⁴Event::lx).tag(kTag_Log);
        w.property("ly", &AABB⁴Event::ly).tag(kTag_Log);
        w.property("lz", &AABB⁴Event::lz).tag(kTag_Log);
        w.property("lw", &AABB⁴Event::lw).tag(kTag_Log);
        w.property("hx", &AABB⁴Event::hx).tag(kTag_Log);
        w.property("hy", &AABB⁴Event::hy).tag(kTag_Log);
        w.property("hz", &AABB⁴Event::hz).tag(kTag_Log);
        w.property("hw", &AABB⁴Event::hw).tag(kTag_Log);
        w.property("aabb", &AABB⁴Event::m_aabb).tag(kTag_Save);
    }
}
