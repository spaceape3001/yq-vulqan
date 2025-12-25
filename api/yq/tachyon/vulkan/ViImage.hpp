////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/shape/Size4.hpp>
#include <yq/typedef/size4.hpp>
#include <yq/tachyon/asset/RasterInfo.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <vk_mem_alloc.h>
#include <vulkan/vulkan_core.h>
#include <system_error>
#include <span>

namespace yq::tachyon {
    class ViDevice;
    class ViDevice;

    class ViImage : public RefCount {
    public:
    
        struct Param {
            VkImageLayout           layout  = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
            VkImageUsageFlags       usage   = VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
            VmaMemoryUsage          memory  = VMA_MEMORY_USAGE_GPU_ONLY;
            VkAccessFlags           access  = VK_ACCESS_SHADER_READ_BIT;    // only good on importing/uploading, not raw
            VkPipelineStageFlagBits stages  = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
            VkImageAspectFlags      aspect  = VK_IMAGE_ASPECT_COLOR_BIT;
            VkImageCreateFlags      flags   = 0;
            
            Param(){}
            ~Param(){}
        };
    
        static size_t       format_bytes(VkFormat);
    
        ViImage(ViDevice&, const Raster&, const Param& p = Param());
        ViImage(ViDevice&, std::span<const RasterCPtr>, const Param& p = Param());
        
        //! Creates temporary (that isn't ID'd), can be written to
        ViImage(ViDevice&, const RasterInfo&, const Param& p = Param());
        ~ViImage();
        
        bool                valid() const;
        
        operator VkImage() const { return m_image; }
        VkImage             image() const { return m_image; }
        VkImage             vk_image() const { return m_image; }
        VkImageLayout       vk_image_layout() const { return m_layout; }
        VmaAllocation       allocation() const { return m_allocation; }
        const RasterInfo&   info() const { return m_info; }
        
        struct Respec {
            VkAccessFlags           access  = 0;
            VkImageLayout           layout  = VK_IMAGE_LAYOUT_UNDEFINED;
            uint32_t                queue   = UINT32_MAX;
            VkPipelineStageFlags    stages  = 0;
        };
    
        void  barrier(VkCommandBuffer, const Respec&);
        void  barrier(VkCommandBuffer, VkPipelineStageFlags, const Respec&);
        
    
    private:
        ViDevice&           m_device;
        VmaAllocation       m_allocation    = nullptr;
        VkImage             m_image         = nullptr;
        RasterInfo          m_info          = {};
        uint64_t            m_id            = 0;
        
        //  ownership/state
        VkImageLayout           m_layout        = VK_IMAGE_LAYOUT_UNDEFINED;
        VkAccessFlags           m_access        = 0;
        VkPipelineStageFlags    m_stages        = VK_PIPELINE_STAGE_HOST_BIT;
        uint32_t                m_queue         = 0;
        uint32_t                m_layers        = 1;
        uint32_t                m_mips          = 1;
        VkImageAspectFlags      m_aspect        = VK_IMAGE_ASPECT_COLOR_BIT;
        
        ViImage(const ViImage&) = delete;
        ViImage(ViImage&&) = delete;
        ViImage& operator=(const ViImage&) = delete;
        ViImage& operator=(ViImage&&) = delete;
        
        std::error_code _init(const Raster&, const Param&);
        std::error_code _init(const std::span<const RasterCPtr>&, const Param&);
        std::error_code _init(const RasterInfo&, const Param&);
        void            _wipe();
        void            _kill();
    };

    struct ViImageExport {
        VkImageType     type        = {};
        VkImageLayout   src_layout  = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        VkFormat        format      = VK_FORMAT_UNDEFINED;
        VkFormat        desired     = VK_FORMAT_UNDEFINED;
        VkExtent3D      extent      = {};
    };
    
    Expect<RasterPtr>   export_image(ViDevice&, VkImage, const ViImageExport& vix);
}
