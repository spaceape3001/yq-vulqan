////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViTexture.hpp"

#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/image/Image.hpp>
#include <yq-vulqan/image/ImageInfo.hpp>
#include <yq-vulqan/texture/Texture.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViImage.hpp>
#include <yq-vulqan/viz/ViSampler.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    ViTexture::ViTexture()
    {
    }
    
    ViTexture::ViTexture(ViVisualizer&viz, const Texture&tex)
    {
        if(viz.device()){
            std::error_code ec  = _init(viz, tex);
            if(ec != std::error_code()){
                _kill();
            }
        }
        
    }
    
    ViTexture::~ViTexture()
    {
        kill();
    }
    
    std::error_code     ViTexture::_init(ViVisualizer&viz, const Texture&tex)
    {
        if(!tex.image){
            vizWarning << "ViTexture() -- image is NULL!";
            return errors::texture_image_null_pointer();
        }
        if(!tex.sampler){
            vizWarning << "ViTexture() -- sampler is NULL!";
            return errors::texture_sampler_null_pointer();
        }
            
        m_image     = viz.image_create(*tex.image);
        if(!m_image){
            vizWarning << "ViTexture() -- cannot import image!";
            return errors::texture_bad_image();
        }
        
        m_sampler   = viz.sampler_create(*tex.sampler);
        if(!m_sampler){
            vizWarning << "ViTexture() -- cannot import sampler!";
            return errors::texture_bad_sampler();
        }
            
        VqImageViewCreateInfo       info;
        const TextureInfo&          ti  = tex.info;
        const ImageInfo&            ii  = tex.image->info;
        
        info.flags  = ti.imageViewFlags.value();
        info.image  = m_image -> image();
        
        if(ti.imageViewType){
            info.viewType   = (VkImageViewType) (*ti.imageViewType).value();
        } else {
            switch(ii.type){
            case ImageType::Is1D:
                info.viewType   = VK_IMAGE_VIEW_TYPE_1D;
                break;
            case ImageType::Is2D:
                info.viewType   = VK_IMAGE_VIEW_TYPE_2D;
                break;
            case ImageType::Is3D:
                info.viewType   = VK_IMAGE_VIEW_TYPE_3D;
                break;
            default:
                info.viewType   = VK_IMAGE_VIEW_TYPE_2D;
                break;
            }
        }
        
        if(ti.format){
            info.format = (VkFormat) (*ti.format).value();
        } else {
            info.format = (VkFormat) ii.format.value();
        }
        
        info.components.r   = (VkComponentSwizzle) ti.swizzle.red.value();
        info.components.g   = (VkComponentSwizzle) ti.swizzle.green.value();
        info.components.b   = (VkComponentSwizzle) ti.swizzle.blue.value();
        info.components.a   = (VkComponentSwizzle) ti.swizzle.alpha.value();
        
        info.subresourceRange.aspectMask     = (VkImageAspectFlags) ti.aspect.value();
        info.subresourceRange.baseMipLevel   = ti.baseMipLevel;
        info.subresourceRange.levelCount     = ti.levelCount;
        info.subresourceRange.baseArrayLayer = ti.baseArrayLayer;
        info.subresourceRange.layerCount     = ti.layerCount;

        VkResult res = vkCreateImageView(viz.device(), &info, nullptr, &m_imageView);
        if(res != VK_SUCCESS){
            vizWarning << "vkTexture().create(imageView): VkResult " << (int32_t) res;
            return errors::texture_cant_create_image_view();
        }
        
        m_viz       = &viz;
        return {};
    }
    
    void                ViTexture::_kill()
    {
        if(m_viz && m_viz->device() && m_imageView){
            vkDestroyImageView(m_viz->device(), m_imageView, nullptr);
            m_imageView = nullptr;
        }
        
        m_viz       = nullptr;
        m_imageView = nullptr;
        m_sampler   = {};
        m_image     = {};
    }
    
    std::error_code     ViTexture::init(ViVisualizer&viz, const Texture&tex)
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
    
    void                ViTexture::kill()
    {
        _kill();
    }

    bool                ViTexture::consistent() const
    {
        return m_viz ? (m_viz->device() && m_image && m_image->valid() && m_sampler && m_sampler->valid()) :
            (!m_image && !m_sampler && !m_imageView);
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
    
    VkSampler           ViTexture::sampler() const
    {
        if(m_sampler)
            return m_sampler -> sampler();
        return nullptr;
    }
    
    bool                ViTexture::valid() const
    {
        return m_viz && m_viz->device() && m_image && m_image->valid() && m_sampler && m_sampler -> valid();
    }
}
