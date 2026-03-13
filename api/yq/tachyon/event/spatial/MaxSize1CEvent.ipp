////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize1CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize¹CEvent)

namespace yq::tachyon {
    MaxSize¹CEvent::MaxSize¹CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize¹CEvent::MaxSize¹CEvent(const Header&h, const Size1CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize¹CEvent::MaxSize¹CEvent(const MaxSize¹CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize¹CEvent::~MaxSize¹CEvent()
    {
    }

    PostCPtr    MaxSize¹CEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize¹CEvent(*this, h);
    }
   
    void MaxSize¹CEvent::init_meta()
    {
        auto w = writer<MaxSize¹CEvent>();
        w.description("Max Size Event in 1D");
        w.property("x", &MaxSize¹CEvent::x).tag(kTag_Log);
        w.property("size", &MaxSize¹CEvent::m_size).tag(kTag_Save);
    }
}
