////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <vulkan/vulkan_core.h>

namespace yq {
    namespace tachyon {
        struct ViQueues {
            std::vector<VkQueue>    queues;
            uint32_t                family   = UINT32_MAX;
            
            void    set(VkDevice, uint32_t cnt);
            ~ViQueues();
            VkQueue operator[](uint32_t i) const;
            bool valid() const { return family != UINT32_MAX; }
        };
    }
}
