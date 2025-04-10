////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenuItem.hpp"
#include "UIMenuItemWriter.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIMenuItem)

namespace yq::tachyon {
    void UIMenuItem::init_info()
    {   
        auto w = writer<UIMenuItem>();
        w.description("UI Menu Item");
    }

    UIMenuItem::UIMenuItem(std::string_view kName, std::string_view kShortcut, UIFlags flags) : 
        UIElement(flags), m_name(kName), m_shortcut(kShortcut)
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

    const char*   UIMenuItem::title() const 
    {
        return m_name.c_str();
    }


    ////////////////////////////

    UIMenuItemWriter::UIMenuItemWriter() = default;
    UIMenuItemWriter::UIMenuItemWriter(const UIMenuItemWriter&) = default;
    UIMenuItemWriter::~UIMenuItemWriter() = default;

    UIMenuItem* UIMenuItemWriter::element()
    {
        return static_cast<UIMenuItem*>(m_ui);
    }
    
    UIMenuItemWriter::UIMenuItemWriter(UIMenuItem* ui) : UIElementWriter(ui)
    {
    }
}
