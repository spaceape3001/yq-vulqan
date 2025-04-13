////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIAssetImage.hpp"
#include "UIAssetImageWriter.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/gfx/Raster.hpp>
#include <yt/gfx/Texture.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>
#include <yt/ui/UIStyle.hpp>
#include <ya/rasters/DebugRasters.hpp>
#include <yt/logging.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIAssetImage)

namespace yq::tachyon {
    
    void UIAssetImage::init_info()
    {
        auto w = writer<UIAssetImage>();
        w.description("Image loaded from an asset");
    }


    /////////////////////

    UIAssetImage::UIAssetImage(std::string_view path, UIFlags flags) : UIAssetImage(path, ZERO, flags)
    {
    }
    
    UIAssetImage::UIAssetImage(std::string_view path, const Size2F&size, UIFlags flags) : UIImage(flags)
    {
        m_size.spec     = size;
        m_texturePath   = std::string(path);
        load();
    }
    
    UIAssetImage::UIAssetImage(const UIAssetImage&cp) : UIImage(cp), m_texture(cp.m_texture),
        m_textureId(cp.m_textureId), m_texturePath(cp.m_texturePath),
        m_size(cp.m_size)
    {
        if(!m_texture)
            load();
    }
    
    UIAssetImage::~UIAssetImage()
    {
    }

    UIAssetImage* UIAssetImage::clone() const
    {
        return new UIAssetImage(*this);
    }
        
    void    UIAssetImage::render() 
    {
        if(m_size.display == Size2F{})
            return ;
    
        if(!m_textureId && !m_status(S::TextureIdFailed) && m_texture){
            m_textureId = install(m_texture);
            if(!m_textureId)
                m_status |= S::TextureIdFailed;
        }

        if(m_textureId){
            ImGui::Image(m_textureId, m_size.display);
        } else {
            ImGui::Dummy(m_size.display);
        }
    }

    void UIAssetImage::load()
    {
        m_texture = texture(m_texturePath);
        if(!m_texture || (m_texture->images.size() != 1)){
            m_status       |= S::LoadFailed;
            m_texture       = new Texture(debug::raster_missing());
        } else {
            m_status       -= S::LoadFailed;
            Size4U sz       = m_texture->images[0]->info.size;
            m_size.actual   = { (float) sz.x, (float) sz.y };
        }
        
        // Right now, no intelligence... desired size
        m_size.display      = m_size.spec;
    }
        
    /////////////////////

    UIAssetImageWriter::UIAssetImageWriter() = default;
    UIAssetImageWriter::UIAssetImageWriter(const UIAssetImageWriter&) = default;
    UIAssetImageWriter::~UIAssetImageWriter() = default;
    
    UIAssetImage* UIAssetImageWriter::element()
    {
        return static_cast<UIAssetImage*>(m_ui);
    }
    
    UIAssetImageWriter::UIAssetImageWriter(UIAssetImage* ui) : UIImageWriter(ui)
    {
    }
}

