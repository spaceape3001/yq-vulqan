////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MenuItem.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    MenuItem::MenuItem(std::string_view kName, std::string_view kShortcut) : m_name(kName), m_shortcut(kShortcut)
    {
    }
    
    MenuItem::MenuItem(const MenuItem& cp) : UIElement(cp), m_name(cp.m_name), m_shortcut(cp.m_shortcut)
    {
    }
    
    MenuItem::~MenuItem()
    {
    }

    MenuItem*     MenuItem::clone() const 
    {
        return new MenuItem(*this);
    }
    
    void        MenuItem::render() 
    {
        const char* shortcut    = m_shortcut.empty() ? nullptr : m_shortcut.c_str();
        if(ImGui::MenuItem(m_name.c_str(), shortcut)){
            content();
        }
    }
}
