////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Camera.hpp>

namespace yq::tachyon {
    class NullCamera : public Camera {
        YQ_OBJECT_DECLARE(NullCamera, Camera)
    public:
    
        glm::dmat4  world2screen(const Params&) const override;
        NullCamera();
        ~NullCamera();
    };
}
