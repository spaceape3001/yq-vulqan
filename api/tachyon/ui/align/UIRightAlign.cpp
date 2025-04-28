////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIRightAlign.hpp"
#include "UIRightAlignWriter.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIRightAlign)

namespace yq::tachyon {
    void UIRightAlign::init_info()
    {
        auto w = writer<UIRightAlign>();
        w.description("Right Alignment UI Element");
    }

    UIRightAlign::UIRightAlign(UIFlags flags) : UIElements(flags)
    {
    }
    
    UIRightAlign::UIRightAlign(const UIRightAlign& cp) : UIElements(cp)
    {
    }
    
    UIRightAlign::~UIRightAlign()
    {
    }
    
    UIRightAlign* UIRightAlign::clone() const
    {
        return new UIRightAlign(*this);
    }

    void        UIRightAlign::render()
    {
        if(m_width > 0)
            ImGui::Dummy({ m_width, 1 });
        content();
        Vector2F    c   = ImGui::GetCursorPos();
        m_width        += ImGui::GetWindowWidth() - c.x;
    }

    ////////////////////////////

    UIRightAlignWriter::UIRightAlignWriter() = default;
    UIRightAlignWriter::UIRightAlignWriter(const UIRightAlignWriter&) = default;
    UIRightAlignWriter::~UIRightAlignWriter() = default;

    UIRightAlign* UIRightAlignWriter::element()
    {
        return static_cast<UIRightAlign*>(m_ui);
    }
    
    UIRightAlignWriter::UIRightAlignWriter(UIRightAlign* ui) : UIElementsWriter(ui)
    {
    }
}
