////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class Camera;

    //! Utiltity to bind a viewer to the whatever...
    class CameraBind {
    public:
        Camera*    camera() const { return m_camera; }
        
    protected:
        CameraBind(Camera* v) : m_camera(v) {}
        virtual ~CameraBind() {}
        
        Camera* const m_camera;
    };
}
