////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViImage.hpp"
#include <tachyon/errors.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/image/Raster.hpp>
#include <tachyon/v/VqStructs.hpp>
#include <tachyon/viz/ViBuffer.hpp>
#include <tachyon/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using image_bad_state                   = error_db::entry<"Image is in a bad state">;
        using image_existing                    = error_db::entry<"Image already created">;
        using image_view_cant_create            = error_db::entry<"Unable to create image view">;
    }
    
    ViImage::ViImage()
    {
    }
    
    ViImage::ViImage(ViVisualizer&viz, const Raster&img)
    {
        if(viz.device()){
            if(_init(viz, img) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }
    
    ViImage::~ViImage()
    {
        kill();
    }

    std::error_code ViImage::_init(ViVisualizer& viz, const Raster& img)
    {
        ViBufferPtr      local = new ViBuffer(viz, img.memory, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, {.usage=VMA_MEMORY_USAGE_CPU_ONLY});
        if(!local->valid())
            return errors::insufficient_gpu_memory();

        m_viz       = &viz;
        m_info      = img.info;

        std::error_code ec;
        
        VqImageCreateInfo   imgInfo;
        imgInfo.imageType       = (VkImageType) m_info.type.value();
        imgInfo.extent.width    = (uint32_t) m_info.size.x;
        imgInfo.extent.height   = (uint32_t) m_info.size.y;
        imgInfo.extent.depth    = (uint32_t) m_info.size.z;
        imgInfo.mipLevels       = m_info.mipLevels;
        imgInfo.arrayLayers     = m_info.arrayLayers;
        imgInfo.samples         = VK_SAMPLE_COUNT_1_BIT;
        imgInfo.format          = (VkFormat) m_info.format.value();
        imgInfo.usage           = VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        imgInfo.tiling          = (VkImageTiling) m_info.tiling.value();
        imgInfo.sharingMode     = VK_SHARING_MODE_EXCLUSIVE;

#if 0
// temporary overrides
imgInfo.mipLevels       = 1;
imgInfo.arrayLayers     = 1;
imgInfo.format          = VK_FORMAT_R8G8B8A8_UNORM;
imgInfo.tiling          = VK_IMAGE_TILING_OPTIMAL;
imgInfo.initialLayout   = VK_IMAGE_LAYOUT_UNDEFINED;
#endif
       
        VmaAllocationCreateInfo diai  = {};
        diai.usage    = VMA_MEMORY_USAGE_GPU_ONLY;
        
        if(vmaCreateImage(viz.allocator(), &imgInfo, &diai, &m_image, &m_allocation, nullptr) != VK_SUCCESS)
            return (std::error_code) errors::insufficient_gpu_memory();
            
        auto uploadTask = [&](VkCommandBuffer cmd){
            VkImageSubresourceRange range;
            range.aspectMask        = VK_IMAGE_ASPECT_COLOR_BIT;
            range.baseMipLevel      = 0;
            range.levelCount        = 1;
            range.baseArrayLayer    = 0;
            range.layerCount        = 1;
            
            VqImageMemoryBarrier imb;
            imb.oldLayout           = VK_IMAGE_LAYOUT_UNDEFINED;
            imb.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            imb.image               = m_image;
            imb.subresourceRange    = range;
            imb.srcAccessMask       = 0;
            imb.dstAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            
            vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &imb);

            VkBufferImageCopy creg  = {};
            creg.bufferOffset       = 0;
            creg.bufferRowLength    = 0;
            creg.bufferImageHeight  = 0;

            creg.imageSubresource.aspectMask        = VK_IMAGE_ASPECT_COLOR_BIT;
            creg.imageSubresource.mipLevel          = 0;
            creg.imageSubresource.baseArrayLayer    = 0;
            creg.imageSubresource.layerCount        = 1;
            creg.imageExtent                        = imgInfo.extent;

            //copy the buffer into the image
            vkCmdCopyBufferToImage(cmd, local->buffer(), m_image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &creg);

            VkImageMemoryBarrier imb2 = imb;

            imb2.oldLayout          = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            imb2.newLayout          = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

            imb2.srcAccessMask      = VK_ACCESS_TRANSFER_WRITE_BIT;
            imb2.dstAccessMask      = VK_ACCESS_SHADER_READ_BIT;

            //barrier the image into the shader readable layout
            vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &imb2);
        };

        if(viz.transfer_queue_valid()){
            ec = viz.transfer_queue_task(uploadTask);
        } else {
            ec = viz.graphic_queue_task(uploadTask);
        }
        return ec;
    }
        
    void ViImage::_kill()
    {
        if(m_image && m_allocation){
            vmaDestroyImage(m_viz->allocator(), m_image, m_allocation);
            m_image         = nullptr;
            m_allocation    = nullptr;
        }
    }
    
    void ViImage::_wipe()
    {
        m_viz           = nullptr;
        m_image         = nullptr;
        m_allocation    = nullptr;
        m_info          = {};
    }
    
    
    std::error_code ViImage::init(ViVisualizer&viz, const Raster&img)
    {
        if(m_viz){
            if(!consistent())
                return errors::image_bad_state();
            return errors::image_existing();
        }
        std::error_code ec  = _init(viz, img);
        if(ec != std::error_code()){
            _kill();
            _wipe();
        }
        return ec;
    }
    
    void            ViImage::kill()
    {
        if(valid())
            _kill();
        _wipe();
    }
    
    bool            ViImage::consistent() const
    {
        return m_viz ? (m_image && m_allocation && m_viz->device()) :
            (!m_image && !m_allocation);
    }
    
    bool            ViImage::valid() const
    {
        return m_viz && m_image && m_allocation && m_viz->device();
    }
        
}
