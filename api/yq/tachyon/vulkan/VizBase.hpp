////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/keywords.hpp>
#include <yq/core/Guarded.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/app/GEnvCreateInfo.hpp>
#include <yq/tachyon/config/vulqan.hpp>
#include <yq/tachyon/typedef/vi_device.hpp>
#include <yq/tachyon/typedef/vi_pipeline.hpp>
#include <yq/tachyon/typedef/vi_pipeline_manager.hpp>
#include <yq/tachyon/typedef/vi_processor.hpp>
#include <yq/tachyon/typedef/vi_queue_id.hpp>
#include <yq/tachyon/typedef/vi_queue_tasker.hpp>
#include <yq/tachyon/vulkan/ViQueueType.hpp>
#include <vulkan/vulkan_core.h>
#include <atomic>

namespace yq::tachyon {
    struct ViContext;
    struct GEnvCreateInfo;
    struct VizBaseCreateInfo;
    class ViSwapchain;


    struct VizTaskerOptions {
        uint64_t        timeout = DEFAULT_WAIT_TIMEOUT;
        uint32_t        queue   = 0;
    };
        
    class VizBase : public UniqueID {
    public:
        static Tristate mix(Tristate spec, Tristate def)
        {
            if(spec != Tristate::Inherit)
                return spec;
            return def;
        }
    
        //! Vulkan instance (convienence function, see the vulkan manager)
        static VkInstance               instance();
        
        struct DrawFunctions {
            std::function<void(ViContext&)>     prerecord;
            std::function<void(ViContext&)>     record;
        };
        
        using depth_spec    = GEnvCreateInfo::depth_spec;
        using queue_spec    = GEnvCreateInfo::queue_spec;
        struct Param {
        
            //! "Clear" color used in rendering (when nothing else is specified)
            RGBA4F              color_clear             = { 0., 0., 0., 1. };  
            VkFormat            color_format            = VK_FORMAT_B8G8R8A8_SRGB;
            VkColorSpaceKHR     color_space             = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
            
            queue_spec          compute;
            uint32_t            compute_processors      = 0;    //!< Number of desired compute processors on init
            uint32_t            compute_qidx            = 0;
            ViQueueID           compute_queue;
            uint32_t            compute_workers         = 1;
            
            depth_spec          depth_buffer;
            ViDevicePtr         device;

            queue_spec          graphics;
            uint32_t            graphics_processors     = 0;    //!< Number of desired graphics processors on init
            uint32_t            graphics_qidx           = 0;
            uint32_t            graphics_workers        = 1;    //!< Number of workers per graphics processor on init
            ViQueueID           graphics_queue;
            
            queue_spec          optical_flow;
            uint32_t            optical_flow_processors = 0;    //!< Number of desired optical flow processors on init
            uint32_t            optical_flow_qidx       = 0;
            ViQueueID           optical_flow_queue;
            uint32_t            optical_flow_workers    = 1;    //!< Number of workers per optical flow processor on init
            
            queue_spec          present;
            uint32_t            present_qidx            = 0;
            ViQueueID           present_queue;
            
            VkSurfaceKHR        surface                 = nullptr;
            
            queue_spec          transfer;
            uint32_t            transfer_qidx           = 0;
            ViQueueID           transfer_queue;
            
            queue_spec          video_decode;
            uint32_t            video_decode_processors = 0;
            uint32_t            video_decode_qidx       = 0;
            ViQueueID           video_decode_queue;
            uint32_t            video_decode_workers    = 1;
            
            queue_spec          video_encode;
            uint32_t            video_encode_processors = 0;
            uint32_t            video_encode_qidx       = 0;
            ViQueueID           video_encode_queue;
            uint32_t            video_encode_workers    = 1;
        };
        
        RGBA4F                          color_clear() const; 
        void                            color_clear(set_k, const RGBA4F&);
        
        VkFormat                        color_format() const { return m_color.format; }
        void                            color_format(set_k, DataFormat);
        void                            color_format(set_k, VkFormat);

        VkColorSpaceKHR                 color_space() const { return m_color.space; }
        void                            color_space(set_k, VkColorSpaceKHR);

        bool                            compute_enabled() const { return m_computeQueue.enable; }

        ViProcessor*                    compute_processor(uint32_t);
        VkQueue                         compute_queue() const;
        ViQueueFamilyID                 compute_queue_family() const { return m_computeQueue.id.family; }
        ViQueueID                       compute_queue_id() const { return m_computeQueue.id; }
        std::error_code                 compute_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            compute_queue_valid() const;

        virtual VkRect2D                def_scissor() const { return {}; }
        virtual VkViewport              def_viewport() const { return {}; }

        bool                            depth_enabled() const { return m_depth.enable; }
        VkFormat                        depth_format() const { return m_depth.format; }

        virtual VkDescriptorPool        descriptor_pool() const = 0;

        //! Vulkan (logical) device
        VkDevice                        device() const;
        
        ViDevice&                       device(ref_k) { return *m_device; }  // temporary hack until we get everybody over....
        ViDevice*                       device(ptr_k) { return m_device.ptr(); }  // temporary hack until we get everybody over....

