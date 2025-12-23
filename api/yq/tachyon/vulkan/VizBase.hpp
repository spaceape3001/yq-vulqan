////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <functional>
#include <yq/keywords.hpp>
#include <yq/core/Guarded.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/app/GEnvCreateInfo.hpp>
#include <yq/tachyon/config/vulqan.hpp>
#include <yq/tachyon/typedef/vi_device.hpp>
#include <yq/tachyon/typedef/vi_queue_id.hpp>
#include <yq/tachyon/typedef/vi_queue_tasker.hpp>
#include <yq/tachyon/vulkan/ViQueueType.hpp>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
    struct ViContext;
    struct GEnvCreateInfo;
    struct VizBaseCreateInfo;


    struct VizTaskerOptions {
        uint64_t        timeout = DEFAULT_WAIT_TIMEOUT;
        uint32_t        queue   = 0;
    };
        
    class VizBase {
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
            RGBA4F          clear_color   = { 0., 0., 0., 1. };
            queue_spec      compute;
            uint32_t        compute_number      = 0;
            ViQueueID       compute_queue;
            depth_spec      depth_buffer;
            ViDevicePtr     device;
            queue_spec      graphics;
            uint32_t        graphics_number     = 0;
            ViQueueID       graphics_queue;
            
            queue_spec      optical_flow;
            uint32_t        optical_flow_number = 0;
            ViQueueID       optical_flow_queue;
            
            queue_spec      present;
            uint32_t        present_number      = 0;
            ViQueueID       present_queue;
            VkSurfaceKHR    surface             = nullptr;
            queue_spec      transfer;
            uint32_t        transfer_number     = 0;
            ViQueueID       transfer_queue;
            queue_spec      video_decode;
            uint32_t        video_decode_number = 0;
            ViQueueID       video_decode_queue;
            queue_spec      video_encode;
            uint32_t        video_encode_number = 0;
            ViQueueID       video_encode_queue;
        };
        
        RGBA4F                          clear_color() const;    // TBH... likely deprecated

        bool                            compute_enabled() const { return m_computeQueue.enable; }

        VkQueue                         compute_queue() const;
        ViQueueFamilyID                 compute_queue_family() const { return m_computeQueue.id.family; }
        ViQueueID                       compute_queue_id() const { return m_computeQueue.id; }
        std::error_code                 compute_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            compute_queue_valid() const;

        bool                            depth_buffer_enabled() const { return m_depthBuffer.enable; }
        VkFormat                        depth_buffer_format() const { return m_depthBuffer.format; }

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
        VkQueue                         graphics_queue() const;
        ViQueueFamilyID                 graphics_queue_family() const { return m_graphicsQueue.id.family; }
        ViQueueID                       graphics_queue_id() const { return m_graphicsQueue.id; }
        std::error_code                 graphics_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            graphics_queue_valid() const;

        //! Vulkan logical device
        VkDevice                        logical() const;

        bool                            optical_flow_enabled() const { return m_opticalFlowQueue.enable; }
        VkQueue                         optical_flow_queue() const;
        ViQueueFamilyID                 optical_flow_queue_family() const { return m_opticalFlowQueue.id.family; }
        ViQueueID                       optical_flow_queue_id() const { return m_opticalFlowQueue.id; }
        std::error_code                 optical_flow_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            optical_flow_queue_valid() const;

        //! Vulkan physical device (gpu)
        VkPhysicalDevice                physical() const;

        bool                            present_enabled() const { return m_presentQueue.enable; }
        VkQueue                         present_queue() const;
        ViQueueFamilyID                 present_queue_family() const { return m_presentQueue.id.family; }
        ViQueueID                       present_queue_id() const { return m_presentQueue.id; }
        std::error_code                 present_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            present_queue_valid() const;

        std::error_code                 queue_task(ViQueueType, queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        
                    //! Sets the background color
        void                            set_clear_color(const RGBA4F&);

        bool                            transfer_enabled() const { return m_transferQueue.enable; }
        VkQueue                         transfer_queue() const;
        uint32_t                        transfer_queue_count() const;
        ViQueueFamilyID                 transfer_queue_family() const { return m_transferQueue.id.family; }
        ViQueueID                       transfer_queue_id() const { return m_transferQueue.id; }
        std::error_code                 transfer_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        
        //! IF valid, means there's an asynchronous DMA transfer queue
        bool                            transfer_queue_valid() const;

        bool                            video_decode_enabled() const { return m_videoDecQueue.enable; }
        VkQueue                         video_decode_queue() const;
        ViQueueFamilyID                 video_decode_queue_family() const { return m_videoDecQueue.id.family; }
        ViQueueID                       video_decode_queue_id() const { return m_videoDecQueue.id; }
        std::error_code                 video_decode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_decode_queue_valid() const;

        bool                            video_encode_enabled() const { return m_videoEncQueue.enable; }
        VkQueue                         video_encode_queue() const;
        ViQueueFamilyID                 video_encode_queue_family() const { return m_videoEncQueue.id.family; }
        ViQueueID                       video_encode_queue_id() const { return m_videoEncQueue.id; }
        std::error_code                 video_encode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_encode_queue_valid() const;

        std::error_code                 wait_idle();

    protected:
        VizBase(const Param& p);
        virtual ~VizBase();
        
        struct Queue {
            ViQueueID       id;
            bool            enable  = false;
            //VkQueue         queue   = nullptr;
            
            // true if success or optional or disabled
            bool            init(ViDevice&, ViQueueType, queue_spec, const ViQueueID&, uint32_t);
        };
        
        struct DepthBuffer {
            bool            enable  = false;
            VkFormat        format  = VkFormat(0);
        };
        
        Guarded<VkClearValue>   m_clearValue;
        Queue                   m_computeQueue;
        ViDevicePtr             m_device;
        DepthBuffer             m_depthBuffer;
        Queue                   m_graphicsQueue;
        Queue                   m_opticalFlowQueue;
        Queue                   m_presentQueue;
        Queue                   m_transferQueue;
        Queue                   m_videoDecQueue;
        Queue                   m_videoEncQueue;
        
        bool    _init_depth(const Param&);
        bool    _init_queues(const Param&);

    private:
        bool                    m_goodBase       = false;
    };
}
