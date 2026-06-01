////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize2CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize²CMEvent)

namespace yq::tachyon {
    MaxSize²CMEvent::MaxSize²CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize²CMEvent::MaxSize²CMEvent(const Header&h, const Size2CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MaxSize²CMEvent::MaxSize²CMEvent(const MaxSize²CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize²CMEvent::~MaxSize²CMEvent()
    {
    }

    PostCPtr    MaxSize²CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize²CMEvent(*this, h);
    }
   
    void MaxSize²CMEvent::init_meta()
    {
        auto w = writer<MaxSize²CMEvent>();
        w.description("Max Size Event in 2D");
        w.property("x", &MaxSize²CMEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize²CMEvent::y).tag(kTag_Log);
        w.property("size", &MaxSize²CMEvent::m_size).tag(kTag_Save);
    }
}
