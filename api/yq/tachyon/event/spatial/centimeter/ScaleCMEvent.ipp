////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ScaleCMEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ScaleCMEvent)

namespace yq::tachyon {
    ScaleCMEvent::ScaleCMEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    ScaleCMEvent::ScaleCMEvent(const Header&h, const Centimeter& v) : 
        SpatialEvent(h), m_scale(v)
    {
    }

    ScaleCMEvent::ScaleCMEvent(const ScaleCMEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_scale(cp.m_scale)
    {
    }

    ScaleCMEvent::~ScaleCMEvent()
    {
    }

    PostCPtr    ScaleCMEvent::clone(rebind_k, const Header& h) const 
    {
        return new ScaleCMEvent(*this, h);
    }
   
    void ScaleCMEvent::init_meta()
    {
        auto w = writer<ScaleCMEvent>();
        w.description("Scale Event in Centimeters");
        w.property("scale", &ScaleCMEvent::m_scale).tag(kTag_Log).tag(kTag_Save);
    }
}
