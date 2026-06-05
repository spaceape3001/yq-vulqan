////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size2MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size²MEvent)

namespace yq::tachyon {
    Size²MEvent::Size²MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size²MEvent::Size²MEvent(const Header&h, const Size2M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    Size²MEvent::Size²MEvent(const Size²MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size²MEvent::~Size²MEvent()
    {
    }

    PostCPtr    Size²MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size²MEvent(*this, h);
    }
   
    void Size²MEvent::init_meta()
    {
        auto w = writer<Size²MEvent>();
        w.description("Size Event in 2D");
        w.property("x", &Size²MEvent::x).tag(kTag_Log);
        w.property("y", &Size²MEvent::y).tag(kTag_Log);
        w.property("size", &Size²MEvent::m_size).tag(kTag_Save);
    }
}
