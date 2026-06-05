////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size4CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size⁴CMEvent)

namespace yq::tachyon {
    Size⁴CMEvent::Size⁴CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size⁴CMEvent::Size⁴CMEvent(const Header&h, const Size4CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size⁴CMEvent::Size⁴CMEvent(const Size⁴CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size⁴CMEvent::~Size⁴CMEvent()
    {
    }

    PostCPtr    Size⁴CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size⁴CMEvent(*this, h);
    }
   
    void Size⁴CMEvent::init_meta()
    {
        auto w = writer<Size⁴CMEvent>();
        w.description("Size Event in 4D");
        w.property("x", &Size⁴CMEvent::x).tag(kTag_Log);
        w.property("y", &Size⁴CMEvent::y).tag(kTag_Log);
        w.property("z", &Size⁴CMEvent::z).tag(kTag_Log);
        w.property("w", &Size⁴CMEvent::w).tag(kTag_Log);
        w.property("size", &Size⁴CMEvent::m_size).tag(kTag_Save);
    }
}
