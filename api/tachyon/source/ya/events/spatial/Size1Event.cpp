////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/Size1Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size¹Event)

namespace yq::tachyon {
    Size¹Event::Size¹Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size¹Event::Size¹Event(const Header&h, const Size1D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size¹Event::Size¹Event(const Size¹Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size¹Event::~Size¹Event()
    {
    }

    PostCPtr    Size¹Event::clone(rebind_k, const Header& h) const 
    {
        return new Size¹Event(*this, h);
    }
   
    void Size¹Event::init_info()
    {
        auto w = writer<Size¹Event>();
        w.description("Size Event in 1D");
        w.property("x", &Size¹Event::x).tag(kTag_Log);
        w.property("size", &Size¹Event::m_size).tag(kTag_Save);
    }
}
