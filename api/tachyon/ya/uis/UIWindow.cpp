////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIWindow.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>
#include <yq/shape/AxBox2.hxx>
#include <yq/vector/Vector2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIWindow)

namespace yq::tachyon {
    void UIWindow::init_info()
    {
        auto w = writer<UIWindow>();
        w.description("\"Window\" in ImGui (not to be confused with the OS/Desktop Window)");
    }

    UIWindow::UIWindow(std::string_view zTitle, UIFlags flags) : 
        UIElements(flags),
        m_title(zTitle), 
        m_imFlags(ImGui::WindowFlags(flags))
    {
    }
    
    UIWindow::UIWindow(const UIWindow& cp) : UIElements(cp), 
        m_title(cp.m_title),
        m_pivot(cp.m_pivot),
        m_position(cp.m_position),
        m_size(cp.m_size),
        m_imFlags(cp.m_imFlags)
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
        if(m_flags(UIFlag::Invisible))
            return ;
            
        bool    open  = true;
        if(m_flags.any({UIFlag::SetPosition, UIFlag::SetPositionOnce})){
            ImGui::SetNextWindowPos(m_position, 0, m_pivot);
            m_flags -= UIFlag::SetPositionOnce;
        }
        if(m_flags.any({UIFlag::SetSize, UIFlag::SetSizeOnce})){
            ImGui::SetNextWindowSize({m_size.x, m_size.y});
            m_flags -= UIFlag::SetSizeOnce;
        }
        if(ImGui::Begin(m_title.c_str(), m_flags(UIFlag::Closeable) ? &open : nullptr, m_imFlags)){
            content();
            
            m_actualPos     = ImGui::GetWindowPos();
            m_actualSize    = ImGui::GetWindowSize();
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

    AxBox2F UIWindow::viewport() const
    {
        return AxBox2F(UNION, m_actualPos, m_actualPos + m_actualSize );
    }
}
