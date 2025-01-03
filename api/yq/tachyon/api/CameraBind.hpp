////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/camera.hpp>

namespace yq::tachyon {
    class Camera;

    //! Utiltity to bind a viewer to the whatever...
    class CameraBind {
    public:
        CameraID    camera() const { return m_camera; }
        
    protected:
        CameraBind(CameraID v) : m_camera(v) {}
        CameraBind(const Camera* v);
        virtual ~CameraBind() {}
        
        CameraID const m_camera;
    };
}
