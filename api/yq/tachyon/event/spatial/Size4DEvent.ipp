////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size4DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size⁴DEvent)

namespace yq::tachyon {
    Size⁴DEvent::Size⁴DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size⁴DEvent::Size⁴DEvent(const Header&h, const Size4D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size⁴DEvent::Size⁴DEvent(const Size⁴DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size⁴DEvent::~Size⁴DEvent()
    {
    }

    PostCPtr    Size⁴DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size⁴DEvent(*this, h);
    }
   
    void Size⁴DEvent::init_meta()
    {
        auto w = writer<Size⁴DEvent>();
        w.description("Size Event in 4D");
        w.property("x", &Size⁴DEvent::x).tag(kTag_Log);
        w.property("y", &Size⁴DEvent::y).tag(kTag_Log);
        w.property("z", &Size⁴DEvent::z).tag(kTag_Log);
        w.property("w", &Size⁴DEvent::w).tag(kTag_Log);
        w.property("size", &Size⁴DEvent::m_size).tag(kTag_Save);
    }
}
