////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Size1MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Size¹MEvent)

namespace yq::tachyon {
    Size¹MEvent::Size¹MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Size¹MEvent::Size¹MEvent(const Header&h, const Size1M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    Size¹MEvent::Size¹MEvent(const Size¹MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    Size¹MEvent::~Size¹MEvent()
    {
    }

    PostCPtr    Size¹MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Size¹MEvent(*this, h);
    }
   
    void Size¹MEvent::init_meta()
    {
        auto w = writer<Size¹MEvent>();
        w.description("Size Event in 1D");
        w.property("x", &Size¹MEvent::x).tag(kTag_Log);
        w.property("size", &Size¹MEvent::m_size).tag(kTag_Save);
    }
}
