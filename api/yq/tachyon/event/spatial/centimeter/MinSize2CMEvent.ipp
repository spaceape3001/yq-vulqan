////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize2CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize²CMEvent)

namespace yq::tachyon {
    MinSize²CMEvent::MinSize²CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize²CMEvent::MinSize²CMEvent(const Header&h, const Size2CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MinSize²CMEvent::MinSize²CMEvent(const MinSize²CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize²CMEvent::~MinSize²CMEvent()
    {
    }

    PostCPtr    MinSize²CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize²CMEvent(*this, h);
    }
   
    void MinSize²CMEvent::init_meta()
    {
        auto w = writer<MinSize²CMEvent>();
        w.description("Min Size Event in 2D");
        w.property("x", &MinSize²CMEvent::x).tag(kTag_Log);
        w.property("y", &MinSize²CMEvent::y).tag(kTag_Log);
        w.property("size", &MinSize²CMEvent::m_size).tag(kTag_Save);
    }
}
