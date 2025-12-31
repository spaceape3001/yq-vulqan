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
#include <tbb/spin_rw_mutex.h>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/tachyon/vulkan/ViQueueType.hpp>
#include <yq/tachyon/typedef/vi_buffer.hpp>
#include <yq/tachyon/typedef/vi_buffer_manager.hpp>
#include <yq/tachyon/typedef/vi_image.hpp>
#include <yq/tachyon/typedef/vi_image_manager.hpp>
#include <yq/tachyon/typedef/vi_queue_id.hpp>
#include <yq/tachyon/typedef/vi_queue_tasker.hpp>
#include <yq/tachyon/typedef/vi_pipeline.hpp>
#include <yq/tachyon/typedef/vi_pipeline_layout.hpp>
#include <yq/tachyon/typedef/vi_pipeline_manager.hpp>
#include <yq/tachyon/typedef/vi_sampler.hpp>
#include <yq/tachyon/typedef/vi_sampler_manager.hpp>
#include <yq/tachyon/typedef/vi_shader.hpp>
#include <yq/tachyon/typedef/vi_shader_manager.hpp>
#include <yq/tachyon/typedef/vi_texture.hpp>
#include <yq/tachyon/typedef/vi_texture_manager.hpp>
#include <map>

namespace yq::tachyon {
    struct VulqanCreateInfo;
    
    /*

        On observation that *NOTHING* in the vkCreateDevice() call relies on 
        surfaces (ie, the windows), the visualizer is going to be split.  
        
        ViDevice will be the vulkan logical device, which is tied to a GPU, 
        likely owned by the VulqanManager.
        
        Visualizer will continue to bind the surface to rendering.
    
    */
    
    class ViDevice : public RefCount {
    public:
    
        /* 
            In order to remove the surface dependency for creating a vulkan logical 
            device, we need to assume that the present queue is available on the 
            graphics queue.  While a generally safe assumption given the current
            GPUs available, it might not be true.  Should we find a card/situation, 
            we'll figure out a way to enumerate that queue family into this list w/o 
            requiring the surface/present-queue-check.
            
            *IF* compute is specified *AND* there is a non-graphics compute queue, 
            it will be used.
            
            *IF* video decode is specifed & found, it'll be used.
            
            *IF* video encode is specifed & found, it'll be used.

            *IF* a transfer queue is found that *ISN'T* graphics, compute, video encode/decode, or optical, 
            that will be used.
            
            Eventually, we'll get the queue stuff spot on, until then, muddle away!
        */

        ViDevice(VkPhysicalDevice, const VulqanCreateInfo&);
        ~ViDevice();

        VmaAllocator                    allocator() const { return m_allocator; }
        
        
        ViBufferCPtr                    buffer(uint64_t) const;
        ViBufferCPtr                    buffer_create(const Buffer&);
        void                            buffer_erase(uint64_t);
        void                            buffer_erase(const Buffer&);
        //ViBufferManager*                buffer_manager() const;

        void                            cleanup(cleanup_fn&&);
        void                            cleanup(sweep_k);
        
        operator VkDevice() const { return m_device; }
        VkDevice                        device() const { return m_device; }
        void                            destroy();

        std::string_view                gpu_name() const;

            //! Returns the type of the GPU/physical device
        VkPhysicalDeviceType            gpu_type() const;
        
        //! Recommended Graphics Queue for tasks that aren't direct-display-related
        ViQueueID                       graphics_queue(headless_k) const { return m_headlessQueue; }
        //! Recommended Graphics Queue for specified viewer
        ViQueueID                       graphics_queue(uint32_t viewerId) const;

        std::error_code                 init(VkPhysicalDevice, const VulqanCreateInfo&);
        
        ViImageCPtr                     image(uint64_t) const;
        ViImageCPtr                     image_create(const Raster&);
        Expect<RasterPtr>               image_export(VkImage, const VkExtent2D&, VkFormat fmt = VK_FORMAT_R8G8B8A8_SRGB);
        Expect<RasterPtr>               image_export(VkImage, const VkExtent3D&, VkFormat fmt = VK_FORMAT_R8G8B8A8_SRGB);
        void                            image_erase(uint64_t);
        void                            image_erase(const Raster&);
        //ViImageManager*                 image_manager() const;

        bool                            has_queue(ViQueueType) const;
        
        bool                            is_queue_compute(ViQueueFamilyID) const;
        bool                            is_queue_graphic(ViQueueFamilyID) const;
        bool                            is_queue_optical(ViQueueFamilyID) const;
        bool                            is_queue_present_supported(ViQueueFamilyID, VkSurfaceKHR) const;
        bool                            is_queue_sparse_binding(ViQueueFamilyID familyIdx) const;
        bool                            is_queue_transfer(ViQueueFamilyID familyIdx) const;
        bool                            is_queue_valid(ViQueueID) const;
        bool                            is_queue_video_decode(ViQueueFamilyID familyIdx) const;
        bool                            is_queue_video_encode(ViQueueFamilyID familyIdx) const;

        uint32_t                        max_memory_allocation_count() const;
        uint32_t                        max_push_constants_size() const;
        float                           max_sampler_anisotropy() const;
        uint32_t                        max_viewports() const;

        //! TRUE if multiple views of the render-pass is enabled
        bool                            multiview_enabled() const;
        
        /*! \brief Maximum index value
        
            KHR's description:
            maxMultiviewInstanceIndex is the maximum valid value of instance index allowed to be generated by a 
            drawing command recorded within a subpass of a multiview render pass instance.            
        */
        uint32_t                        multiview_max_instance_index() const;
        
