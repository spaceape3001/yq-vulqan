////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenuWriter.hpp"
#include "UIMenuBarWriter.hpp"
#include "UIMenuItemWriter.hpp"

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/tachyon/ui/input/UICheckBox_Simple.hpp>
#include <yq/tachyon/ui/input/UICheckBox_Visible.hpp>
#include <yq/tachyon/ui/input/UICheckBoxWriter.hpp>
#include <yq/tachyon/ui/layout/UISeparatorWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIMenu)

namespace yq::tachyon {
    void UIMenu::init_meta()
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

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

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
