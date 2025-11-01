////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/Flags.hpp>
#include <tachyon/config/vulqan.hpp>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {

    class ViVisualizer;

    //  ViFrame will get the cleanup manager
    
    /*! \brief Target image
    
        A frame is intended to hit a target image (either swap or offscreen); 
        the swapchain will hold a vector of these.
    */
    class ViFrame : public RefCount {
    public:
    
        /*
            This'd be one image/frame target.... maybe the semaphore/fences are internal?
            
            Visualizer split into two... one for swapchain, the other for graphics?
            
        */
    
    private:
        enum class F {
            OwnsImage,
            Swap
        };
        
        Flags<F>        m_flags     = {};
        VkImage         m_image     = nullptr;
        VkImageView     m_view      = nullptr;
        VkFramebuffer   m_fb        = nullptr;
    };
    
    class ViSyncObject {
    public:
    
    private:
        ViVisualizer*       m_viz               = nullptr;
    };
}
