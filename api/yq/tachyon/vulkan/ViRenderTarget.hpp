////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
    struct ViRenderTarget {
        VkViewport2D    viewport{};
        VkClearValue    clear{};
        VkFramebuffer   frameBuffer = nullptr;
        VkRenderPass    renderPass  = nullptr;
    };
}

