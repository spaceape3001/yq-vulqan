////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenu.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    UIMenu::UIMenu(std::string_view kv) : m_name(kv)
    {
    }
    
    UIMenu::UIMenu(const UIMenu&cp) : UIItems(cp), m_name(cp.m_name)
    {
    }
    
    UIMenu::~UIMenu()
    {
    }
    
    UIMenu*     UIMenu::clone() const 
    {
        return new UIMenu(*this);
    }

    void        UIMenu::render() 
    {
        if(ImGui::BeginMenu(m_name.c_str())){
            content();
            ImGui::EndMenu();
        }
    }
}
