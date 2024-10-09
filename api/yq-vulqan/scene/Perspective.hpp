////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <engine/preamble.hpp>
#include <yq-toolbox/shape/Rectangle2.hpp>
#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq-vulqan/basic/Tristate.hpp>
#include <yq-vulqan/camera/Camera.hpp>
#include <yq-vulqan/typedef/camera.hpp>
#include <optional>

namespace yq::tachyon {

    /*! \brief A perspective, a view
    
        This is meant to capture the basics to a perspective, camera required.
    */
    struct Perspective {
        // Only the camera shall be required
        CameraCPtr                  camera;
        std::optional<RGBA4F>       background;
        std::optional<Rectangle2D>  screen;
        Tristate                    wireframe   = Tristate::INHERIT;
        
        Perspective();
        Perspective(const CameraCPtr& c) : camera(c) {}

        ~Perspective();
    };
}
