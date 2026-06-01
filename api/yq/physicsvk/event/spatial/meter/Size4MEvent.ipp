////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size4MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size⁴MEvent)

namespace yq::tachyon {
    Size⁴MEvent::Size⁴MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size⁴MEvent::Size⁴MEvent(const Header&h, const Size4M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size⁴MEvent::Size⁴MEvent(const Size⁴MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size⁴MEvent::~Size⁴MEvent()
    {
    }

    PostCPtr    Size⁴MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size⁴MEvent(*this, h);
    }
   
    void Size⁴MEvent::init_meta()
    {
        auto w = writer<Size⁴MEvent>();
        w.description("Size Event in 4D");
        w.property("x", &Size⁴MEvent::x).tag(kTag_Log);
        w.property("y", &Size⁴MEvent::y).tag(kTag_Log);
        w.property("z", &Size⁴MEvent::z).tag(kTag_Log);
        w.property("w", &Size⁴MEvent::w).tag(kTag_Log);
        w.property("size", &Size⁴MEvent::m_size).tag(kTag_Save);
    }
}
