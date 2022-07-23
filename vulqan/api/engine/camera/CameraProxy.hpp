////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <glm/glm.hpp>

namespace yq {
    namespace engine {
        //!  Camera data for rendering...
        struct CameraProxy {
            uint64_t        camera      = 0;
            uint64_t        revision    = 0;
            glm::dmat4      screen;
            bool operator==(const CameraProxy&) const noexcept;
        };
    }
}
