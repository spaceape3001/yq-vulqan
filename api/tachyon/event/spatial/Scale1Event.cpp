////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/Scale1Event.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scale¹Event)

namespace yq::tachyon {
    Scale¹Event::Scale¹Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Scale¹Event::Scale¹Event(const Header&h, const Vector1D& v) : 
        SpatialEvent(h), m_scale(v)
    {
    }

    Scale¹Event::Scale¹Event(const Scale¹Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_scale(cp.m_scale)
    {
    }

    Scale¹Event::~Scale¹Event()
    {
    }

    PostCPtr    Scale¹Event::clone(rebind_k, const Header& h) const 
    {
        return new Scale¹Event(*this, h);
    }
   
    void Scale¹Event::init_info()
    {
        auto w = writer<Scale¹Event>();
        w.description("Scaled Event in 1D");
        w.property("x", &Scale¹Event::x).tag(kTag_Log);
        w.property("scale", &Scale¹Event::m_scale).tag(kTag_Save);
    }
}
