////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize3CEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize³CEvent)

namespace yq::tachyon {
    MinSize³CEvent::MinSize³CEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize³CEvent::MinSize³CEvent(const Header&h, const Size3CM& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize³CEvent::MinSize³CEvent(const MinSize³CEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize³CEvent::~MinSize³CEvent()
    {
    }

    PostCPtr    MinSize³CEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize³CEvent(*this, h);
    }
   
    void MinSize³CEvent::init_meta()
    {
        auto w = writer<MinSize³CEvent>();
        w.description("Min Size Event in 3D");
        w.property("x", &MinSize³CEvent::x).tag(kTag_Log);
        w.property("y", &MinSize³CEvent::y).tag(kTag_Log);
        w.property("z", &MinSize³CEvent::z).tag(kTag_Log);
        w.property("size", &MinSize³CEvent::m_size).tag(kTag_Save);
    }
}
