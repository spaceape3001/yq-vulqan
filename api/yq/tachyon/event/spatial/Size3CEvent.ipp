////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size3CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size³CEvent)

namespace yq::tachyon {
    Size³CEvent::Size³CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size³CEvent::Size³CEvent(const Header&h, const Size3CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size³CEvent::Size³CEvent(const Size³CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size³CEvent::~Size³CEvent()
    {
    }

    PostCPtr    Size³CEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size³CEvent(*this, h);
    }
   
    void Size³CEvent::init_meta()
    {
        auto w = writer<Size³CEvent>();
        w.description("Size Event in 3D");
        w.property("x", &Size³CEvent::x).tag(kTag_Log);
        w.property("y", &Size³CEvent::y).tag(kTag_Log);
        w.property("z", &Size³CEvent::z).tag(kTag_Log);
        w.property("size", &Size³CEvent::m_size).tag(kTag_Save);
    }
}
