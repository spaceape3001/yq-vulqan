////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
    class ViVisualizer;
    struct TexConfig;
    

    struct ViTextureObject {
        VkDescriptorSet         desc        = nullptr;
        VkImageView             view        = nullptr;
        VkSampler               sampler     = nullptr;
        uint64_t                rev         = 0ULL;

        //  returns TRUE if changed
        bool    update(ViVisualizer&, const TexConfig&, const void*);
    };

}
