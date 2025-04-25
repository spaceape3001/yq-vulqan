////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/AABB1Event.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AABB¹Event)

namespace yq::tachyon {
    AABB¹Event::AABB¹Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    AABB¹Event::AABB¹Event(const Header&h, const AxBox1D& v) : 
        SpatialEvent(h), m_aabb(v)
    {
    }
    
    AABB¹Event::AABB¹Event(const AABB¹Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_aabb(cp.m_aabb)
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
        w.description("AABB Changed Event in 1D");
        w.property("lx", &AABB¹Event::lx).tag(kTag_Log);
        w.property("hx", &AABB¹Event::hx).tag(kTag_Log);
        w.property("aabb", &AABB¹Event::m_aabb).tag(kTag_Save);
    }
}
