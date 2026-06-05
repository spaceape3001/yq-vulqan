////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size2CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size²CMEvent)

namespace yq::tachyon {
    Size²CMEvent::Size²CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size²CMEvent::Size²CMEvent(const Header&h, const Size2CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    Size²CMEvent::Size²CMEvent(const Size²CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size²CMEvent::~Size²CMEvent()
    {
    }

    PostCPtr    Size²CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size²CMEvent(*this, h);
    }
   
    void Size²CMEvent::init_meta()
    {
        auto w = writer<Size²CMEvent>();
        w.description("Size Event in 2D");
        w.property("x", &Size²CMEvent::x).tag(kTag_Log);
        w.property("y", &Size²CMEvent::y).tag(kTag_Log);
        w.property("size", &Size²CMEvent::m_size).tag(kTag_Save);
    }
}
