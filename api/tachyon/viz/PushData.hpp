////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <glm/glm.hpp>

namespace yq::tachyon {

    //! Standard Push Data
    struct StdPushData {
        //! Either a model -> screen matrix, or world -> screen matrix, depending on the enumeration
        glm::mat4   matrix      = {};
        
        //! Color by color gamma multipliers
        glm::vec4   gamma       = { 1., 1., 1., 1. };
        
        //! Primary color for object
        glm::vec4   pricolor    = {};
        
        //! Secondary color for object
        glm::vec4   seccolor    = {};
        
        //! Clock time
        float       time        = 0;
    };
}
