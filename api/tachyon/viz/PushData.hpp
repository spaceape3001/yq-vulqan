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
        glm::mat4   matrix      = {};     // either view or render... depending on enumeration
        glm::vec4   gamma       = { 1., 1., 1., 1. };
        glm::vec4   pricolor    = {};
        glm::vec4   seccolor    = {};
        float       time        = 0;
    };
}
