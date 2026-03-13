////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size1CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size¹CEvent)

namespace yq::tachyon {
    Size¹CEvent::Size¹CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size¹CEvent::Size¹CEvent(const Header&h, const Size1CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size¹CEvent::Size¹CEvent(const Size¹CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size¹CEvent::~Size¹CEvent()
    {
    }

    PostCPtr    Size¹CEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size¹CEvent(*this, h);
    }
   
    void Size¹CEvent::init_meta()
    {
        auto w = writer<Size¹CEvent>();
        w.description("Size Event in 1D");
        w.property("x", &Size¹CEvent::x).tag(kTag_Log);
        w.property("size", &Size¹CEvent::m_size).tag(kTag_Save);
    }
}
