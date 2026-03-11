////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaxSize3DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaxSize³DEvent)

namespace yq::tachyon {
    MaxSize³DEvent::MaxSize³DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MaxSize³DEvent::MaxSize³DEvent(const Header&h, const Size3D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MaxSize³DEvent::MaxSize³DEvent(const MaxSize³DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MaxSize³DEvent::~MaxSize³DEvent()
    {
    }

    PostCPtr    MaxSize³DEvent::clone(rebind_k, const Header& h) const 
    {
        return new MaxSize³DEvent(*this, h);
    }
   
    void MaxSize³DEvent::init_meta()
    {
        auto w = writer<MaxSize³DEvent>();
        w.description("Max Size Event in 3D");
        w.property("x", &MaxSize³DEvent::x).tag(kTag_Log);
        w.property("y", &MaxSize³DEvent::y).tag(kTag_Log);
        w.property("z", &MaxSize³DEvent::z).tag(kTag_Log);
        w.property("size", &MaxSize³DEvent::m_size).tag(kTag_Save);
    }
}
