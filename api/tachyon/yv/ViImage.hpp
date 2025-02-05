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
    
        static size_t       format_bytes(VkFormat);
    
        ViImage();
        ViImage(ViVisualizer&, const Raster&);
        ViImage(ViVisualizer&, std::span<const RasterCPtr>);
        
        //! Creates temporary (that isn't ID'd), can be written to
        ViImage(ViVisualizer&, const RasterInfo&, VkImageUsageFlags flags={});
        ~ViImage();
        
        std::error_code     init(ViVisualizer&, const Raster&);
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
        
        std::error_code _init(ViVisualizer&, const Raster&);
        std::error_code _init(ViVisualizer&, const std::span<const RasterCPtr>&);
        std::error_code _init(ViVisualizer&, const RasterInfo&, VkImageUsageFlags flags);
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
