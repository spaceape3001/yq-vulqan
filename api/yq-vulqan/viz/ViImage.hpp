////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/shape/Size4.hpp>
#include <yq-toolbox/typedef/size4.hpp>
#include <yq-vulqan/image/ImageInfo.hpp>
#include <vk_mem_alloc.h>
#include <vulkan/vulkan_core.h>
#include <system_error>


namespace yq::tachyon {
    class ViVisualizer;
    class Image;
    class ViImage : public RefCount {
    public:
    
        ViImage();
        ViImage(ViVisualizer&, const Image&);
        ~ViImage();
        
        std::error_code init(ViVisualizer&, const Image&);
        void            kill();
        
        bool            consistent() const;
        bool            valid() const;
        
        operator VkImage() const { return m_image; }
        VkImage         image() const { return m_image; }
        VmaAllocation   allocation() const { return m_allocation; }
        ViVisualizer*   visualizer() const { return m_viz; }
        const ImageInfo&    info() const { return m_info; }
    
    private:
        ViVisualizer*       m_viz           = nullptr;
        VmaAllocation       m_allocation    = nullptr;
        VkImage             m_image         = nullptr;
        ImageInfo           m_info          = {};
        
        ViImage(const ViImage&) = delete;
        ViImage(ViImage&&) = delete;
        ViImage& operator=(const ViImage&) = delete;
        ViImage& operator=(ViImage&&) = delete;
        
        std::error_code _init(ViVisualizer&, const Image&);
        void            _wipe();
        void            _kill();
    };
}
