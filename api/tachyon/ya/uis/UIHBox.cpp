////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIHBox.hpp"
#include "UIHBoxWriter.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIHBox)

namespace yq::tachyon {
    void UIHBox::init_info()
    {
        auto w = writer<UIHBox>();
        w.description("Horizontal line of UI elements");
    }

    UIHBox::UIHBox(UIFlags flags) : UIElements(flags|UIFlag::Horizontal)
    {
    }
    
    UIHBox::UIHBox(const UIHBox& cp) : UIElements(cp)
    {
    }
    
    UIHBox::~UIHBox()
    {
    }
    
    UIHBox* UIHBox::clone() const
    {
        return new UIHBox(*this);
    }

    ////////////////////////////

    UIHBoxWriter::UIHBoxWriter() = default;
    UIHBoxWriter::UIHBoxWriter(const UIHBoxWriter&) = default;
    UIHBoxWriter::~UIHBoxWriter() = default;

    UIHBox* UIHBoxWriter::element()
    {
        return static_cast<UIHBox*>(m_ui);
    }
    
    UIHBoxWriter::UIHBoxWriter(UIHBox* ui) : UIElementsWriter(ui)
    {
    }

}

