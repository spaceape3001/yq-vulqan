////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Ref.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq-vulqan/typedef/texture.hpp>
#include <yq-vulqan/typedef/sampler.hpp>
#include <vulkan/vulkan_core.h>
#include <system_error>

namespace yq::tachyon {
    class ViVisualizer;
    
    class ViTexture : public RefCount {
    public:
    
        ViTexture();
        ViTexture(ViVisualizer&, const Texture&);
        ViTexture(ViVisualizer&, const ViImageCPtr&, const ViSamplerCPtr&, const TextureInfo&);
        ~ViTexture();
        
        std::error_code     init(ViVisualizer&, const Texture&);
        void                kill();
    
        bool                consistent() const;
        VkExtent3D          extents() const;
        VkImage             image() const;
        VkImageView         image_view() const;
        VkSampler           sampler() const;
        uint64_t            texture_id() const { return m_id; }
        bool                valid() const;
    
    private:
        ViVisualizer*   m_viz           = nullptr;
        ViImageCPtr     m_image;
        ViSamplerCPtr   m_sampler;
        VkImageView     m_imageView;
        VkExtent3D      m_extents;
        uint64_t        m_id            = 0;

        std::error_code     _init(ViVisualizer&, const Texture&);
        std::error_code     _init(ViVisualizer&, const ViImageCPtr&, const ViSamplerCPtr&, const TextureInfo&);
        void                _kill();
    };

}
