////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/Size2Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size²Event)

namespace yq::tachyon {
    Size²Event::Size²Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size²Event::Size²Event(const Header&h, const Size2D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    Size²Event::Size²Event(const Size²Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size²Event::~Size²Event()
    {
    }

    PostCPtr    Size²Event::clone(rebind_k, const Header& h) const 
    {
        return new Size²Event(*this, h);
    }
   
    void Size²Event::init_info()
    {
        auto w = writer<Size²Event>();
        w.description("Sized Event in 2D");
        w.property("x", &Size²Event::x).tag(kTag_Log);
        w.property("y", &Size²Event::y).tag(kTag_Log);
        w.property("size", &Size²Event::m_size).tag(kTag_Save);
    }
}
