////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/shape/Size4.hpp>
#include <yq/typedef/size4.hpp>
#include <yq/tachyon/asset/GriddedDataInfo.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <vk_mem_alloc.h>
#include <vulkan/vulkan_core.h>
#include <system_error>
#include <span>

namespace yq::tachyon {
    class ViDevice;

    // Gridded data, treated as an image within the vulkan engine
    class ViGridded : public RefCount {
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
    
        ViGridded();
        ViGridded(ViDevice&, const GriddedData&, const Param& p = Param());
        ViGridded(ViDevice&, std::span<const GriddedDataCPtr>, const Param& p = Param());
        
        //! Creates temporary (that isn't ID'd), can be written to
        ViGridded(ViDevice&, const GriddedDataInfo&, const Param& p = Param());
        ~ViGridded();
        
        std::error_code     init(ViDevice&, const GriddedData&, const Param& p = Param());
        void                kill();
        
        bool                consistent() const;
        bool                valid() const;
        
        operator VkImage() const { return m_image; }
        VkImage             image() const { return m_image; }
        VmaAllocation       allocation() const { return m_allocation; }
        const GriddedDataInfo&   info() const { return m_info; }
        
        struct Respec {
            VkAccessFlags           access  = 0;
            VkImageLayout           layout  = VK_IMAGE_LAYOUT_UNDEFINED;
            uint32_t                queue   = UINT32_MAX;
            VkPipelineStageFlags    stages  = 0;
        };
    
        void  barrier(VkCommandBuffer, const Respec&);
    
    private:
        ViDevice*           m_device        = nullptr;
        VmaAllocation       m_allocation    = nullptr;
        VkImage             m_image         = nullptr;
        GriddedDataInfo          m_info          = {};
        uint64_t            m_id            = 0;
        
        //  ownership/state
        VkImageLayout           m_layout        = VK_IMAGE_LAYOUT_UNDEFINED;
        VkAccessFlags           m_access        = 0;
        VkPipelineStageFlags    m_stages        = VK_PIPELINE_STAGE_HOST_BIT;
        uint32_t                m_queue         = 0;
        uint32_t                m_layers        = 1;
        uint32_t                m_mips          = 1;
        VkImageAspectFlags      m_aspect        = VK_IMAGE_ASPECT_COLOR_BIT;
        
        ViGridded(const ViGridded&) = delete;
        ViGridded(ViGridded&&) = delete;
        ViGridded& operator=(const ViGridded&) = delete;
        ViGridded& operator=(ViGridded&&) = delete;
        
        std::error_code _init(ViDevice&, const GriddedData&, const Param&);
        std::error_code _init(ViDevice&, const std::span<const GriddedDataCPtr>&, const Param&);
        std::error_code _init(ViDevice&, const GriddedDataInfo&, const Param&);
        void            _wipe();
        void            _kill();
    };

    struct ViGriddedExport {
        VkImageType     type        = {};
        VkImageLayout   src_layout  = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        VkFormat        format      = VK_FORMAT_UNDEFINED;
        VkFormat        desired     = VK_FORMAT_UNDEFINED;
        VkExtent3D      extent      = {};
    };
    
    Expect<GriddedDataPtr>   export_gridded(ViDevice&, VkImage, const ViGriddedExport& vix);
}
