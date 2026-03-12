////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize1DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize¹DEvent)

namespace yq::tachyon {
    MaxSize¹DEvent::MaxSize¹DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize¹DEvent::MaxSize¹DEvent(const Header&h, const Size1D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize¹DEvent::MaxSize¹DEvent(const MaxSize¹DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize¹DEvent::~MaxSize¹DEvent()
    {
    }

    PostCPtr    MaxSize¹DEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize¹DEvent(*this, h);
    }
   
    void MaxSize¹DEvent::init_meta()
    {
        auto w = writer<MaxSize¹DEvent>();
        w.description("Max Size Event in 1D");
        w.property("x", &MaxSize¹DEvent::x).tag(kTag_Log);
        w.property("size", &MaxSize¹DEvent::m_size).tag(kTag_Save);
    }
}
