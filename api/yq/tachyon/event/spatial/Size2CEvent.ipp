////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size2CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size²CEvent)

namespace yq::tachyon {
    Size²CEvent::Size²CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size²CEvent::Size²CEvent(const Header&h, const Size2CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    Size²CEvent::Size²CEvent(const Size²CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size²CEvent::~Size²CEvent()
    {
    }

    PostCPtr    Size²CEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size²CEvent(*this, h);
    }
   
    void Size²CEvent::init_meta()
    {
        auto w = writer<Size²CEvent>();
        w.description("Size Event in 2D");
        w.property("x", &Size²CEvent::x).tag(kTag_Log);
        w.property("y", &Size²CEvent::y).tag(kTag_Log);
        w.property("size", &Size²CEvent::m_size).tag(kTag_Save);
    }
}
