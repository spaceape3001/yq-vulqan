////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize1CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize¹CMEvent)

namespace yq::tachyon {
    MinSize¹CMEvent::MinSize¹CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize¹CMEvent::MinSize¹CMEvent(const Header&h, const Size1CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize¹CMEvent::MinSize¹CMEvent(const MinSize¹CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize¹CMEvent::~MinSize¹CMEvent()
    {
    }

    PostCPtr    MinSize¹CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize¹CMEvent(*this, h);
    }
   
    void MinSize¹CMEvent::init_meta()
    {
        auto w = writer<MinSize¹CMEvent>();
        w.description("Min Size Event in 1D");
        w.property("x", &MinSize¹CMEvent::x).tag(kTag_Log);
        w.property("size", &MinSize¹CMEvent::m_size).tag(kTag_Save);
    }
}
