////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/vulkan/ViImage.hpp>
#include <tachyon/errors.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/asset/Raster.hpp>
#include <tachyon/vulkan/VqStructs.hpp>
#include <tachyon/vulkan/ViBuffer.hpp>
#include <tachyon/vulkan/ViDevice.hpp>
#include <tachyon/vulkan/ViDevice.hpp>
#include <yq/shape/Size4.hxx>

namespace yq::tachyon {
    namespace errors {
        using image_bad_state                   = error_db::entry<"Image is in a bad state">;
        using image_bad_format                  = error_db::entry<"Image format is unknown">;
        using image_existing                    = error_db::entry<"Image already created">;
        using image_cant_create_temporary       = error_db::entry<"Unable to create temporary image">;
        using image_empty                       = error_db::entry<"Image is empty">;
        using image_incompatible_images         = error_db::entry<"Images are incompatible to be layered">;
        using image_view_cant_create            = error_db::entry<"Unable to create image view">;
    }
    
    Expect<RasterPtr>   export_image(ViDevice& viz, VkImage img, const ViImageExport& vix)
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
            ViImage::Param p4;
            p4.usage = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
            temp    = new ViImage(viz, info, p4);
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

        ec  = viz.queue_task(viz.graphics_queue(HEADLESS), downloadTask);

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
    
