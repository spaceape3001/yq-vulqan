////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/Cleanup.hpp>
#include <vulkan/vulkan_core.h>
#include <vk_mem_alloc.h>

namespace yq::tachyon {
    /*

        On observation that *NOTHING* in the vkCreateDevice() call relies on 
        surfaces (ie, the windows), the visualizer is going to be split.  
        
        ViDevice will be the vulkan logical device, which is tied to a GPU, 
        likely owned by the VulqanManager.
        
        Visualizer will continue to bind the surface to rendering.
    
    */
    
    class ViDevice : public RefCount {
    public:
        /* TBD */
        
        ViDevice(VkDevice);
        ~ViDevice();
        
        void        cleanup();
        
    private:
        VkDevice            m_device;
        VmaAllocator        m_allocator         = nullptr;
        Cleanup             m_cleanup;
        
        void    _kill();
    };
}

