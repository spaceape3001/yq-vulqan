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
        m_title(cp.m_title),
        m_pivot(cp.m_pivot),
        m_position(cp.m_position),
        m_flags(cp.m_flags), m_imFlags(cp.m_imFlags)
    {
    }
    
    UIWindow::~UIWindow()
    {
    }
    
    UIWindow*   UIWindow::clone() const
    {
        return new UIWindow(*this);
    }

    void    UIWindow::flag(set_k, UIFlag f)
    {
        m_flags.set(f);
        update(FLAGS);
    }
    
    void    UIWindow::flag(clear_k, UIFlag f)
    {
        m_flags.clear(f);
        update(FLAGS);
    }
    
    void        UIWindow::render()
    {
        if(m_flags(UIFlag::Invisible))
            return ;
            
        bool    open  = true;
        if(m_flags.any({UIFlag::SetPosition, UIFlag::SetPositionOnce})){
            ImGui::SetNextWindowPos(m_position, 0, m_pivot);
            m_flags -= UIFlag::SetPositionOnce;
        }
        if(ImGui::Begin(m_title.c_str(), m_flags(UIFlag::Closeable) ? &open : nullptr, m_imFlags)){
            content();
        }
        ImGui::End();
        if(!open){
            m_flags |= UIFlag::Invisible;  
            closing();
        }
    }
    
    const char*   UIWindow::title() const 
    {
        return m_title.c_str();
    }

    void    UIWindow::update(flags_k)
    {
        m_imFlags   = ImGui::WindowFlags(m_flags);
    }
}
