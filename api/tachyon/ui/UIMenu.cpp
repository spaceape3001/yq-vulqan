////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenu.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>

#include "imgui_internal.h"

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
int ocnt = (int) ImGui::GetCurrentContext()->CurrentWindowStack.Size;    
        if(ImGui::BeginMenu(m_name.c_str())){
            content();
            ImGui::EndMenu();
        }
int ncnt = (int) ImGui::GetCurrentContext()->CurrentWindowStack.Size;
assert(ocnt == ncnt);
    }

    const char*   UIMenu::title() const 
    {
        return m_name.c_str();
    }

}
