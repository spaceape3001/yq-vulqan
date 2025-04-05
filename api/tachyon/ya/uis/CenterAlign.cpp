////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CenterAlign.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    CenterAlign::CenterAlign()
    {
    }
    
    CenterAlign::CenterAlign(const CenterAlign& cp) : UIItems(cp)
    {
    }
    
    CenterAlign::~CenterAlign()
    {
    }
    
    CenterAlign* CenterAlign::clone() const
    {
        return new CenterAlign(*this);
    }

    void        CenterAlign::render()
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
