////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIWindow.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    UIWindow::UIWindow(std::string_view zTitle, UIFlags flags) : 
        m_title(zTitle), m_flags(flags), 
        m_imFlags(ImGui::WindowFlags(flags))
    {
    }
    
    UIWindow::UIWindow(const UIWindow& cp) : UIElements(cp), 
        m_title(cp.m_title), m_flags(cp.m_flags), m_imFlags(cp.m_imFlags)
    {
    }
    
    UIWindow::~UIWindow()
    {
    }
    
    UIWindow*   UIWindow::clone() const
    {
        return new UIWindow(*this);
    }
    
    void        UIWindow::render()
    {
        if(ImGui::Begin(m_title.c_str(), nullptr, m_imFlags)){
            content();
        }
        ImGui::End();
    }
    
    const char*   UIWindow::title() const 
    {
        return m_title.c_str();
    }
}
