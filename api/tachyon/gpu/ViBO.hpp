////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>
#include <tachyon/preamble.hpp>

namespace yq {
    namespace tachyon {
        struct ABOConfig;
    
        struct ViBO {
            VkBuffer        buffer  = nullptr;
            uint64_t        rev     = 0;
            uint32_t        count   = 0;
            uint32_t        offset  = 0;
            
            void    update(Visualizer&, const ABOConfig&, const void*);
        };
    }
}
