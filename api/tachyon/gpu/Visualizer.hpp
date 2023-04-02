////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>

#include <basic/Guarded.hpp>
#include <math/preamble.hpp>
#include <tachyon/gpu/ViQueues.hpp>

#include <atomic>
#include <map>
#include <set>
#include <string_view>
#include <unordered_map>
#include <vector>

#include <vk_mem_alloc.h>
#include <vulkan/vulkan_core.h>
#include <tbb/spin_rw_mutex.h>

namespace yq {
    namespace tachyon {
    
        struct ViShader {
            VkShaderModule          shader  = nullptr;
            VkShaderStageFlagBits   mask    = {};
        };
        
        template <typename T>
        struct ViHashPlus {
            std::unordered_map<uint64_t, T>     hash;
            std::vector<T>                      loose;  // others that aren't in the hash
            mutable tbb::spin_rw_mutex          mutex;
            
            void    clear()
            {
                hash.clear();
                loose.clear();
            }
        };
    
        //template <typename T>
        //struct ViMap {
            //std::map<uint64_t, T>       map;
            //mutable tbb::spin_rw_mutex  mutex;
            
        //};
    
        /*! \brief the Physical vulkan device adapter
            
            This is about transferreing resources to/from the device, 
            making pipelines, etc.  It's expected to have ONE visualizer
            per viewer/logical vulkan device.
        *//*
            Note, if this needs to be shared, we'll make it ref-counted.
        */
        class Visualizer  {
        public:
        
            //  since this is "stolen", demoted
            GLFWwindow*                     _window() const { return m_window; }
            VmaAllocator                    allocator() const { return m_allocator; }
            VkDevice                        device() const { return m_device; }
            VkDevice                        logical() const { return m_device; }
            VkInstance                      instance() const { return m_instance; }
            VkPhysicalDevice                physical() const { return m_physical; }
        
            RGBA4F                          clear_color() const;

            VkQueue                         compute_queue(uint32_t i=0) const;
            uint32_t                        compute_queue_count() const;
            uint32_t                        compute_queue_family() const;
            bool                            compute_queue_valid() const;

                //! Returns the name of the GPU/physical device
            std::string_view                gpu_name() const;

                //! Returns the type of the GPU/physical device
            VkPhysicalDeviceType            gpu_type() const;
            
            VkQueue                         graphic_queue(uint32_t i=0) const;
            uint32_t                        graphic_queue_count() const;
            uint32_t                        graphic_queue_family() const;
            bool                            graphic_queue_valid() const;

            uint32_t                        max_memory_allocation_count() const;
            uint32_t                        max_push_constants_size() const;
            uint32_t                        max_viewports() const;
            
            PresentMode                     present_mode() const { return m_presentMode; }
            
            const std::set<PresentMode>&    present_modes_available() const { return m_presentModes; }

            VkQueue                         present_queue(uint32_t i=0) const;
            uint32_t                        present_queue_count() const;
            uint32_t                        present_queue_family() const;
            bool                            present_queue_valid() const;

            void                            trigger_rebuild();
            
                //! Sets the background color
            void                            set_clear_color(const RGBA4F&);
            void                            set_present_mode(PresentMode);

            ViShader                        shader(uint64_t) const;
            Expect<ViShader>                shader_create(Ref<const Shader>);

            VkSurfaceKHR                    surface() const { return m_surface; }

            VkSurfaceCapabilitiesKHR        surface_capabilities() const;

            VkColorSpaceKHR                 surface_color_space() const { return m_surfaceColorSpace; }
            VkColorSpaceKHR                 surface_color_space(VkFormat) const;
            VkFormat                        surface_format() const { return m_surfaceFormat; }

            bool                            supports_surface(VkFormat) const;
            bool                            supports_present(PresentMode) const;

            VkQueue                         video_decode_queue(uint32_t i=0) const;
            uint32_t                        video_decode_queue_count() const;
            uint32_t                        video_decode_queue_family() const;
            bool                            video_decode_queue_valid() const;

            VkQueue                         video_encode_queue(uint32_t i=0) const;
            uint32_t                        video_encode_queue_count() const;
            uint32_t                        video_encode_queue_family() const;
            bool                            video_encode_queue_valid() const;

        protected:
            Visualizer();
            ~Visualizer();
        
            std::error_code             init_visualizer(const ViewerCreateInfo&, GLFWwindow*);
            void                        kill_visualizer();
            
        
            std::error_code             _ctor(const ViewerCreateInfo&, GLFWwindow*);
            void                        _dtor();
        
            Visualizer(const Visualizer&) = delete;
            Visualizer(Visualizer&&) = delete;
            Visualizer& operator=(const Visualizer&) = delete;
            Visualizer& operator=(Visualizer&&) = delete;
        
        
            VmaAllocator                        m_allocator             = nullptr;
            VqApp*                              m_app                   = nullptr;
            Guarded<VkClearValue>               m_clearValue;
            ViQueues                            m_compute;
            VkDevice                            m_device                = nullptr;
            VkPhysicalDeviceProperties          m_deviceInfo;
            //std::vector<const char*>            m_extensions;
            ViQueues                            m_graphic;
            VkInstance                          m_instance              = nullptr;
            VkPhysicalDeviceMemoryProperties    m_memoryInfo;
            VkPhysicalDevice                    m_physical              = nullptr;
            ViQueues                            m_present;
            PresentMode                         m_presentMode;
            std::set<PresentMode>               m_presentModes;
            ViHashPlus<ViShader>                m_shaders;
            VkSurfaceKHR                        m_surface               = nullptr;
            std::vector<VkSurfaceFormatKHR>     m_surfaceFormats;
            VkFormat                            m_surfaceFormat;
            VkColorSpaceKHR                     m_surfaceColorSpace;
            ViQueues                            m_videoDecode;
            ViQueues                            m_videoEncode;
            GLFWwindow*                         m_window                = nullptr;
            
            
            std::atomic<bool>                   m_rebuildSwap           = { false };
            bool                                m_init      = false;
            //std::atomic_flag    m_rebuildSwapchain; //  needed for every resize
        

#if 0            
            std::vector<const char*>            m_extensions;
            VkDevice                            m_device                = nullptr;
#endif
            
        };
    
    }
}


