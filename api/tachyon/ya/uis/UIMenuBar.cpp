////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenuBar.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    UIMenuBar::UIMenuBar() : m_isMain(false)
    {
    }
    
    UIMenuBar::UIMenuBar(main_k) : m_isMain(true)
    {
    }

    UIMenuBar::UIMenuBar(const UIMenuBar&cp) : UIItems(cp), m_isMain(cp.m_isMain)
    {
    }
    
    UIMenuBar::~UIMenuBar()
    {
    }

    UIMenuBar*    UIMenuBar::clone() const
    {
        return new UIMenuBar(*this);
    }
   
    void        UIMenuBar::render() 
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