    ViImage::ViImage(ViDevice&viz, const Raster&img, const Param& p)
    {
        if(viz.device()){
            if(_init(viz, img, p) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }
    
    ViImage::ViImage(ViDevice&viz, const RasterInfo& info, const Param& p)
    {
        if(viz.device()){
            if(_init(viz, info, p) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }

    ViImage::ViImage(ViDevice&viz, std::span<const RasterCPtr> images, const Param& p)
    {
        if(viz.device()){
            if(_init(viz, images, p) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }
    

    ViImage::~ViImage()
    {
        kill();
    }

    std::error_code ViImage::_init(ViDevice&viz, const RasterInfo& info, const Param& p)
    {
        m_device                = &viz;
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
        imgInfo.usage           = p.usage;
        imgInfo.tiling          = (VkImageTiling) m_info.tiling.value();
        imgInfo.sharingMode     = VK_SHARING_MODE_EXCLUSIVE;
        imgInfo.flags           = p.flags;
        
        VmaAllocationCreateInfo diai  = {};
        diai.usage              = p.memory;
        
        if(vmaCreateImage(viz.allocator(), &imgInfo, &diai, &m_image, &m_allocation, nullptr) != VK_SUCCESS){
            return errors::insufficient_gpu_memory();
        }
        
        m_layout        = VK_IMAGE_LAYOUT_UNDEFINED;
        m_access        = 0;
        m_queue         = 0;
        m_aspect        = p.aspect;
        return {};
    }

    void            ViImage::barrier(VkCommandBuffer cmd, const Respec& spec)
    {
        VqImageMemoryBarrier imb;
        imb.subresourceRange.aspectMask         = m_aspect;
        imb.subresourceRange.baseMipLevel       = 0;
        imb.subresourceRange.levelCount         = m_mips;
        imb.subresourceRange.baseArrayLayer     = 0;
        imb.subresourceRange.layerCount         = m_layers;
        
        if(spec.access){
            imb.srcAccessMask   = m_access;
            imb.dstAccessMask   = m_access = spec.access;
        } else {
            imb.srcAccessMask   = imb.dstAccessMask = m_access;
        }
        
        if(spec.layout != VK_IMAGE_LAYOUT_UNDEFINED){
            imb.oldLayout       = m_layout;
            imb.newLayout       = m_layout = spec.layout;
        } else {
            imb.oldLayout       = imb.newLayout = m_layout;
        }
        
        if(spec.queue != UINT32_MAX){
            imb.srcQueueFamilyIndex = m_queue;
            imb.dstQueueFamilyIndex = m_queue = spec.queue;
        } else {
            imb.srcQueueFamilyIndex = imb.dstQueueFamilyIndex = m_queue;
        }
        
        imb.image   = m_image;
        
        VkPipelineStageFlags    newStages   = spec.stages ? spec.stages : m_stages;
        vkCmdPipelineBarrier(cmd, m_stages, newStages, 0, 0, nullptr, 0, nullptr, 1, &imb);
        m_stages    = newStages;
    }

    std::error_code ViImage::_init(ViDevice& viz, const Raster& img, const Param& p)
    {
        ViBufferPtr      local = new ViBuffer(viz, img.memory, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, {.usage=VMA_MEMORY_USAGE_CPU_TO_GPU});
        if(!local->valid())
            return errors::insufficient_gpu_memory();


        std::error_code ec = _init(viz, img.info, p);
        if(ec != std::error_code()){
        vizWarning << "ViImage: Unable to initialize: " << ec.message();
            return ec;
        }
            
        auto uploadTask = [&](VkCommandBuffer cmd){
            barrier(cmd, { .access=VK_ACCESS_2_TRANSFER_WRITE_BIT, .layout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, .stages=VK_PIPELINE_STAGE_TRANSFER_BIT });
            
            VkBufferImageCopy creg  = {};
            creg.bufferOffset       = 0;
            creg.bufferRowLength    = 0;
            creg.bufferImageHeight  = 0;

            creg.imageSubresource.aspectMask        = p.aspect;
            creg.imageSubresource.mipLevel          = 0;
            creg.imageSubresource.baseArrayLayer    = 0;
            creg.imageSubresource.layerCount        = 1;
            creg.imageExtent.width                  = (uint32_t) m_info.size.x;
            creg.imageExtent.height                 = (uint32_t) m_info.size.y;
            creg.imageExtent.depth                  = (uint32_t) m_info.size.z;

            //copy the buffer into the image
            vkCmdCopyBufferToImage(cmd, local->buffer(), m_image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &creg);

            barrier(cmd, { .access = p.access, .layout = p.layout, .stages=p.stages });
        };

        // If we bring in mipping, we will most likely want to use the non-display graphics queue?
        ec = viz.queue_task(viz.graphics_queue(HEADLESS), uploadTask);
        if(ec != std::error_code())
            return ec;
            
        m_id                = img.id();
        return {};
    }
        
    std::error_code ViImage::_init(ViDevice&viz, const std::span<const RasterCPtr>&imgs, const Param& p)
    {
        //  check for nulls
        for(const RasterCPtr& img : imgs){
            if(!img){
                vizWarning << "ViImage: null image submitted";
                return errors::null_pointer();
            }
        }
    
        // check for compatible characteristics
        RasterInfo      info = imgs[0]->info;
        //bool            diffSize    = false;
        for(const RasterCPtr& img : imgs){
            //if(info.size != img->info.size)
                //diffSize    = true;
        
            info.size   = info.size.emax(img->info.size);
            if(info.type != img->info.type){
                vizWarning << "ViImage: Image type mismatch";
                return errors::image_incompatible_images();
            }
            if(img->info.arrayLayers != 1){
                vizWarning << "ViImage: This is already a layered image";
                return errors::image_incompatible_images();
            }
        }
        
        info.arrayLayers    = imgs.size();

        //  And we upsize...
        unsigned    mx  = std::max(info.size.x, info.size.y);
        info.size.x = mx;
        info.size.y = mx;
        
        //  Load the images
        std::vector<ViImagePtr>    images;
        for(const RasterCPtr& img : imgs){
            Param p3;
            p3.layout   = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            p3.usage   |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
            p3.access   = VK_ACCESS_2_TRANSFER_WRITE_BIT;
            p3.stages   = VK_PIPELINE_STAGE_TRANSFER_BIT;
        
            ViImagePtr  local = new ViImage(viz, *img, p3);
            if(!local->valid())
                return errors::insufficient_gpu_memory();
            images.push_back(local);
        }
    
        // Create our destination image
        Param p2 = p;
        p2.usage    = VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        p2.flags   |= VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT;
        p2.layout   = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

        
        
        std::error_code ec = _init(viz, info, p2 );
        if(ec != std::error_code()){
            return ec;
        }

        auto compositeTask = [&](VkCommandBuffer cmd){
            std::vector<VkImageMemoryBarrier>   imbs;
            for(size_t n=0;n<images.size();++n){
                VqImageMemoryBarrier imb;
                imb.oldLayout                       = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                imb.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                imb.image                           = images[n]->image();
                imb.subresourceRange.aspectMask     = p.aspect;
                imb.subresourceRange.baseMipLevel   = 0;
                imb.subresourceRange.levelCount     = 1;
                imb.subresourceRange.baseArrayLayer = 0;
                imb.subresourceRange.layerCount     = 1;
                imb.srcAccessMask                   = 0; // VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
                imb.dstAccessMask                   = 0; // VK_ACCESS_MEMORY_READ_BIT;
                imbs.push_back(imb);
            }

            vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, 0, nullptr, 0, nullptr, imbs.size(), imbs.data());
        
            for(size_t n=0;n<images.size();++n){
                const Raster&   ras = *(imgs[n]);
                const ViImage&  img = *images[n];
                /*
                if(ras.info.size == info.size){
                    VkImageCopy     creg;
                    
                    creg.srcSubresource.aspectMask      = VK_IMAGE_ASPECT_COLOR_BIT;
                    creg.srcSubresource.mipLevel        = 0;
                    creg.srcSubresource.baseArrayLayer  = 0;
                    creg.srcSubresource.layerCount      = 1;
                    creg.srcOffset      = { 0, 0, 0 };

                    creg.dstSubresource.aspectMask      = VK_IMAGE_ASPECT_COLOR_BIT;
                    creg.dstSubresource.mipLevel        = 0;
                    creg.dstSubresource.baseArrayLayer  = n;
                    creg.dstSubresource.layerCount      = 1;
                    creg.dstOffset      = { 0, 0, 0 };
                    creg.extent         = { (uint32_t) info.size.x, (uint32_t) info.size.y, (uint32_t) info.size.z };
                    
                    vkCmdCopyImage(cmd, img.image(), VK_IMAGE_LAYOUT_GENERAL, m_image, VK_IMAGE_LAYOUT_GENERAL, 1, &creg);
                } else {
                */
                    VkImageBlit     blit;
                    
                    blit.srcSubresource.aspectMask      = p.aspect;
                    blit.srcSubresource.mipLevel        = 0;
                    blit.srcSubresource.baseArrayLayer  = 0;
                    blit.srcSubresource.layerCount      = 1;
                    blit.srcOffsets[0]      = { 0, 0, 0 };
                    blit.srcOffsets[1]      = { (int32_t) ras.info.size.x, (int32_t) ras.info.size.y, (int32_t) ras.info.size.z };
                    blit.dstSubresource.aspectMask      = p.aspect;
                    blit.dstSubresource.mipLevel        = 0;
                    blit.dstSubresource.baseArrayLayer  = n;
                    blit.dstSubresource.layerCount      = 1;
                    blit.dstOffsets[0]      = { 0, 0, 0 };
                    blit.dstOffsets[1]      = { (int32_t) info.size.x, (int32_t) info.size.y, (int32_t) info.size.z };
                    
                    vkCmdBlitImage(cmd, img.image(), VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, m_image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &blit, VK_FILTER_LINEAR);
                //}
                //break;
            }

            VqImageMemoryBarrier imb;
            imb.oldLayout                       = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            imb.newLayout                       = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
            imb.image                           = m_image;
            imb.subresourceRange.aspectMask     = p.aspect;
            imb.subresourceRange.baseMipLevel   = 0;
            imb.subresourceRange.levelCount     = 1;
            imb.subresourceRange.baseArrayLayer = 0;
            imb.subresourceRange.layerCount     = (uint32_t) images.size();
            imb.srcAccessMask                   = 0;
            imb.dstAccessMask                   = 0;
            
            vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, 0, nullptr, 0, nullptr, 1, &imb);
        };
            
        ec = viz.queue_task(viz.graphics_queue(HEADLESS), compositeTask);
        if(ec != std::error_code())
            return ec;
        return {};
    }

    void ViImage::_kill()
    {
        if(m_device && m_image && m_allocation){
            vmaDestroyImage(m_device->allocator(), m_image, m_allocation);
            m_image         = nullptr;
            m_allocation    = nullptr;
        }
    }
    
    void ViImage::_wipe()
    {
        m_device        = nullptr;
        m_image         = nullptr;
        m_allocation    = nullptr;
        m_info          = {};
    }
    
    
    std::error_code ViImage::init(ViDevice&viz, const Raster&img, const Param&p)
    {
        if(m_device){
            if(!consistent())
                return errors::image_bad_state();
            return errors::image_existing();
        }
        std::error_code ec  = _init(viz, img, p);
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
        return m_device ? (m_image && m_allocation) :
            (!m_image && !m_allocation);
    }
    
    bool            ViImage::valid() const
    {
        return m_device && m_image && m_allocation;
    }
        
}
