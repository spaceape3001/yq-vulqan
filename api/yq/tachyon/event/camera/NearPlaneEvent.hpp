////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/CameraEvent.hpp>

namespace yq::tachyon {
    class NearPlaneEvent : public CameraEvent {
        YQ_OBJECT_DECLARE(NearPlaneEvent, CameraEvent)
    public:
        NearPlaneEvent(const Header&, double);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        double  near_plane() const { return m_nearPlane; }

    protected:
        NearPlaneEvent(const NearPlaneEvent&, const Header&);
        virtual ~NearPlaneEvent();
        
    private:
    
        double m_nearPlane;

        NearPlaneEvent(const NearPlaneEvent&) = delete;
        NearPlaneEvent(NearPlaneEvent&&) = delete;
        NearPlaneEvent& operator=(const NearPlaneEvent&) = delete;
        NearPlaneEvent& operator=(NearPlaneEvent&&) = delete;
    };
}
