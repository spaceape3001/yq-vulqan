////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UICenterAlign.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    UICenterAlign::UICenterAlign(UIFlags flags) : UIElements(flags)
    {
    }
    
    UICenterAlign::UICenterAlign(const UICenterAlign& cp) : UIElements(cp)
    {
    }
    
    UICenterAlign::~UICenterAlign()
    {
    }
    
    UICenterAlign* UICenterAlign::clone() const
    {
        return new UICenterAlign(*this);
    }

    void        UICenterAlign::render()
    {
        if(m_width > 0)
            ImGui::Dummy({ m_width, 1 });
        Vector2F    b   = ImGui::GetCursorPos();
        content();
        Vector2F    c   = ImGui::GetCursorPos();
        float       x   = 0.5*(b.x+c.x);
        m_width        += ImGui::GetWindowWidth()*0.5 - x;
    }
}
