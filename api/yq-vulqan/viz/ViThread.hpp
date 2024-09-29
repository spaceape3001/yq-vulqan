////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Ref.hpp>
#include <yq-vulqan/typedef/thread.hpp>
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
