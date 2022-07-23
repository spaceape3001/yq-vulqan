////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/BasicBuffer.hpp>
#include <engine/preamble.hpp>
#include <vulkan/vulkan_core.h>
#include <optional>
#include <span>

namespace yq {
    namespace engine {

        /*! \brief Basic "Object" Command that is rendered to vulkan
        
            \note This is the basics, only what is needed for the buffer, nothing more.
        */
        struct VqCommand {
            struct VBO {
                const VkBuffer*         buffers = nullptr;
                const VkDeviceSize*     offsets = nullptr;
                size_t                  count   = 0;
                size_t                  first   = 0;
            };
            
            struct UBO {
                // TODO
            };
            
            struct Draw {
                uint32_t    vertexCount     = 0;
                uint32_t    instanceCount   = 1;
                uint32_t    firstVertex     = 0;
                uint32_t    firstInstance   = 0;
            };
            
        
            //! Used for the object/command tracking system
            uint64_t                object      = 0;
            //! Used for the object/command tracking system
            uint64_t                revision    = 0;
            //  note a NULL pipeline will recycle the previous one
            VkPipeline              pipeline    = nullptr;
            VkPipelineLayout        layout      = nullptr;
            
            BasicBuffer<MAX_PUSH>   push;
            uint32_t                push_mask   = 0;
            
            
            std::optional<UBO>      ubo;
            std::optional<VBO>      vbo;
            std::optional<Draw>     draw;
        };
        
        void    record_draw(VkCommandBuffer, const VqCommand&);
        void    record_draw(VkCommandBuffer, std::span<const VqCommand>);
        void    record_draw(VkCommandBuffer, const std::span<VqCommand>);

    }
}
