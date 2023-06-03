////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


#include <tachyon/preamble.hpp>
#include <tachyon/scene/Rendered.hpp>

namespace yq {
    namespace tachyon {
        /*! \brief Frame of things to be rendered
        
            This will include lighting (eventually) & rendred objects.
        */
        struct Scene {
            std::vector<RenderedPtr>    things;
            std::optional<RGB3F>        background;
            // eventually things like lights, background/layers/materials/etc will go here
            double                      utime   = 0.; // for the push constant
        };
    }
}
