////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIRightAlign.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

namespace yq::tachyon {
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
}
