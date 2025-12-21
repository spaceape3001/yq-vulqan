////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>
#include <yq/tachyon/typedef/vi_image.hpp>

namespace yq::tachyon {
    class ViDevice;
    
    struct ViRenderTarget {
        ViDevice*       device      = nullptr;
        //ViImagePtr      depthBuffer;
        VkImageView     imageView   = nullptr;
        VkSemaphore     semaphore   = nullptr;
        VkExtent2D      extent      = { 0, 0 };
    };
}

