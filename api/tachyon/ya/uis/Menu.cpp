////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Menu.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    Menu::Menu(std::string_view kv) : m_name(kv)
    {
    }
    
    Menu::Menu(const Menu&cp) : UIItems(cp), m_name(cp.m_name)
    {
    }
    
    Menu::~Menu()
    {
    }
    
    Menu*     Menu::clone() const 
    {
        return new Menu(*this);
    }

    void        Menu::render() 
    {
        if(ImGui::BeginMenu(m_name.c_str())){
            content();
            ImGui::EndMenu();
        }
    }
}
