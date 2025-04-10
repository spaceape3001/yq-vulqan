////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenu.hpp"
#include "UIMenuWriter.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIMenu)

namespace yq::tachyon {
    void UIMenu::init_info()
    {
        auto w = writer<UIMenu>();
        w.description("Menu UI Element (ie collection of items)");
    }

    UIMenu::UIMenu(std::string_view kv, UIFlags flags) : UIElements(flags), m_name(kv)
    {
    }
    
    UIMenu::UIMenu(const UIMenu&cp) : UIElements(cp), m_name(cp.m_name)
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

    const char*   UIMenu::title() const 
    {
        return m_name.c_str();
    }

    ////////////////////////////

    UIMenuWriter::UIMenuWriter() = default;
    UIMenuWriter::UIMenuWriter(const UIMenuWriter&) = default;
    UIMenuWriter::~UIMenuWriter() = default;

    UIMenu* UIMenuWriter::element()
    {
        return static_cast<UIMenu*>(m_ui);
    }
    
    UIMenuWriter::UIMenuWriter(UIMenu* ui) : UIElementsWriter(ui)
    {
    }
}
