////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
    class ViBufferManager;
    struct BaseBOConfig;
    
    struct ViBufferObject {
        VkBuffer        buffer  = nullptr;
        uint64_t        rev     = 0;
        uint32_t        count   = 0;
        uint32_t        offset  = 0;
        
        //  returns TRUE if changed
        bool    update(ViBufferManager&, const BaseBOConfig&, const void*);
    };
}
