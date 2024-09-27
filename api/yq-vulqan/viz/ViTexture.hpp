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
        ~ViTexture();
        
        std::error_code     init(ViVisualizer&, const Texture&);
        void                kill();
    
        bool                consistent() const;
        VkExtent3D          extents() const;
        VkImage             image() const;
        VkImageView         image_view() const;
        VkSampler           sampler() const;
        bool                valid() const;
    
    private:
        ViVisualizer*   m_viz       = nullptr;
        ViImageCPtr     m_image;
        ViSamplerCPtr   m_sampler;
        VkImageView     m_imageView;
        VkExtent3D      m_extents;

        std::error_code     _init(ViVisualizer&, const Texture&);
        void                _kill();
    };

}
