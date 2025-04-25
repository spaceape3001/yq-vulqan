////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/MaxSize2Event.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize²Event)

namespace yq::tachyon {
    MaxSize²Event::MaxSize²Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize²Event::MaxSize²Event(const Header&h, const Size2D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MaxSize²Event::MaxSize²Event(const MaxSize²Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize²Event::~MaxSize²Event()
    {
    }

    PostCPtr    MaxSize²Event::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize²Event(*this, h);
    }
   
    void MaxSize²Event::init_info()
    {
        auto w = writer<MaxSize²Event>();
        w.description("Max Size Event in 2D");
        w.property("x", &MaxSize²Event::x).tag(kTag_Log);
        w.property("y", &MaxSize²Event::y).tag(kTag_Log);
        w.property("size", &MaxSize²Event::m_size).tag(kTag_Save);
    }
}
