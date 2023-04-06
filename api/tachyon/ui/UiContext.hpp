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
            
            We're making this structure so consumers can optionally extend with their own 
            custom data
        */
        struct UiContext {
            //  If modified, restore before return
            Visualizer*     viz             = nullptr;  // yep, back to pointer
            VkCommandBuffer cmd             = nullptr;
            glm::mat4       world2eye;
            uint64_t        frame           = 0;
            bool            imgui_enabled   = false;
        };
    }
}
