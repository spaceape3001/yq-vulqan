////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MenuBar.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    MenuBar::MenuBar() : m_isMain(false)
    {
    }
    
    MenuBar::MenuBar(main_k) : m_isMain(true)
    {
    }

    MenuBar::MenuBar(const MenuBar&cp) : UIItems(cp), m_isMain(cp.m_isMain)
    {
    }
    
    MenuBar::~MenuBar()
    {
    }

    MenuBar*    MenuBar::clone() const
    {
        return new MenuBar(*this);
    }
   
    void        MenuBar::render() 
    {
        if(m_isMain){
            if(ImGui::BeginMainMenuBar()){
                content();
                ImGui::EndMainMenuBar();
            }
        } else {
            if(ImGui::BeginMenuBar()){
                content();
                ImGui::EndMenuBar();
            }
        }
    }
}
