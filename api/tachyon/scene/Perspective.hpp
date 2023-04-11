////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/preamble.hpp>
#include <tachyon/camera/Camera.hpp>
#include <math/shape/Rectangle2.hpp>
#include <math/color/RGB.hpp>
#include <optional>
#include <tachyon/enum/Tristate.hpp>

namespace yq {
    namespace tachyon {
        struct Perspective {
            // Only the camera shall be required
            CameraCPtr                  camera;
            std::optional<RGB3F>        background;
            std::optional<Rectangle2D>  screen;
            Tristate                    wireframe   = Tristate::INHERIT;
            
            Perspective();
            Perspective(const CameraCPtr& c) : camera(c) {}

            ~Perspective();
        };
    }
}