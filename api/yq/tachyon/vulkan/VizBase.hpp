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
#include <yq/tachyon/vulkan/ViDescriptorPool.hpp>
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
            //uint32_t            compute_processors      = 0;    //!< Number of desired compute processors on init
            uint32_t            compute_qidx            = 0;
            ViQueueID           compute_queue;
            //uint32_t            compute_workers         = 1;
            
            depth_spec          depth_buffer;
            uint32_t            descriptors             = 0;

            queue_spec          graphics;
            //uint32_t            graphics_processors     = 0;    //!< Number of desired graphics processors on init
            uint32_t            graphics_qidx           = 0;
            ViQueueID           graphics_queue;
            //uint32_t            graphics_workers        = 1;    //!< Number of workers per graphics processor on init
            
            queue_spec          optical_flow;
            //uint32_t            optical_flow_processors = 0;    //!< Number of desired optical flow processors on init
            uint32_t            optical_flow_qidx       = 0;
            ViQueueID           optical_flow_queue;
            //uint32_t            optical_flow_workers    = 1;    //!< Number of workers per optical flow processor on init
            
            queue_spec          present;
            uint32_t            present_qidx            = 0;
            ViQueueID           present_queue;
            
            VkSurfaceKHR        surface                 = nullptr;
            
            queue_spec          transfer;
            uint32_t            transfer_qidx           = 0;
            ViQueueID           transfer_queue;
            
            queue_spec          video_decode;
            //uint32_t            video_decode_processors = 0;
            uint32_t            video_decode_qidx       = 0;
            ViQueueID           video_decode_queue;
            //uint32_t            video_decode_workers    = 1;
            
            queue_spec          video_encode;
            //uint32_t            video_encode_processors = 0;
            uint32_t            video_encode_qidx       = 0;
            ViQueueID           video_encode_queue;
            //uint32_t            video_encode_workers    = 1;
        };
        
        RGBA4F                          color_clear() const; 
        void                            color_clear(set_k, const RGBA4F&);
        
        VkClearValue                    color_clear_vk() const { return m_color.clear; }                    
        
        VkFormat                        color_format() const { return m_color.format; }
        void                            color_format(set_k, DataFormat);
        void                            color_format(set_k, VkFormat);

        VkColorSpaceKHR                 color_space() const { return m_color.space; }
        void                            color_space(set_k, VkColorSpaceKHR);

        bool                            compute_enabled() const { return m_compute.enable; }
        ViProcessor*                    compute_processor(uint32_t);
        uint32_t                        compute_processor(count_k) const;
        bool                            compute_processor_expand(uint32_t);
        VkQueue                         compute_queue() const;
        ViQueueFamilyID                 compute_queue_family() const { return m_compute.id.family; }
        ViQueueID                       compute_queue_id() const { return m_compute.id; }
        std::error_code                 compute_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            compute_queue_valid() const;

        virtual VkRect2D                def_scissor() const { return {}; }
        virtual VkViewport              def_viewport() const { return {}; }

        bool                            depth_enabled() const { return m_depth.enable; }
        VkFormat                        depth_format() const { return m_depth.format; }
        
        uint32_t                        descriptor_count() const { return m_descriptorPool.count(); }

        ViDevice&                       device() { return *m_device; }
        const ViDevice&                 device() const { return *m_device; }


        //! Vulkan (logical) device
        //VkDevice                        device() const;
        //ViDevice&                       device(ref_k) { return *m_device; }  // temporary hack until we get everybody over....
        //ViDevice*                       device(ptr_k) { return m_device.ptr(); }  // temporary hack until we get everybody over....

        Expect<VkFormat>                find_depth_format() const;
        Expect<VkFormat>                find_supported_format(std::span<const VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;
        Expect<VkFormat>                find_supported_format(std::initializer_list<VkFormat>, VkImageTiling, VkFormatFeatureFlags) const;

        bool                            good() const { return m_good; }

        bool                            graphics_enabled() const { return m_graphics.enable; }
        ViProcessor*                    graphics_processor(uint32_t);
        uint32_t                        graphics_processor(count_k) const;
        bool                            graphics_processor_expand(uint32_t);
        VkQueue                         graphics_queue() const;
        ViQueueFamilyID                 graphics_queue_family() const { return m_graphics.id.family; }
        ViQueueID                       graphics_queue_id() const { return m_graphics.id; }
        std::error_code                 graphics_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            graphics_queue_valid() const;

        //! Vulkan logical device
        VkDevice                        logical() const { return vk_device(); }

        bool                            optical_flow_enabled() const { return m_opticalFlow.enable; }
        ViProcessor*                    optical_flow_processor(uint32_t);
        uint32_t                        optical_flow_processor(count_k) const;
        VkQueue                         optical_flow_queue() const;
        ViQueueFamilyID                 optical_flow_queue_family() const { return m_opticalFlow.id.family; }
        ViQueueID                       optical_flow_queue_id() const { return m_opticalFlow.id; }
        std::error_code                 optical_flow_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            optical_flow_queue_valid() const;

        //! Vulkan physical device (gpu)
        VkPhysicalDevice                physical() const { return vk_physical_device(); }

        ViPipelineCPtr                  pipeline(uint64_t) const;
        ViPipelineCPtr                  pipeline_create(const Pipeline*);
        void                            pipeline_erase(uint64_t);
        void                            pipeline_erase(const Pipeline*);
        ViPipelineManager*              pipeline_manager() const;
     

        bool                            present_enabled() const { return m_present.enable; }
        VkQueue                         present_queue() const;
        ViQueueFamilyID                 present_queue_family() const { return m_present.id.family; }
        ViQueueID                       present_queue_id() const { return m_present.id; }
        std::error_code                 present_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            present_queue_valid() const;

        std::error_code                 queue_task(ViQueueType, queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        
        
        uint64_t                        tick() const { return m_tick; }

        bool                            transfer_enabled() const { return m_transfer.enable; }
        VkQueue                         transfer_queue() const;
        uint32_t                        transfer_queue_count() const;
        ViQueueFamilyID                 transfer_queue_family() const { return m_transfer.id.family; }
        ViQueueID                       transfer_queue_id() const { return m_transfer.id; }
        std::error_code                 transfer_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        
        //! IF valid, means there's an asynchronous DMA transfer queue
        bool                            transfer_queue_valid() const;

        ViDevice*                       vi_device() { return m_device.ptr(); }
        const ViDevice*                 vi_device() const { return m_device.ptr(); }
        virtual ViSwapchain*            vi_swapchain() { return nullptr; }

        VkDescriptorPool                vk_descriptor_pool() const { return m_descriptorPool.descriptor_pool(); }
        VkDevice                        vk_device() const;
        VkPhysicalDevice                vk_physical_device() const;
        virtual VkRenderPass            vk_render_pass() const { return nullptr; }

        bool                            video_decode_enabled() const { return m_videoDec.enable; }
        ViProcessor*                    video_decode_processor(uint32_t);
        uint32_t                        video_decode_processor(count_k) const;
        VkQueue                         video_decode_queue() const;
        ViQueueFamilyID                 video_decode_queue_family() const { return m_videoDec.id.family; }
        ViQueueID                       video_decode_queue_id() const { return m_videoDec.id; }
        std::error_code                 video_decode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_decode_queue_valid() const;

        bool                            video_encode_enabled() const { return m_videoEnc.enable; }
        ViProcessor*                    video_encode_processor(uint32_t);
        uint32_t                        video_encode_processor(count_k) const;
        VkQueue                         video_encode_queue() const;
        ViQueueFamilyID                 video_encode_queue_family() const { return m_videoEnc.id.family; }
        ViQueueID                       video_encode_queue_id() const { return m_videoEnc.id; }
        std::error_code                 video_encode_queue_task(queue_tasker_fn&&, const VizTaskerOptions& opts=VizTaskerOptions());
        bool                            video_encode_queue_valid() const;

        std::error_code                 wait_idle();

    protected:
        VizBase(ViDevice&, const Param&);
        virtual ~VizBase();
        
        using processor_create_t    = std::function<ViProcessorUPtr()>;
        
        void    compute_processor_factory(set_k, processor_create_t&&);
        void    graphics_processor_factory(set_k, processor_create_t&&);
        void    optical_flow_processor_factory(set_k, processor_create_t&&);
        void    video_decode_processor_factory(set_k, processor_create_t&&);
        void    video_encode_processor_factory(set_k, processor_create_t&&);


        void    set_bad() { m_good = false; }
        void    set_good() { m_good = true; }

        std::atomic<uint64_t>       m_tick{0ULL};     // Always monotomically incrementing

    private:

        struct basic_t {
            bool        enable  = false;
        };
        
        struct queue_t : public basic_t {
            ViQueueID       id;
            ViQueueType     type;
            
            queue_t(ViQueueType);

            // true if success or optional or disabled
            bool        qInit(ViDevice&, queue_spec, const ViQueueID&, uint32_t);
        };
        
        struct processing_t : public queue_t {
            processor_create_t          factory;
            ViProcessorUPtrVector       procs;
            
            ViProcessor*    proc(uint32_t) const;
            
            processing_t(ViQueueType);
            ~processing_t();
            
            void        pInit(VizBase*);
            bool        pExpand(uint32_t);
            
            void reset();
        };
        
        
        struct compute_t : public processing_t {
            compute_t();
        };
        
        struct graphics_t : public processing_t {
            graphics_t();
        };
        
        struct optical_flow_t : public processing_t {
            optical_flow_t();
        };
        
        struct present_t : public queue_t {
            present_t();
        };
        
        struct transfer_t : public queue_t {
            transfer_t();
        };
        
        struct video_t : public processing_t {
            video_t(ViQueueType);
        };
        
        struct video_decode_t : public video_t {
            video_decode_t();
        };
        
        struct video_encode_t : public video_t {
            video_encode_t();
        };
        
        struct color_t {
            VkClearValue        clear{};
            VkFormat            format;
            VkColorSpaceKHR     space;
        };
        
        struct depth_t : public basic_t {
            bool                enable  = false;
            VkFormat            format  = VkFormat(0);
        };
        
        ViDevicePtr                 m_device;
        
        color_t                     m_color;
        compute_t                   m_compute;
        depth_t                     m_depth;
        ViDescriptorPool            m_descriptorPool;
        graphics_t                  m_graphics;
        optical_flow_t              m_opticalFlow;
        ViPipelineManagerUPtr       m_pipelines;
        present_t                   m_present;
        transfer_t                  m_transfer;
        video_decode_t              m_videoDec;
        video_encode_t              m_videoEnc;
        bool                        m_good       = false;
        
        bool    _init_depth(const Param&);
        bool    _init_queues(const Param&);
        
        // note, it'll be up to subclasses to create the processors
        //bool    _init_processors(ViProcessorUPtrVector&, ViQueueType, uint32_t nprocs, uint32_t nworkers);

        static void set_id(ViProcessor&, uint32_t);
    };
}
