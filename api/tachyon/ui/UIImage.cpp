////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIImage.hpp"
#include "UIImageWriter.hpp"
#include <tachyon/ui/UIElementMetaWriter.hpp>
#include <tachyon/resource/Raster.hpp>
#include <tachyon/pipeline/Texture.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/ui/UIStyle.hpp>
#include <yq/text/format.hpp>
#include <tachyon/MyImGui.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIImage)

namespace yq::tachyon {

    void UIImage::init_meta()
    {
        auto w = writer<UIImage>();
        w.description("UI Image Element");
    }
    
    
    //////////////////////////

    UIImage::UIImage(UIFlags flags) : UIElement(flags)
    {
    }
    
    UIImage::UIImage(std::string_view name, UIFlags flags) : UIImage(texture(name), flags)
    {
        m_path          = std::string(name);
    }
    
    UIImage::UIImage(std::string_view name, const Size2F& size, UIFlags flags) : 
        UIImage(texture(name), size, flags)
    {
        m_path          = std::string(name);
    }
    
    UIImage::UIImage(const RasterCPtr& img, UIFlags flags) : UIImage(new Texture(img), flags)
    {
    }
    
    UIImage::UIImage(const RasterCPtr& img, const Size2F& size, UIFlags flags) : UIImage(new Texture(img), size, flags)
    {
    }
    
    UIImage::UIImage(const TextureCPtr& tex, UIFlags flags) : UIElement(flags), m_texture(tex)
    {
        _size();
    }
    
    UIImage::UIImage(const TextureCPtr&tex, const Size2F& size, UIFlags flags) : UIElement(flags), m_size(size), m_texture(tex)
    {
        _size();
    }

    UIImage::UIImage(const UIImage& cp) : UIElement(cp), 
        m_imId(cp.m_imId),
        m_path(cp.m_path),
        m_size(cp.m_size), 
        m_texture(cp.m_texture)
    {
        if(!m_texture && !m_path.empty()){
            m_texture   = texture(m_path);
            _size();
        }
    }
    
    UIImage::~UIImage()
    {
    }
    
    void    UIImage::_size()
    {
        if((m_size == Size2F{}) && m_texture && !m_texture->images.empty() && m_texture->images[0]){
            Size4U  sz  = m_texture->images[0]->info.size;
            m_size  = Size2F{ (float) sz.x, (float) sz.y };
        }
    }

    UIImage* UIImage::clone() const
    {
        UIImage tmp;
        return new UIImage(*this);
    }
    
    bool UIImage::is_button() const
    {
        return m_flags(UIFlag::IsButton) || !m_actions.empty();
    }

    void  UIImage::render() 
    {
        if(!m_image && !m_status(S::LoadFailed)){
            if(!m_texture && !m_path.empty()){
                m_texture   = texture(m_path);
                _size();
            }
            
            if(!m_texture || m_texture->images.empty()){
                m_status       |= S::LoadFailed;
                m_texture       = missing_texture();
            }
            
            if(m_size == Size2F{})
                m_size  = style().image.def_size;
                
            m_image     = install(m_texture);
            assert(m_image);        // Should *NEVER* fail.... (shouldn't)
            if(!m_image)
                m_status |= S::LoadFailed;
        }
        
        if(!m_image)
            return ;
        
        if(is_button()){  
            static std::atomic<uint64_t> indexer{1};
            if(m_imId.empty()){
                m_imId  = "##UImage-";
                m_imId += to_string_view(indexer++);
            }

            //  IMAGE BUTTON
            if(ImGui::ImageButton(m_imId.c_str(), m_image, m_size)){
                triggered();
            }

        } else {
            //  REGULAR IMAGE
            ImGui::Image(m_image, m_size);
        }
    }

    ////////////////////////////
    
    UIImageWriter::UIImageWriter() = default;
    UIImageWriter::UIImageWriter(const UIImageWriter&) = default;
    UIImageWriter::~UIImageWriter() = default;
    
    UIImage* UIImageWriter::element()
    {
        return static_cast<UIImage*>(m_ui);
    }
    
    UIImageWriter::UIImageWriter(UIImage* ui) : UIElementWriter(ui)
    {
    }

}
