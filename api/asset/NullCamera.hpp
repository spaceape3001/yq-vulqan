////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/Camera.hpp>

namespace yq {
    namespace asset {
        class NullCamera : public engine::Camera {
            YQ_OBJECT_DECLARE(NullCamera, engine::Camera)
        public:
        
            glm::dmat4  world2screen(const engine::CameraParams&) const override;
            NullCamera();
            ~NullCamera();
        };
    }
}