        /*! Maximumum number of views
        
            KHR's description:
            maxMultiviewViewCount is one greater than the maximum view index that can be used in a subpass.
        */
        uint32_t                        multiview_max_view_count() const;

        VkPhysicalDevice                physical() const { return m_physical; }
        
        ViPipelineLayoutCPtr            pipeline_layout(uint64_t) const;
        ViPipelineLayoutCPtr            pipeline_layout_create(const Pipeline*);
        void                            pipeline_layout_erase(uint64_t);
        void                            pipeline_layout_erase(const Pipeline*);
        //ViPipelineLayoutManager*        pipeline_layout_manager() const;

        VkQueue                         queue(const ViQueueID&) const;
        VkQueue                         queue(ViQueueFamilyID familyIdx, uint32_t subIdx) const;
        VkQueue                         queue(ViQueueType) const;
        VkQueue                         queue(ViQueueType, ThreadID) const;
        VkQueue                         queue(ViQueueFamilyID) const;
        VkQueue                         queue(ViQueueFamilyID, ThreadID) const;

        uint32_t                        queue_count(ViQueueFamilyID familyIdx) const;

        uint32_t                        queue_family_count() const;
        VkQueueFlags                    queue_family_flags(ViQueueFamilyID familyIdx) const;
        
        //! Queue family for type (note, UINT32_MAX is invalid)
        ViQueueFamilyID                 queue_family(ViQueueType) const;
        
        ViQueueID                       queue_id(ViQueueFamilyID) const;
        ViQueueID                       queue_id(ViQueueFamilyID, ThreadID) const;
        ViQueueID                       queue_id(ViQueueType) const;
        ViQueueID                       queue_id(ViQueueType, ThreadID) const;
        
        std::error_code                 queue_task(ViQueueID, queue_tasker_fn&&);
        std::error_code                 queue_task(ViQueueID, uint64_t timeout, queue_tasker_fn&&);
        std::error_code                 queue_task(ViQueueFamilyID, queue_tasker_fn&&);
        std::error_code                 queue_task(ViQueueFamilyID, uint64_t timeout, queue_tasker_fn&&);
        std::error_code                 queue_task(ViQueueType, queue_tasker_fn&&);
        std::error_code                 queue_task(ViQueueType, uint64_t timeout, queue_tasker_fn&&);
        ViQueueTaskerPtr                queue_tasker(ViQueueID);
        
        ViSamplerCPtr                   sampler(uint64_t) const;
        ViSamplerCPtr                   sampler_create(const Sampler&);
        void                            sampler_erase(uint64_t);
        void                            sampler_erase(const Sampler&);
        //ViSamplerManager*               sampler_manager() const;

        //! Finds the shader
        ViShaderCPtr                    shader(uint64_t) const;

        /*! Creates the shader
        
            This imports the shader onto the GPU device.  
            
            \note Once imported, this shader cannot be removed and will persist 
            to the end of the visualizer's lifespan.
        */
        ViShaderCPtr                    shader_create(const Shader&);

        void                            shader_erase(uint64_t);
        void                            shader_erase(const Shader&);

        //! Current shader manager (null if not initialized)
        //ViShaderManager*                shader_manager() const;
        
        ViTextureCPtr                   texture(uint64_t) const;
        ViTextureCPtr                   texture_create(const Texture&);
        void                            texture_erase(uint64_t);
        void                            texture_erase(const Texture&);
        //ViTextureManager*               texture_manager() const;
        
        bool                            valid() const;
        std::error_code                 wait_idle() const;
        
    private:
        struct QueueFamily;
    
        using mutex_t   = tbb::spin_rw_mutex;
        using lock_t    = mutex_t::scoped_lock;
    
        VmaAllocator                            m_allocator                 = nullptr;
        ViBufferManagerUPtr                     m_buffers;
        Cleanup                                 m_cleanup;
        VkDevice                                m_device                    = nullptr;
        VkPhysicalDeviceFeatures                m_gpuFeatures;
        VkPhysicalDeviceMemoryProperties        m_gpuMemory;
        std::string                             m_gpuName;
        VkPhysicalDeviceProperties              m_gpuProperties;
        ViQueueID                               m_headlessQueue;
        ViImageManagerUPtr                      m_images;
        VkPhysicalDevice                        m_physical                  = nullptr;
        ViPipelineLayoutManagerUPtr             m_pipelineLayouts;
        std::vector<QueueFamily>                m_queueFamilies;
        mutable mutex_t                         m_queueMutex;
        std::map<ViQueueType,ViQueueFamilyID>   m_queueType2Family;
        ViSamplerManagerUPtr                    m_samplers;
        ViShaderManagerUPtr                     m_shaders;
        std::map<ViQueueID, ViQueueTaskerPtr>   m_taskers;
        mutable mutex_t                         m_taskerMutex;
        ViTextureManagerUPtr                    m_textures;

        struct {
            bool        enabled             = false;
            // KHR -- One greater than the maximum view index that can be used in a subpass.
            uint32_t    maxViewCount        = 0;
            // KHR -- maximum valid value of instance index allowed to be generated by a drawing command recorded within a subpass of a multiview render pass instance.
            uint32_t    maxInstanceIndex    = 0;
        }                                   m_multiview;
        
        const QueueFamily*  _family(ViQueueFamilyID) const;
        QueueFamily*        _family(ViQueueFamilyID);
        
        
        // NOTE -- present queue will remain in the visualizer as that's surface dependent... the rest are not
        
        void                _kill();
        std::error_code     _init(VkPhysicalDevice, const VulqanCreateInfo&);
    };
}

