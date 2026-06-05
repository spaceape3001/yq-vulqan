////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ScaleMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ScaleMEvent)

namespace yq::tachyon {
    ScaleMEvent::ScaleMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    ScaleMEvent::ScaleMEvent(const Header&h, const Meter& v) : 
        SpatialEvent(h), m_scale(v)
    {
    }

    ScaleMEvent::ScaleMEvent(const ScaleMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_scale(cp.m_scale)
    {
    }

    ScaleMEvent::~ScaleMEvent()
    {
    }

    PostCPtr    ScaleMEvent::clone(rebind_k, const Header& h) const 
    {
        return new ScaleMEvent(*this, h);
    }
   
    void ScaleMEvent::init_meta()
    {
        auto w = writer<ScaleMEvent>();
        w.description("Scale Event in Meters");
        w.property("scale", &ScaleMEvent::m_scale).tag(kTag_Log).tag(kTag_Save);
    }
}
