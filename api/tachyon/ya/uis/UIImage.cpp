////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIImage.hpp"
#include "UIImageWriter.hpp"
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIImage)

namespace yq::tachyon {
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
    
    void UIImage::init_info()
    {
        auto w = writer<UIImage>();
        w.description("Image UI Element (base)");
    }
    
    //////////////////////////


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
