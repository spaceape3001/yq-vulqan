////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIImage.hpp"
#include "UIImageWriter.hpp"
#include <yt/ui/UIElementInfoWriter.hpp>
#include <yt/gfx/Raster.hpp>
#include <yt/gfx/Texture.hpp>
#include <yt/logging.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIImage)

namespace yq::tachyon {

    void UIImage::init_info()
    {
        auto w = writer<UIImage>();
        w.description("Image UI Element (base)");
    }
    
    TextureCPtr      UIImage::texture(std::string_view path)
    {
        TextureCPtr  tex = Texture::load(path);
        if(tex)
            return tex;
        uiInfo << "Unable to load '" << path << "' as a texture, trying raster";
        RasterCPtr   ras = Raster::load(path);
        if(ras)
            return new Texture(ras);
        uiInfo << "Unable to load '" << path << "' as a raster image (sorry)";
        return {};
    }
    
    //////////////////////////

    UIImage::UIImage(UIFlags flags) : UIElement(flags)
    {
    }
    
    UIImage::UIImage(const UIImage& cp) : UIElement(cp)
    {
    }
    
    UIImage::~UIImage()
    {
    }
    
    UIImage* UIImage::clone() const
    {
        UIImage tmp;
        return new UIImage(*this);
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
