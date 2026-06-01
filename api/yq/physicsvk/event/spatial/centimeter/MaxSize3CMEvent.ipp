////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize3CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize³CMEvent)

namespace yq::tachyon {
    MaxSize³CMEvent::MaxSize³CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize³CMEvent::MaxSize³CMEvent(const Header&h, const Size3CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize³CMEvent::MaxSize³CMEvent(const MaxSize³CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize³CMEvent::~MaxSize³CMEvent()
    {
    }

    PostCPtr    MaxSize³CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize³CMEvent(*this, h);
    }
   
    void MaxSize³CMEvent::init_meta()
    {
        auto w = writer<MaxSize³CMEvent>();
        w.description("Max Size Event in 3D");
        w.property("x", &MaxSize³CMEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize³CMEvent::y).tag(kTag_Log);
        w.property("z", &MaxSize³CMEvent::z).tag(kTag_Log);
        w.property("size", &MaxSize³CMEvent::m_size).tag(kTag_Save);
    }
}
