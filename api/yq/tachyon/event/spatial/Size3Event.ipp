////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/Size3Event.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size³Event)

namespace yq::tachyon {
    Size³Event::Size³Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size³Event::Size³Event(const Header&h, const Size3D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size³Event::Size³Event(const Size³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size³Event::~Size³Event()
    {
    }

    PostCPtr    Size³Event::clone(rebind_k, const Header& h) const 
    {
        return new Size³Event(*this, h);
    }
   
    void Size³Event::init_meta()
    {
        auto w = writer<Size³Event>();
        w.description("Size Event in 3D");
        w.property("x", &Size³Event::x).tag(kTag_Log);
        w.property("y", &Size³Event::y).tag(kTag_Log);
        w.property("z", &Size³Event::z).tag(kTag_Log);
        w.property("size", &Size³Event::m_size).tag(kTag_Save);
    }
}
