////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/MaxSize1Event.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize¹Event)

namespace yq::tachyon {
    MaxSize¹Event::MaxSize¹Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize¹Event::MaxSize¹Event(const Header&h, const Size1D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize¹Event::MaxSize¹Event(const MaxSize¹Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize¹Event::~MaxSize¹Event()
    {
    }

    PostCPtr    MaxSize¹Event::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize¹Event(*this, h);
    }
   
    void MaxSize¹Event::init_info()
    {
        auto w = writer<MaxSize¹Event>();
        w.description("Max Size Event in 1D");
        w.property("x", &MaxSize¹Event::x).tag(kTag_Log);
        w.property("size", &MaxSize¹Event::m_size).tag(kTag_Save);
    }
}
