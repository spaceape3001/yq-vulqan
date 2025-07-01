////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/MinSize1Event.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize¹Event)

namespace yq::tachyon {
    MinSize¹Event::MinSize¹Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize¹Event::MinSize¹Event(const Header&h, const Size1D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize¹Event::MinSize¹Event(const MinSize¹Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize¹Event::~MinSize¹Event()
    {
    }

    PostCPtr    MinSize¹Event::clone(rebind_k, const Header& h) const 
    {
        return new MinSize¹Event(*this, h);
    }
   
    void MinSize¹Event::init_meta()
    {
        auto w = writer<MinSize¹Event>();
        w.description("Min Size Event in 1D");
        w.property("x", &MinSize¹Event::x).tag(kTag_Log);
        w.property("size", &MinSize¹Event::m_size).tag(kTag_Save);
    }
}
