////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/render/Rendered.hpp>
#include <math/RGB.hpp>

namespace yq {
    namespace engine {
        /*! \brief Frame of things to be rendered
        
            This will include lighting (eventually) & rendred objects.
        
        *//*
            To get things to be rendered, the general process should go...
            
            Scene -> Frame -> VqCommands
        */
        struct Scene {
            std::vector<RenderedPtr>    things;
            std::optional<RGB3F>        background;
            float                       utime   = 0.;   // This is passed into the standard push constant
        };
        
    }
}
