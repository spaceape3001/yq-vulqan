////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NearPlaneEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::NearPlaneEvent)

namespace yq::tachyon {

    NearPlaneEvent::NearPlaneEvent(const Header&h, double v) : CameraEvent(h), m_nearPlane(v)
    {
    }

    NearPlaneEvent::NearPlaneEvent(const NearPlaneEvent& cp, const Header& h) : CameraEvent(cp, h), m_nearPlane(cp.m_nearPlane)
    {
    }
    
    NearPlaneEvent::~NearPlaneEvent()
    {
    }

    PostCPtr    NearPlaneEvent::clone(rebind_k, const Header&h) const 
    {
        return new NearPlaneEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void NearPlaneEvent::init_meta()
    {
        auto w = writer<NearPlaneEvent>();
        w.description("Near Plane Event");
        w.property("near_plane", &NearPlaneEvent::m_nearPlane);
    }
}
