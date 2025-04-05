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
        if(m_width > 0)
            ImGui::Dummy({ m_width, 1 });
        content();
        Vector2F    c   = ImGui::GetCursorPos();
        m_width        += ImGui::GetWindowWidth() - c.x;
    }
}
