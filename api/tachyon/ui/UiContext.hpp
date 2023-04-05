////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/preamble.hpp>
#include <glm/glm.hpp>

namespace yq {
    namespace tachyon {

        /*! \brief Mutable set of parameters that'll pass through
        
            \note If a caller MODIFIES this, they're obligated to restore before finishing
        */
        struct UiContext {
            //  If modified, restore before return
            Visualizer&     viz;
            VkCommandBuffer cmd             = nullptr;
            glm::mat4       world2eye;
            uint64_t        frame           = 0;
            //  Custom data to be passed through
            Object*         custom          = nullptr;
            bool            imgui_enabled   = false;
            
            UiContext(Visualizer& v) : viz(v) {}
        };
    }
}
