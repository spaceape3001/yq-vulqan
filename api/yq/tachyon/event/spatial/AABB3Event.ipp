////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/AABB3Event.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AABB³Event)

namespace yq::tachyon {
    AABB³Event::AABB³Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    AABB³Event::AABB³Event(const Header&h, const AxBox3D& v) : 
        SpatialEvent(h), m_aabb(v)
    {
    }

    AABB³Event::AABB³Event(const AABB³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_aabb(cp.m_aabb)
    {
    }

    AABB³Event::~AABB³Event()
    {
    }

    PostCPtr    AABB³Event::clone(rebind_k, const Header& h) const 
    {
        return new AABB³Event(*this, h);
    }
   
    void AABB³Event::init_meta()
    {
        auto w = writer<AABB³Event>();
        w.description("AABB Changed Event in 3D");
        w.property("lx", &AABB³Event::lx).tag(kTag_Log);
        w.property("ly", &AABB³Event::ly).tag(kTag_Log);
        w.property("lz", &AABB³Event::lz).tag(kTag_Log);
        w.property("hx", &AABB³Event::hx).tag(kTag_Log);
        w.property("hy", &AABB³Event::hy).tag(kTag_Log);
        w.property("hz", &AABB³Event::hz).tag(kTag_Log);
        w.property("aabb", &AABB³Event::m_aabb).tag(kTag_Save);
    }
}
