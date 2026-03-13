////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize2CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize²CEvent)

namespace yq::tachyon {
    MaxSize²CEvent::MaxSize²CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize²CEvent::MaxSize²CEvent(const Header&h, const Size2CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }
    
    MaxSize²CEvent::MaxSize²CEvent(const MaxSize²CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize²CEvent::~MaxSize²CEvent()
    {
    }

    PostCPtr    MaxSize²CEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize²CEvent(*this, h);
    }
   
    void MaxSize²CEvent::init_meta()
    {
        auto w = writer<MaxSize²CEvent>();
        w.description("Max Size Event in 2D");
        w.property("x", &MaxSize²CEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize²CEvent::y).tag(kTag_Log);
        w.property("size", &MaxSize²CEvent::m_size).tag(kTag_Save);
    }
}
