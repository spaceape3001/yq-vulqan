////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize1CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize¹CMEvent)

namespace yq::tachyon {
    MaxSize¹CMEvent::MaxSize¹CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize¹CMEvent::MaxSize¹CMEvent(const Header&h, const Size1CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize¹CMEvent::MaxSize¹CMEvent(const MaxSize¹CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize¹CMEvent::~MaxSize¹CMEvent()
    {
    }

    PostCPtr    MaxSize¹CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize¹CMEvent(*this, h);
    }
   
    void MaxSize¹CMEvent::init_meta()
    {
        auto w = writer<MaxSize¹CMEvent>();
        w.description("Max Size Event in 1D");
        w.property("x", &MaxSize¹CMEvent::x).tag(kTag_Log);
        w.property("size", &MaxSize¹CMEvent::m_size).tag(kTag_Save);
    }
}
