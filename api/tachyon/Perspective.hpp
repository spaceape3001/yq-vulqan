////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/preamble.hpp>
#include <tachyon/Camera.hpp>
#include <0/math/shape/Rectangle2.hpp>
#include <0/math/color/RGB.hpp>
#include <optional>
#include <tachyon/enum/Tristate.hpp>

namespace yq::tachyon {

    /*! \brief A perspective, a view
    
        This is meant to capture the basics to a perspective, camera required.
    */
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
