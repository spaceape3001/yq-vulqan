////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size1CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size¹CMEvent)

namespace yq::tachyon {
    Size¹CMEvent::Size¹CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size¹CMEvent::Size¹CMEvent(const Header&h, const Size1CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size¹CMEvent::Size¹CMEvent(const Size¹CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size¹CMEvent::~Size¹CMEvent()
    {
    }

    PostCPtr    Size¹CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size¹CMEvent(*this, h);
    }
   
    void Size¹CMEvent::init_meta()
    {
        auto w = writer<Size¹CMEvent>();
        w.description("Size Event in 1D");
        w.property("x", &Size¹CMEvent::x).tag(kTag_Log);
        w.property("size", &Size¹CMEvent::m_size).tag(kTag_Save);
    }
}
