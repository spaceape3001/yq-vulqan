////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Camera.hpp>

namespace yq {
    namespace camera {
        class Null : public Camera {
            YQ_OBJECT_DECLARE(Null, Camera)
        public:
        
            glm::dmat4  world2screen(const Params&) const override;
            Null();
            ~Null();
        };
    }
}
