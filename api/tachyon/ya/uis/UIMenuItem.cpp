////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenuItem.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    UIMenuItem::UIMenuItem(std::string_view kName, std::string_view kShortcut) : m_name(kName), m_shortcut(kShortcut)
    {
    }
    
    UIMenuItem::UIMenuItem(const UIMenuItem& cp) : UIElement(cp), m_name(cp.m_name), m_shortcut(cp.m_shortcut)
    {
    }
    
    UIMenuItem::~UIMenuItem()
    {
    }

    UIMenuItem*     UIMenuItem::clone() const 
    {
        return new UIMenuItem(*this);
    }
    
    void        UIMenuItem::render() 
    {
        const char* shortcut    = m_shortcut.empty() ? nullptr : m_shortcut.c_str();
        if(ImGui::MenuItem(m_name.c_str(), shortcut)){
            content();
        }
    }
}
