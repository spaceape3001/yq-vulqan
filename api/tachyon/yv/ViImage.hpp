////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/shape/Size4.hpp>
#include <yq/typedef/size4.hpp>
#include <yt/gfx/RasterInfo.hpp>
#include <yt/typedef/raster.hpp>
#include <vk_mem_alloc.h>
#include <vulkan/vulkan_core.h>
#include <system_error>
#include <span>

namespace yq::tachyon {
    class ViVisualizer;

    class ViImage : public RefCount {
    public:
    
        struct Param {
            VkImageLayout           layout  = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
            VkImageUsageFlags       usage   = VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
            VmaMemoryUsage          memory  = VMA_MEMORY_USAGE_GPU_ONLY;
            VkAccessFlags           access  = VK_ACCESS_SHADER_READ_BIT;
            VkPipelineStageFlagBits stages  = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
            VkImageAspectFlags      aspect  = VK_IMAGE_ASPECT_COLOR_BIT;
            VkImageCreateFlags      flags   = 0;
            
            Param(){}
            ~Param(){}
        };
    
        static size_t       format_bytes(VkFormat);
    
        ViImage();
        ViImage(ViVisualizer&, const Raster&, const Param& p = Param());
        ViImage(ViVisualizer&, std::span<const RasterCPtr>, const Param& p = Param());
        
        //! Creates temporary (that isn't ID'd), can be written to
        ViImage(ViVisualizer&, const RasterInfo&, const Param& p = Param());
        ~ViImage();
        
        std::error_code     init(ViVisualizer&, const Raster&, const Param& p = Param());
        void                kill();
        
        bool                consistent() const;
        bool                valid() const;
        
        operator VkImage() const { return m_image; }
        VkImage             image() const { return m_image; }
        VmaAllocation       allocation() const { return m_allocation; }
        ViVisualizer*       visualizer() const { return m_viz; }
        const RasterInfo&   info() const { return m_info; }
    
    private:
        ViVisualizer*       m_viz           = nullptr;
        VmaAllocation       m_allocation    = nullptr;
        VkImage             m_image         = nullptr;
        RasterInfo          m_info          = {};
        uint64_t            m_id            = 0;
        
        ViImage(const ViImage&) = delete;
        ViImage(ViImage&&) = delete;
        ViImage& operator=(const ViImage&) = delete;
        ViImage& operator=(ViImage&&) = delete;
        
        std::error_code _init(ViVisualizer&, const Raster&, const Param&);
        std::error_code _init(ViVisualizer&, const std::span<const RasterCPtr>&, const Param&);
        std::error_code _init(ViVisualizer&, const RasterInfo&, const Param&);
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
    
    Expect<RasterPtr>   export_image(ViVisualizer&, VkImage, const ViImageExport& vix);
}
