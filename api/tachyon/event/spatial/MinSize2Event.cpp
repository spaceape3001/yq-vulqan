////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/MinSize2Event.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize²Event)

namespace yq::tachyon {
    MinSize²Event::MinSize²Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize²Event::MinSize²Event(const Header&h, const Size2D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MinSize²Event::MinSize²Event(const MinSize²Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize²Event::~MinSize²Event()
    {
    }

    PostCPtr    MinSize²Event::clone(rebind_k, const Header& h) const 
    {
        return new MinSize²Event(*this, h);
    }
   
    void MinSize²Event::init_info()
    {
        auto w = writer<MinSize²Event>();
        w.description("Min Size Event in 2D");
        w.property("x", &MinSize²Event::x).tag(kTag_Log);
        w.property("y", &MinSize²Event::y).tag(kTag_Log);
        w.property("size", &MinSize²Event::m_size).tag(kTag_Save);
    }
}
