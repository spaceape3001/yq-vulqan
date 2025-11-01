////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/ViTexture.hpp>

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/RasterInfo.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/ViImage.hpp>
#include <yq/tachyon/vulkan/ViLogging.hpp>
#include <yq/tachyon/vulkan/ViSampler.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>

namespace yq::tachyon {
    namespace errors {
        using texture_bad_image                 = error_db::entry<"Texture's image is bad">;
        using texture_bad_sampler               = error_db::entry<"Texture's sampler is bad">;
        using texture_bad_state                 = error_db::entry<"Texture is in a bad state">;
        using texture_cant_create_image_view    = error_db::entry<"Texture is unable to create image view">;
        using texture_existing                  = error_db::entry<"Texture already created">;
        using texture_image_null_pointer        = error_db::entry<"Texture's image is a null pointer">;
        using texture_sampler_null_pointer      = error_db::entry<"Texture's sampler is a null pointer">;
        using texture_no_images                 = error_db::entry<"Texture's without images">;
        using texture_null_pointer              = error_db::entry<"Texture is a null pointer">;
    }

    ViTexture::ViTexture(ViDevice&dev, const Texture&tex) : m_device(dev)
    {
        assert(dev.device());
        
        std::error_code ec  = _init(tex);
        if(ec != std::error_code()){
            _kill();
        }
        
    }
    
    ViTexture::ViTexture(ViDevice& dev, const ViImageCPtr&img, const ViSamplerCPtr&sam, const TextureInfo& info) : 
        m_device(dev)
    {
        assert(dev.device() && img && img->valid() && sam && sam->valid());
        
        std::error_code ec  = _init(img, sam, info);
        if(ec != std::error_code()){
            _kill();
        }
    }

    ViTexture::~ViTexture()
    {
        if(valid())
            _kill();
    }
    
    std::error_code     ViTexture::_init(const Texture&tex)
    {
        if(tex.images.empty()){
            vizWarning << "ViTexture() -- no images!";
            return errors::texture_no_images();
        }
        
        if(!tex.sampler){
            vizWarning << "ViTexture() -- sampler is NULL!";
            return errors::texture_sampler_null_pointer();
        }

        ViImageCPtr img; 
        if(tex.images.size() > 1){
            //try {
                img = new ViImage(m_device, tex.images);
            //}
            //catch(...)
            //{
                //img = nullptr;
            //}
            if(!img.valid())
                img = nullptr;
        } else {
            img = m_device.image_create(*tex.images[0]);
        }
        if(!img){
            vizWarning << "ViTexture() -- cannot import image!";
            return errors::texture_bad_image();
        }
        
        ViSamplerCPtr sampler  = m_device.sampler_create(*tex.sampler);
        if(!sampler){
            vizWarning << "ViTexture() -- cannot import sampler!";
            return errors::texture_bad_sampler();
        }
        
        m_id        = tex.id();
        return _init(img, sampler, tex.info); 
    }
    
    std::error_code     ViTexture::_init(const ViImageCPtr& image, const ViSamplerCPtr& sampler, const TextureInfo& texInfo)
    {
        m_image     = image;
        m_sampler   = sampler;
    
        VqImageViewCreateInfo       info;
        const RasterInfo&            imgInfo  = image->info();

        m_extents  = { 
            .width          = (uint32_t) imgInfo.size.x,
            .height         = (uint32_t) imgInfo.size.y,
            .depth          = (uint32_t) imgInfo.size.z
        };

        info.image          = image -> image();
        info.flags  = texInfo.imageViewFlags.value();
        
        if(texInfo.imageViewType){
            info.viewType   = (VkImageViewType) (*texInfo.imageViewType).value();
        } else {
            switch(imgInfo.type){
            case RasterType::Is1D:
                info.viewType   = VK_IMAGE_VIEW_TYPE_1D;
                break;
            case RasterType::Is2D:
                info.viewType   = VK_IMAGE_VIEW_TYPE_2D;
                break;
            case RasterType::Is3D:
                info.viewType   = VK_IMAGE_VIEW_TYPE_3D;
                break;
            default:
                info.viewType   = VK_IMAGE_VIEW_TYPE_2D;
                break;
            }
        }

        if(texInfo.format){
            info.format = (VkFormat) (*texInfo.format).value();
        } else {
            info.format = (VkFormat) imgInfo.format.value();
        }
        
        info.components = {
            .r = (VkComponentSwizzle) texInfo.swizzle.red.value(),
            .g = (VkComponentSwizzle) texInfo.swizzle.green.value(),
            .b = (VkComponentSwizzle) texInfo.swizzle.blue.value(),
            .a = (VkComponentSwizzle) texInfo.swizzle.alpha.value()
        };

        info.subresourceRange.aspectMask        = (VkImageAspectFlags) texInfo.aspect.value();

        info.subresourceRange.baseMipLevel      = texInfo.baseMipLevel;
        info.subresourceRange.levelCount        = texInfo.levelCount;
        info.subresourceRange.baseArrayLayer    = texInfo.baseArrayLayer;
        info.subresourceRange.layerCount        = texInfo.layerCount;

        VkResult res = vkCreateImageView(m_device.device(), &info, nullptr, &m_imageView);
        if(res != VK_SUCCESS){
            vizWarning << "ViTexture() -- cannot create image view.  VkResult " << (int32_t) res;
            return errors::texture_cant_create_image_view();
        }
        
        return {};
    }
    
    void                ViTexture::_kill()
    {
        if(m_device.device() && m_imageView){
            vkDestroyImageView(m_device.device(), m_imageView, nullptr);
            m_imageView = nullptr;
        }
        
        m_imageView = nullptr;
        m_sampler   = {};
        m_image     = {};
        m_id        = 0ULL;
    }

    bool                ViTexture::consistent() const
    {
        return m_image ? (m_imageView && m_sampler) : (!m_sampler && !m_imageView);
    }

    VkExtent3D          ViTexture::extents() const
    {
        return m_extents;
    }
    
    VkImage             ViTexture::image() const
    {
        if(m_image)
            return m_image -> image();
        return nullptr;
    }
    
    VkImageView         ViTexture::image_view() const
    {
        return m_imageView;
    }
    
    #if 0
    std::error_code     ViTexture::init(ViDevice&viz, const Texture&tex)
    {
        if(m_viz){
            if(!consistent()){
                return errors::texture_bad_state();
            }
            return errors::texture_existing();
        }
        if(!viz.device())
            return errors::vulkan_uninitialized();
        std::error_code     ec  = _init(viz, tex);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }
    #endif
    
    void                ViTexture::kill()
    {
        _kill();
    }
    
    VkSampler           ViTexture::sampler() const
    {
        if(m_sampler)
            return m_sampler -> sampler();
        return nullptr;
    }
    
    bool                ViTexture::valid() const
    {
        return m_image && m_image->valid() && m_sampler && m_sampler -> valid();
    }
}
