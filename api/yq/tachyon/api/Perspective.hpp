////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <engine/preamble.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <optional>

namespace yq::tachyon {

    /*! \brief A perspective, a view
    
        This is meant to capture the basics to a perspective, camera required.
    */
    struct Perspective0 {
        // Only the camera shall be required
        CameraCPtr                  camera;
        std::optional<RGBA4F>       background;
        std::optional<Rectangle2D>  screen;
        Tristate                    wireframe   = Tristate::INHERIT;
        
        Perspective0();
        Perspective0(const CameraCPtr& c) : camera(c) {}

        ~Perspective0();
    };
}
