////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RightAlign.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    RightAlign::RightAlign()
    {
    }
    
    RightAlign::RightAlign(const RightAlign& cp) : UIItems(cp)
    {
    }
    
    RightAlign::~RightAlign()
    {
    }
    
    RightAlign* RightAlign::clone() const
    {
        return new RightAlign(*this);
    }

    void        RightAlign::render()
    {
        Vector2F    w   = ImGui::GetContentRegionAvail();
        Vector2F    a   = ImGui::GetCursorPos();
        if(m_width > 0)
            ImGui::Dummy({ m_width, 1 });
        Vector2F    b   = ImGui::GetCursorPos();
        render(ITEMS);
        Vector2F    c   = ImGui::GetCursorPos();
        m_width        += w.x - c.x;
    }
}
