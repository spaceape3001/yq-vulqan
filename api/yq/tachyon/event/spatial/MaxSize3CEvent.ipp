////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize3CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize³CEvent)

namespace yq::tachyon {
    MaxSize³CEvent::MaxSize³CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize³CEvent::MaxSize³CEvent(const Header&h, const Size3CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize³CEvent::MaxSize³CEvent(const MaxSize³CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize³CEvent::~MaxSize³CEvent()
    {
    }

    PostCPtr    MaxSize³CEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize³CEvent(*this, h);
    }
   
    void MaxSize³CEvent::init_meta()
    {
        auto w = writer<MaxSize³CEvent>();
        w.description("Max Size Event in 3D");
        w.property("x", &MaxSize³CEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize³CEvent::y).tag(kTag_Log);
        w.property("z", &MaxSize³CEvent::z).tag(kTag_Log);
        w.property("size", &MaxSize³CEvent::m_size).tag(kTag_Save);
    }
}
