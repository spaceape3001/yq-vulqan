////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize3CMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize³CMEvent)

namespace yq::tachyon {
    MinSize³CMEvent::MinSize³CMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize³CMEvent::MinSize³CMEvent(const Header&h, const Size3CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize³CMEvent::MinSize³CMEvent(const MinSize³CMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize³CMEvent::~MinSize³CMEvent()
    {
    }

    PostCPtr    MinSize³CMEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize³CMEvent(*this, h);
    }
   
    void MinSize³CMEvent::init_meta()
    {
        auto w = writer<MinSize³CMEvent>();
        w.description("Min Size Event in 3D");
        w.property("x", &MinSize³CMEvent::x).tag(kTag_Log);
        w.property("y", &MinSize³CMEvent::y).tag(kTag_Log);
        w.property("z", &MinSize³CMEvent::z).tag(kTag_Log);
        w.property("size", &MinSize³CMEvent::m_size).tag(kTag_Save);
    }
}
