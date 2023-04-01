////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>

#include <vulkan/vulkan_core.h>
#include <set>
#include <vector>

namespace yq {
    namespace tachyon {
    
    
        /*! \brief the Physical vulkan device adapter
            
            This is about transferreing resources to/from the device, 
            making pipelines, etc.  It's expected to have ONE visualizer
            per viewer/logical vulkan device.
        *//*
            Note, if this needs to be shared, we'll make it ref-counted.
        */
        class Visualizer  {
        protected:
            Visualizer();
            ~Visualizer();
        
            std::error_code             init_visualizer(const ViewerCreateInfo&, GLFWwindow*);
            void                        kill_visualizer();
        
        private:
        
            Visualizer(const Visualizer&) = delete;
            Visualizer(Visualizer&&) = delete;
            Visualizer& operator=(const Visualizer&) = delete;
            Visualizer& operator=(Visualizer&&) = delete;
        
        
            GLFWwindow*         m_window    = nullptr;
            bool                m_init      = false;
        

#if 0            
            //! Vulkan instance (from vulkan)
            VkInstance                          m_instance              = nullptr;
            
            //! Physical Device
            VkPhysicalDevice                    m_physicalDevice        = nullptr;
            VkPhysicalDeviceProperties          m_deviceInfo;
            VkPhysicalDeviceMemoryProperties    m_memoryInfo;
            VkSurfaceKHR                        m_surface               = nullptr;
            std::set<PresentMode>               m_presentModes;
            std::vector<VkSurfaceFormatKHR>     m_surfaceFormats;
            VkFormat                            m_surfaceFormat;
            VkColorSpaceKHR                     m_surfaceColorSpace;
            std::vector<const char*>            m_extensions;
            VkDevice                            m_device                = nullptr;
#endif
            
        };
    
    }
}


