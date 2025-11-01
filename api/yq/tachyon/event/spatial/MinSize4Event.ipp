////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/spatial/MinSize4Event.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize⁴Event)

namespace yq::tachyon {
    MinSize⁴Event::MinSize⁴Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize⁴Event::MinSize⁴Event(const Header&h, const Size4D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize⁴Event::MinSize⁴Event(const MinSize⁴Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize⁴Event::~MinSize⁴Event()
    {
    }

    PostCPtr    MinSize⁴Event::clone(rebind_k, const Header& h) const 
    {
        return new MinSize⁴Event(*this, h);
    }
   
    void MinSize⁴Event::init_meta()
    {
        auto w = writer<MinSize⁴Event>();
        w.description("Min Size Event in 4D");
        w.property("x", &MinSize⁴Event::x).tag(kTag_Log);
        w.property("y", &MinSize⁴Event::y).tag(kTag_Log);
        w.property("z", &MinSize⁴Event::z).tag(kTag_Log);
        w.property("w", &MinSize⁴Event::w).tag(kTag_Log);
        w.property("size", &MinSize⁴Event::m_size).tag(kTag_Save);
    }
}
