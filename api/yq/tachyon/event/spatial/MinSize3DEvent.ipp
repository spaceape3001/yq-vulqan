////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MinSize3DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MinSize³DEvent)

namespace yq::tachyon {
    MinSize³DEvent::MinSize³DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    MinSize³DEvent::MinSize³DEvent(const Header&h, const Size3D& v) : 
        SpatialEvent(h), m_size(v)
    {
    }

    MinSize³DEvent::MinSize³DEvent(const MinSize³DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_size(cp.m_size)
    {
    }

    MinSize³DEvent::~MinSize³DEvent()
    {
    }

    PostCPtr    MinSize³DEvent::clone(rebind_k, const Header& h) const 
    {
        return new MinSize³DEvent(*this, h);
    }
   
    void MinSize³DEvent::init_meta()
    {
        auto w = writer<MinSize³DEvent>();
        w.description("Min Size Event in 3D");
        w.property("x", &MinSize³DEvent::x).tag(kTag_Log);
        w.property("y", &MinSize³DEvent::y).tag(kTag_Log);
        w.property("z", &MinSize³DEvent::z).tag(kTag_Log);
        w.property("size", &MinSize³DEvent::m_size).tag(kTag_Save);
    }
}
