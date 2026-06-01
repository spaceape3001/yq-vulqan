////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size3MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size³MEvent)

namespace yq::tachyon {
    Size³MEvent::Size³MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size³MEvent::Size³MEvent(const Header&h, const Size3M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size³MEvent::Size³MEvent(const Size³MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size³MEvent::~Size³MEvent()
    {
    }

    PostCPtr    Size³MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size³MEvent(*this, h);
    }
   
    void Size³MEvent::init_meta()
    {
        auto w = writer<Size³MEvent>();
        w.description("Size Event in 3D");
        w.property("x", &Size³MEvent::x).tag(kTag_Log);
        w.property("y", &Size³MEvent::y).tag(kTag_Log);
        w.property("z", &Size³MEvent::z).tag(kTag_Log);
        w.property("size", &Size³MEvent::m_size).tag(kTag_Save);
    }
}
