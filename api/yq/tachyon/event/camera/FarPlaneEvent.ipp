////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FarPlaneEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FarPlaneEvent)

namespace yq::tachyon {

    FarPlaneEvent::FarPlaneEvent(const Header&h, double v) : CameraEvent(h), m_farPlane(v)
    {
    }

    FarPlaneEvent::FarPlaneEvent(const FarPlaneEvent& cp, const Header& h) : CameraEvent(cp, h), m_farPlane(cp.m_farPlane)
    {
    }
    
    FarPlaneEvent::~FarPlaneEvent()
    {
    }

    PostCPtr    FarPlaneEvent::clone(rebind_k, const Header&h) const 
    {
        return new FarPlaneEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void FarPlaneEvent::init_meta()
    {
        auto w = writer<FarPlaneEvent>();
        w.description("Far Plane Event");
        w.property("far_plane", &FarPlaneEvent::m_farPlane);
    }
}
