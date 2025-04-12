////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIImage.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yt/typedef/texture.hpp>
#include <yq/core/Ref.hpp>

namespace yq::tachyon {
    class UIAssetImageWriter;
    class UIAssetImage : public UIImage {
        YQ_OBJECT_DECLARE(UIAssetImage, UIImage)
    public:
        using Writer = UIAssetImageWriter;
        
        UIAssetImage(std::string_view, UIFlags flags={});
        UIAssetImage(std::string_view, const Size2F&, UIFlags flags={});
        UIAssetImage(const UIAssetImage&);
        ~UIAssetImage();
        
        UIAssetImage* clone() const;
        
        static void init_info();
        
    protected:
        void    render() override;
    
    private:
    
        static TextureCPtr  load(std::string_view);
    
        void    load();
    
        TextureCPtr     m_texture;
        ImTextureID     m_textureId = {};
        std::string     m_texturePath;
        
        struct {
            Size2F      actual  = ZERO;
            Size2F      spec    = ZERO;
            Size2F      min     = ZERO;
            Size2F      max     = ZERO;
            Size2F      display = ZERO;
            Vector2I    aspect  = ZERO;
        } m_size;
    };
}
