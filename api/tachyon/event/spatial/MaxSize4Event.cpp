////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/MaxSize4Event.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize⁴Event)

namespace yq::tachyon {
    MaxSize⁴Event::MaxSize⁴Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize⁴Event::MaxSize⁴Event(const Header&h, const Size4D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize⁴Event::MaxSize⁴Event(const MaxSize⁴Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize⁴Event::~MaxSize⁴Event()
    {
    }

    PostCPtr    MaxSize⁴Event::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize⁴Event(*this, h);
    }
   
    void MaxSize⁴Event::init_info()
    {
        auto w = writer<MaxSize⁴Event>();
        w.description("Max Size Event in 4D");
        w.property("x", &MaxSize⁴Event::x).tag(kTag_Log);
        w.property("y", &MaxSize⁴Event::y).tag(kTag_Log);
        w.property("z", &MaxSize⁴Event::z).tag(kTag_Log);
        w.property("w", &MaxSize⁴Event::w).tag(kTag_Log);
        w.property("size", &MaxSize⁴Event::m_size).tag(kTag_Save);
    }
}
