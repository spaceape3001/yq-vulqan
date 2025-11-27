////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/CameraEvent.hpp>

namespace yq::tachyon {
    class FarPlaneEvent : public CameraEvent {
        YQ_OBJECT_DECLARE(FarPlaneEvent, CameraEvent)
    public:
        FarPlaneEvent(const Header&, double);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        double  far_plane() const { return m_farPlane; }

    protected:
        FarPlaneEvent(const FarPlaneEvent&, const Header&);
        virtual ~FarPlaneEvent();
        
    private:
    
        double m_farPlane;

        FarPlaneEvent(const FarPlaneEvent&) = delete;
        FarPlaneEvent(FarPlaneEvent&&) = delete;
        FarPlaneEvent& operator=(const FarPlaneEvent&) = delete;
        FarPlaneEvent& operator=(FarPlaneEvent&&) = delete;
    };
}
