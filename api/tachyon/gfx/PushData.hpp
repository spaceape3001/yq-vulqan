////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <glm/glm.hpp>

namespace yq {
    namespace tachyon {

        //! Render Push Data
        struct StdPushData {
            glm::mat4       matrix; // either full or render... depending on enumeration
        };

        //! Standard push data 
        struct TimePushData {
            glm::mat4       transform;
            double          time        = 0;
        };
    }
}
