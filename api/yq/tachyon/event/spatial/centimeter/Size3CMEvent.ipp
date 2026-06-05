////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size3CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size³CMEvent)

namespace yq::tachyon {
    Size³CMEvent::Size³CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size³CMEvent::Size³CMEvent(const Header&h, const Size3CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size³CMEvent::Size³CMEvent(const Size³CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size³CMEvent::~Size³CMEvent()
    {
    }

    PostCPtr    Size³CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size³CMEvent(*this, h);
    }
   
    void Size³CMEvent::init_meta()
    {
        auto w = writer<Size³CMEvent>();
        w.description("Size Event in 3D");
        w.property("x", &Size³CMEvent::x).tag(kTag_Log);
        w.property("y", &Size³CMEvent::y).tag(kTag_Log);
        w.property("z", &Size³CMEvent::z).tag(kTag_Log);
        w.property("size", &Size³CMEvent::m_size).tag(kTag_Save);
    }
}
