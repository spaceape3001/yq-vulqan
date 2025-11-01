////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/tachyon/typedef/vi_thread.hpp>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {

    class ViVisualizer;

    class ViThread : public RefCount {
    public:
    
    private:
        ViVisualizer*           m_viz   = nullptr;
        VkDescriptorPool        m_pool  = nullptr;
    };
}