        Expect<VkFormat>                find_depth_format() const;
        Expect<VkFormat>                find_supported_format(std::span<const VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;
        Expect<VkFormat>                find_supported_format(std::initializer_list<VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;

        bool                            good_base() const { return m_goodBase; }

        bool                            graphics_enabled() const { return m_graphicsQueue.enable; }
        ViProcessor*                    graphics_processor(uint32_t);
        VkQueue                         graphics_queue() const;
        ViQueueFamilyID                 graphics_queue_family() const { return m_graphicsQueue.id.family; }
        ViQueueID                       graphics_queue_id() const { return m_graphicsQueue.id; }
        std::error_code                 graphics_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            graphics_queue_valid() const;

        //! Vulkan logical device
        VkDevice                        logical() const;

        ViProcessor*                    optical_flow_processor(uint32_t);
        bool                            optical_flow_enabled() const { return m_opticalFlowQueue.enable; }
        VkQueue                         optical_flow_queue() const;
        ViQueueFamilyID                 optical_flow_queue_family() const { return m_opticalFlowQueue.id.family; }
        ViQueueID                       optical_flow_queue_id() const { return m_opticalFlowQueue.id; }
        std::error_code                 optical_flow_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            optical_flow_queue_valid() const;

        //! Vulkan physical device (gpu)
        VkPhysicalDevice                physical() const;

        ViPipelineCPtr                  pipeline(uint64_t) const;
        ViPipelineCPtr                  pipeline_create(const Pipeline*);
        void                            pipeline_erase(uint64_t);
        void                            pipeline_erase(const Pipeline*);
        ViPipelineManager*              pipeline_manager() const;
     

        bool                            present_enabled() const { return m_presentQueue.enable; }
        VkQueue                         present_queue() const;
        ViQueueFamilyID                 present_queue_family() const { return m_presentQueue.id.family; }
        ViQueueID                       present_queue_id() const { return m_presentQueue.id; }
        std::error_code                 present_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            present_queue_valid() const;

        std::error_code                 queue_task(ViQueueType, queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        
        
        uint64_t                        tick() const { return m_tick; }

        bool                            transfer_enabled() const { return m_transferQueue.enable; }
        VkQueue                         transfer_queue() const;
        uint32_t                        transfer_queue_count() const;
        ViQueueFamilyID                 transfer_queue_family() const { return m_transferQueue.id.family; }
        ViQueueID                       transfer_queue_id() const { return m_transferQueue.id; }
        std::error_code                 transfer_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        
        //! IF valid, means there's an asynchronous DMA transfer queue
        bool                            transfer_queue_valid() const;

        ViDevice*                       vi_device() { return m_device.ptr(); }
        virtual ViSwapchain*            vi_swapchain() { return nullptr; }
        virtual VkRenderPass            vk_render_pass() const { return nullptr; }

        ViProcessor*                    video_decode_processor(uint32_t);
        bool                            video_decode_enabled() const { return m_videoDecQueue.enable; }
        VkQueue                         video_decode_queue() const;
        ViQueueFamilyID                 video_decode_queue_family() const { return m_videoDecQueue.id.family; }
        ViQueueID                       video_decode_queue_id() const { return m_videoDecQueue.id; }
        std::error_code                 video_decode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_decode_queue_valid() const;

        ViProcessor*                    video_encode_processor(uint32_t);
        bool                            video_encode_enabled() const { return m_videoEncQueue.enable; }
        VkQueue                         video_encode_queue() const;
        ViQueueFamilyID                 video_encode_queue_family() const { return m_videoEncQueue.id.family; }
        ViQueueID                       video_encode_queue_id() const { return m_videoEncQueue.id; }
        std::error_code                 video_encode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_encode_queue_valid() const;

        std::error_code                 wait_idle();

    protected:
        VizBase(const Param&);
        virtual ~VizBase();
        
        struct Queue {
            ViQueueID       id;
            bool            enable  = false;
            //VkQueue         queue   = nullptr;
            
            // true if success or optional or disabled
            bool            init(ViDevice&, ViQueueType, queue_spec, const ViQueueID&, uint32_t);
        };
        
        struct ColorAttachment {
            VkClearValue        clear{};
            VkFormat            format;
            VkColorSpaceKHR     space;
        };
        
        struct DepthAttachment {
            bool            enable  = false;
            VkFormat        format  = VkFormat(0);
        };
        
        ColorAttachment             m_color;
        ViProcessorUPtrVector       m_computeProcs;
        Queue                       m_computeQueue;
        ViDevicePtr                 m_device;
        DepthAttachment             m_depth;
        ViProcessorUPtrVector       m_graphicsProcs;
        Queue                       m_graphicsQueue;
        ViProcessorUPtrVector       m_opticalFlowProcs;
        Queue                       m_opticalFlowQueue;
        ViPipelineManagerUPtr       m_pipelines;
        Queue                       m_presentQueue;
        Queue                       m_transferQueue;
        ViProcessorUPtrVector       m_videoDecProcs;
        Queue                       m_videoDecQueue;
        ViProcessorUPtrVector       m_videoEncProcs;
        Queue                       m_videoEncQueue;

        std::atomic<uint64_t>       m_tick{0ULL};     // Always monotomically incrementing
        
        bool    _init_depth(const Param&);
        bool    _init_queues(const Param&);
        
        bool    _init_processors(ViProcessorUPtrVector&, ViQueueType, uint32_t nprocs, uint32_t nworkers);
        
    private:
        bool                    m_goodBase       = false;
    };
}
