////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size4CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size⁴CEvent)

namespace yq::tachyon {
    Size⁴CEvent::Size⁴CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size⁴CEvent::Size⁴CEvent(const Header&h, const Size4CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size⁴CEvent::Size⁴CEvent(const Size⁴CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size⁴CEvent::~Size⁴CEvent()
    {
    }

    PostCPtr    Size⁴CEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size⁴CEvent(*this, h);
    }
   
    void Size⁴CEvent::init_meta()
    {
        auto w = writer<Size⁴CEvent>();
        w.description("Size Event in 4D");
        w.property("x", &Size⁴CEvent::x).tag(kTag_Log);
        w.property("y", &Size⁴CEvent::y).tag(kTag_Log);
        w.property("z", &Size⁴CEvent::z).tag(kTag_Log);
        w.property("w", &Size⁴CEvent::w).tag(kTag_Log);
        w.property("size", &Size⁴CEvent::m_size).tag(kTag_Save);
    }
}
