////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize1MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize¹MEvent)

namespace yq::tachyon {
    MaxSize¹MEvent::MaxSize¹MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize¹MEvent::MaxSize¹MEvent(const Header&h, const Size1M& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize¹MEvent::MaxSize¹MEvent(const MaxSize¹MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize¹MEvent::~MaxSize¹MEvent()
    {
    }

    PostCPtr    MaxSize¹MEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize¹MEvent(*this, h);
    }
   
    void MaxSize¹MEvent::init_meta()
    {
        auto w = writer<MaxSize¹MEvent>();
        w.description("Max Size Event in 1D");
        w.property("x", &MaxSize¹MEvent::x).tag(kTag_Log);
        w.property("size", &MaxSize¹MEvent::m_size).tag(kTag_Save);
    }
}
