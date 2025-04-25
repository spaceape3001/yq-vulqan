////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/Size4Event.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size⁴Event)

namespace yq::tachyon {
    Size⁴Event::Size⁴Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size⁴Event::Size⁴Event(const Header&h, const Size4D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size⁴Event::Size⁴Event(const Size⁴Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size⁴Event::~Size⁴Event()
    {
    }

    PostCPtr    Size⁴Event::clone(rebind_k, const Header& h) const 
    {
        return new Size⁴Event(*this, h);
    }
   
    void Size⁴Event::init_info()
    {
        auto w = writer<Size⁴Event>();
        w.description("Size Event in 4D");
        w.property("x", &Size⁴Event::x).tag(kTag_Log);
        w.property("y", &Size⁴Event::y).tag(kTag_Log);
        w.property("z", &Size⁴Event::z).tag(kTag_Log);
        w.property("w", &Size⁴Event::w).tag(kTag_Log);
        w.property("size", &Size⁴Event::m_size).tag(kTag_Save);
    }
}
