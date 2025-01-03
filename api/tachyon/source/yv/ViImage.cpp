////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViImage.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yt/gfx/Raster.hpp>
#include <yv/VqStructs.hpp>
#include <yv/ViBuffer.hpp>
#include <yv/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using image_bad_state                   = error_db::entry<"Image is in a bad state">;
        using image_bad_format                  = error_db::entry<"Image format is unknown">;
        using image_existing                    = error_db::entry<"Image already created">;
        using image_cant_create_temporary       = error_db::entry<"Unable to create temporary image">;
        using image_empty                       = error_db::entry<"Image is empty">;
        using image_view_cant_create            = error_db::entry<"Unable to create image view">;
    }
    
    Expect<RasterPtr>   export_image(ViVisualizer& viz, VkImage img, const ViImageExport& vix)
    {
        if(!img)
            return errors::null_pointer();
            
        VkExtent3D  extent = vix.extent;
        size_t       cnt        = 0;
        switch(vix.type){
        case VK_IMAGE_TYPE_1D:
            cnt = (size_t) extent.width;
            extent.depth        = extent.height = 1;
            break;
        case VK_IMAGE_TYPE_2D:
            cnt = (size_t) extent.width * (size_t) extent.height;
            extent.depth        = 1;
            break;
        case VK_IMAGE_TYPE_3D:
            cnt = (size_t) extent.width * (size_t) extent.height * (size_t) extent.depth;
            break;
        default:
            break;
        }

        if(!cnt)
            return errors::image_empty();

        RasterInfo  info;
        info.type       = (RasterType) vix.type;
        info.format     = (DataFormat) vix.format;
        info.size.x     = extent.width;
        info.size.y     = extent.height;
        info.size.z     = extent.depth;

        ViImagePtr  temp;
        if(vix.desired && (vix.desired != vix.format)){
            info.format = (DataFormat) vix.desired;
            temp    = new ViImage(viz, info, VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT);
            if(!temp->valid())
                return errors::image_cant_create_temporary();
        }
        
        size_t       bpp       = ViImage::format_bytes((VkFormat) info.format.value());
        if(!bpp)
            return errors::image_bad_format();
        

        size_t      bytes       = bpp * cnt;
        ViBufferPtr      local = new ViBuffer(viz, bytes, VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT, VMA_MEMORY_USAGE_GPU_TO_CPU);
        if(!local->valid())
            return errors::insufficient_gpu_memory();
        
        std::error_code ec, ec2;
        auto downloadTask = [&](VkCommandBuffer cmd) {
            VkBufferImageCopy creg  = {};
            creg.bufferOffset       = 0;
            creg.bufferRowLength    = 0;
            creg.bufferImageHeight  = 0;

            creg.imageSubresource.aspectMask        = VK_IMAGE_ASPECT_COLOR_BIT;
            creg.imageSubresource.mipLevel          = 0;
            creg.imageSubresource.baseArrayLayer    = 0;
            creg.imageSubresource.layerCount        = 1;
            creg.imageExtent                        = extent;

            VkImage         i2      = img;
            VkImageLayout   lay     = vix.src_layout;
            if(temp){
                VkImageCopy     copy{};
                copy.srcSubresource = creg.imageSubresource;
                copy.dstSubresource = creg.imageSubresource;
                copy.extent         = extent;
                i2  = temp->image();
                
                vkCmdCopyImage(cmd, img, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, i2, 
                    VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &copy);

#if 0
                VqImageMemoryBarrier imb;
                imb.oldLayout           = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                imb.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                imb.image               = i2;
                imb.subresourceRange    = VkImageSubresourceRange{ 
                    .aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT,
                    .baseMipLevel   = 0,
                    .levelCount     = 1,
                    .baseArrayLayer = 0,
                    .layerCount     = 1
                };
                imb.srcAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
                imb.dstAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            
                vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &imb);
#endif
                lay = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            }

            vkCmdCopyImageToBuffer(cmd, i2, lay, local->buffer(), 1, &creg);
        };

        if(viz.transfer_queue_valid()){
            ec = viz.transfer_queue_task(downloadTask);
        } else {
            ec = viz.graphic_queue_task(downloadTask);
        }

        if(ec != std::error_code())
            return unexpected(ec);
        //if(ec2 != std::error_code())
            //return unexpected(ec2);

        ec  = local -> map();
        if(ec != std::error_code())
            return unexpected(ec);
            
        void*   p   = malloc(bytes);
        if(!p)
            return errors::insufficient_cpu_memory();
        memcpy(p, local->data(), bytes);
        local->unmap();
        return new Raster(info, 
            Memory(SET, p, bytes, bpp, [](const void*p, size_t){
                free((void*) p);
            })
        );
    }

    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    size_t       ViImage::format_bytes(VkFormat fmt)
    {
        switch(fmt){
        case VK_FORMAT_R4G4_UNORM_PACK8:
            return 1;
        case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
        case VK_FORMAT_B4G4R4A4_UNORM_PACK16:
        case VK_FORMAT_R5G6B5_UNORM_PACK16:
        case VK_FORMAT_B5G6R5_UNORM_PACK16:
        case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
        case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
        case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
            return 2;
        case VK_FORMAT_R8_UNORM:
        case VK_FORMAT_R8_SNORM:
        case VK_FORMAT_R8_USCALED:
        case VK_FORMAT_R8_SSCALED:
        case VK_FORMAT_R8_UINT:
        case VK_FORMAT_R8_SINT:
        case VK_FORMAT_R8_SRGB:
            return 1;
        case VK_FORMAT_R8G8_UNORM:
        case VK_FORMAT_R8G8_SNORM:
        case VK_FORMAT_R8G8_USCALED:
        case VK_FORMAT_R8G8_SSCALED:
        case VK_FORMAT_R8G8_UINT:
        case VK_FORMAT_R8G8_SINT:
        case VK_FORMAT_R8G8_SRGB:
            return 2;
        case VK_FORMAT_R8G8B8_UNORM:
        case VK_FORMAT_R8G8B8_SNORM:
        case VK_FORMAT_R8G8B8_USCALED:
        case VK_FORMAT_R8G8B8_SSCALED:
        case VK_FORMAT_R8G8B8_UINT:
        case VK_FORMAT_R8G8B8_SINT:
        case VK_FORMAT_R8G8B8_SRGB:
        case VK_FORMAT_B8G8R8_UNORM:
        case VK_FORMAT_B8G8R8_SNORM:
        case VK_FORMAT_B8G8R8_USCALED:
        case VK_FORMAT_B8G8R8_SSCALED:
        case VK_FORMAT_B8G8R8_UINT:
        case VK_FORMAT_B8G8R8_SINT:
        case VK_FORMAT_B8G8R8_SRGB:
            return 3;
        case VK_FORMAT_R8G8B8A8_UNORM:
        case VK_FORMAT_R8G8B8A8_SNORM:
        case VK_FORMAT_R8G8B8A8_USCALED:
        case VK_FORMAT_R8G8B8A8_SSCALED:
        case VK_FORMAT_R8G8B8A8_UINT:
        case VK_FORMAT_R8G8B8A8_SINT:
        case VK_FORMAT_R8G8B8A8_SRGB:
        case VK_FORMAT_B8G8R8A8_UNORM:
        case VK_FORMAT_B8G8R8A8_SNORM:
        case VK_FORMAT_B8G8R8A8_USCALED:
        case VK_FORMAT_B8G8R8A8_SSCALED:
        case VK_FORMAT_B8G8R8A8_UINT:
        case VK_FORMAT_B8G8R8A8_SINT:
        case VK_FORMAT_B8G8R8A8_SRGB:
        case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
        case VK_FORMAT_A8B8G8R8_SNORM_PACK32:
        case VK_FORMAT_A8B8G8R8_USCALED_PACK32:
        case VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
        case VK_FORMAT_A8B8G8R8_UINT_PACK32:
        case VK_FORMAT_A8B8G8R8_SINT_PACK32:
        case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
        case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
        case VK_FORMAT_A2R10G10B10_SNORM_PACK32:
        case VK_FORMAT_A2R10G10B10_USCALED_PACK32:
        case VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
        case VK_FORMAT_A2R10G10B10_UINT_PACK32:
        case VK_FORMAT_A2R10G10B10_SINT_PACK32:
        case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
        case VK_FORMAT_A2B10G10R10_SNORM_PACK32:
        case VK_FORMAT_A2B10G10R10_USCALED_PACK32:
        case VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
        case VK_FORMAT_A2B10G10R10_UINT_PACK32:
        case VK_FORMAT_A2B10G10R10_SINT_PACK32:
            return 4;
        case VK_FORMAT_R16_UNORM:
        case VK_FORMAT_R16_SNORM:
        case VK_FORMAT_R16_USCALED:
        case VK_FORMAT_R16_SSCALED:
        case VK_FORMAT_R16_UINT:
        case VK_FORMAT_R16_SINT:
        case VK_FORMAT_R16_SFLOAT:
            return 2;
        case VK_FORMAT_R16G16_UNORM:
        case VK_FORMAT_R16G16_SNORM:
        case VK_FORMAT_R16G16_USCALED:
        case VK_FORMAT_R16G16_SSCALED:
        case VK_FORMAT_R16G16_UINT:
        case VK_FORMAT_R16G16_SINT:
        case VK_FORMAT_R16G16_SFLOAT:
            return 4;
        case VK_FORMAT_R16G16B16_UNORM:
        case VK_FORMAT_R16G16B16_SNORM:
        case VK_FORMAT_R16G16B16_USCALED:
        case VK_FORMAT_R16G16B16_SSCALED:
        case VK_FORMAT_R16G16B16_UINT:
        case VK_FORMAT_R16G16B16_SINT:
        case VK_FORMAT_R16G16B16_SFLOAT:
            return 6;
        case VK_FORMAT_R16G16B16A16_UNORM:
        case VK_FORMAT_R16G16B16A16_SNORM:
        case VK_FORMAT_R16G16B16A16_USCALED:
        case VK_FORMAT_R16G16B16A16_SSCALED:
        case VK_FORMAT_R16G16B16A16_UINT:
        case VK_FORMAT_R16G16B16A16_SINT:
        case VK_FORMAT_R16G16B16A16_SFLOAT:
            return 8;
        case VK_FORMAT_R32_UINT:
        case VK_FORMAT_R32_SINT:
        case VK_FORMAT_R32_SFLOAT:
            return 4;
        case VK_FORMAT_R32G32_UINT:
        case VK_FORMAT_R32G32_SINT:
        case VK_FORMAT_R32G32_SFLOAT:
            return 8;
        case VK_FORMAT_R32G32B32_UINT:
        case VK_FORMAT_R32G32B32_SINT:
        case VK_FORMAT_R32G32B32_SFLOAT:
        case VK_FORMAT_R32G32B32A32_UINT:
        case VK_FORMAT_R32G32B32A32_SINT:
        case VK_FORMAT_R32G32B32A32_SFLOAT:
            return 16;
        case VK_FORMAT_R64_UINT:
        case VK_FORMAT_R64_SINT:
        case VK_FORMAT_R64_SFLOAT:
            return 8;
        case VK_FORMAT_R64G64_UINT:
        case VK_FORMAT_R64G64_SINT:
        case VK_FORMAT_R64G64_SFLOAT:
            return 16;
        case VK_FORMAT_R64G64B64_UINT:
        case VK_FORMAT_R64G64B64_SINT:
        case VK_FORMAT_R64G64B64_SFLOAT:
            return 24;
        case VK_FORMAT_R64G64B64A64_UINT:
        case VK_FORMAT_R64G64B64A64_SINT:
        case VK_FORMAT_R64G64B64A64_SFLOAT:
            return 32;
        case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
        case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
            return 4;
        case VK_FORMAT_D16_UNORM:
            return 2;
        case VK_FORMAT_X8_D24_UNORM_PACK32:
            return 4;
        case VK_FORMAT_D32_SFLOAT:
            return 4;
        case VK_FORMAT_S8_UINT:
            return 1;
        case VK_FORMAT_D16_UNORM_S8_UINT:
        case VK_FORMAT_D24_UNORM_S8_UINT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return 32;
        case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
        case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
        case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
        case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        case VK_FORMAT_BC2_UNORM_BLOCK:
        case VK_FORMAT_BC2_SRGB_BLOCK:
        case VK_FORMAT_BC3_UNORM_BLOCK:
        case VK_FORMAT_BC3_SRGB_BLOCK:
        case VK_FORMAT_BC4_UNORM_BLOCK:
        case VK_FORMAT_BC4_SNORM_BLOCK:
        case VK_FORMAT_BC5_UNORM_BLOCK:
        case VK_FORMAT_BC5_SNORM_BLOCK:
        case VK_FORMAT_BC6H_UFLOAT_BLOCK:
        case VK_FORMAT_BC6H_SFLOAT_BLOCK:
        case VK_FORMAT_BC7_UNORM_BLOCK:
        case VK_FORMAT_BC7_SRGB_BLOCK:
            return 0;
        case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
            return 3;
        case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
            return 4;
        case VK_FORMAT_EAC_R11_UNORM_BLOCK:
        case VK_FORMAT_EAC_R11_SNORM_BLOCK:
        case VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
        case VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
        case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
        case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
        case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
        case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
        case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
        case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
        case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
        case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
        case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
        case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
        case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
        case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
        case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
        case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
        case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
        case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
        case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
        case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
        case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
            return 0;
        case VK_FORMAT_G8B8G8R8_422_UNORM:
        case VK_FORMAT_B8G8R8G8_422_UNORM:
            return 4;
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
            return 0;
        case VK_FORMAT_R10X6_UNORM_PACK16:
            return 2;
        case VK_FORMAT_R10X6G10X6_UNORM_2PACK16:
        case VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16:
        case VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16:
        case VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_R12X4_UNORM_PACK16:
        case VK_FORMAT_R12X4G12X4_UNORM_2PACK16:
        case VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16:
        case VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16:
        case VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_G16B16G16R16_422_UNORM:
        case VK_FORMAT_B16G16R16G16_422_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM:
        case VK_FORMAT_A4R4G4B4_UNORM_PACK16:
        case VK_FORMAT_A4B4G4R4_UNORM_PACK16:
        case VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK:
        case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG:
        case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
        case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_R16G16_SFIXED5_NV:
        case VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR:
            return 0;
        case VK_FORMAT_A8_UNORM_KHR:
            return 1;
        default:
            return 0;
        }
    }

    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

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
    
    ViImage::ViImage(ViVisualizer&viz, const RasterInfo& info, VkImageUsageFlags usage)
    {
        if(viz.device()){
            if(_init(viz, info, usage) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }
    

    ViImage::~ViImage()
    {
        kill();
    }

    std::error_code ViImage::_init(ViVisualizer&viz, const RasterInfo& info, VkImageUsageFlags usage)
    {
        m_viz                   = &viz;
        m_info                  = info;
        
        VqImageCreateInfo   imgInfo;
        imgInfo.imageType       = (VkImageType) m_info.type.value();
        imgInfo.extent.width    = (uint32_t) m_info.size.x;
        imgInfo.extent.height   = (uint32_t) m_info.size.y;
        imgInfo.extent.depth    = (uint32_t) m_info.size.z;
        imgInfo.mipLevels       = m_info.mipLevels;
        imgInfo.arrayLayers     = m_info.arrayLayers;
        imgInfo.samples         = VK_SAMPLE_COUNT_1_BIT;
        imgInfo.format          = (VkFormat) m_info.format.value();
        imgInfo.usage           = usage;
        imgInfo.tiling          = (VkImageTiling) m_info.tiling.value();
        imgInfo.sharingMode     = VK_SHARING_MODE_EXCLUSIVE;
       
        VmaAllocationCreateInfo diai  = {};
        diai.usage    = VMA_MEMORY_USAGE_GPU_ONLY;

        if(vmaCreateImage(viz.allocator(), &imgInfo, &diai, &m_image, &m_allocation, nullptr) != VK_SUCCESS){
            return errors::insufficient_gpu_memory();
        }
        return {};
    }

    std::error_code ViImage::_init(ViVisualizer& viz, const Raster& img)
    {
        ViBufferPtr      local = new ViBuffer(viz, img.memory, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, {.usage=VMA_MEMORY_USAGE_CPU_ONLY});
        if(!local->valid())
            return errors::insufficient_gpu_memory();

        std::error_code ec = _init(viz, img.info, VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT);
        if(ec != std::error_code()){
            return ec;
        }
            
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
            creg.imageExtent.width                  = (uint32_t) m_info.size.x;
            creg.imageExtent.height                 = (uint32_t) m_info.size.y;
            creg.imageExtent.depth                  = (uint32_t) m_info.size.z;

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

        if(ec != std::error_code())
            return ec;
            
        m_id                = img.id();
        return {};
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
