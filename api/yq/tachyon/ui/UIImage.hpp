////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/core/Ref.hpp>

namespace yq::tachyon {
    class UIImageWriter;

    //! An Image (singular)
    class UIImage : public UIElement {
        YQ_OBJECT_DECLARE(UIImage, UIElement)
    public:
    
        using Writer = UIImageWriter;
    
        UIImage(UIFlags flags={});
        UIImage(const UIImage&);
        
        UIImage(std::string_view, UIFlags flags={});
        UIImage(std::string_view, const Size2F& size, UIFlags flags={});
        UIImage(const RasterCPtr&, UIFlags flags={});
        UIImage(const RasterCPtr&, const Size2F& size, UIFlags flags={});
        UIImage(const TextureCPtr&, UIFlags flags={});
        UIImage(const TextureCPtr&, const Size2F& size, UIFlags flags={});
        
        ~UIImage();
        
        UIImage* clone() const;
        
        static void init_meta();
        
    protected:
    
        ImTextureID     m_image     = nullptr;

        //! ImGui "ID" (if we're a button)
        std::string     m_imId;
        
        //! In case load failed... first time
        std::string     m_path;

        //! Size of the image to show
        Size2F          m_size;
        
        //! Texture itself
        TextureCPtr     m_texture;
        
        void    _size();
    
        void    render() override;
        
        bool is_button() const;
    };
}
