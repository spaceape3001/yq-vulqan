////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UITabbed.hpp"
#include "UITabbedWriter.hpp"

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/tachyon/ui/UIElementsWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UITabbed)

namespace yq::tachyon {
    UITabbed::UITabbed(std::string_view k, UIFlags flgs) : UIPanel(k,flgs)
    {
    }
    
    UITabbed::UITabbed(const UITabbed& cp) : UIPanel(cp), m_selected(cp.m_selected)
    {
    }
        
    UITabbed* UITabbed::clone() const
    {
        return new UITabbed(*this);
    }
        
    void    UITabbed::content()
    {
        if(m_items.empty())
            return ;
            
        if(ImGui::BeginTabBar("UITabbed", ImGuiTabBarFlags_NoCloseWithMiddleMouseButton)){
            UIElement*      current = nullptr;
            m_selected      = std::clamp<int>(m_selected, 1, (int) m_items.size());

            int         cnt = 0;
            for(UIElement* i : m_items){
                ++cnt;
                std::string tabname;
                const char* title   = i->title();
                if(!title || !*title){
                    tabname = std::format("Tab{}##Tab{}", cnt, cnt);
                } else {
                    tabname = std::format("{}##Tab{}", title, cnt);
                }
                
                ImGuiTabItemFlags itflags = 0;
                if(cnt == m_selected)
                    itflags |= ImGuiTabItemFlags_SetSelected;
                
                
                if(ImGui::BeginTabItem(tabname.c_str(), nullptr, itflags)){
                    current = i;
                    ImGui::EndTabItem();
                }
            }
            
            assert(current != nullptr);
            if(current)
                current->render();
           ImGui::EndTabBar(); 
        }
    }

    void UITabbed::init_meta()
    {
        auto w = writer<UITabbed>();
    }
    
    /////////////////////////////////////

    
    UITabbedWriter::UITabbedWriter() = default;
    UITabbedWriter::UITabbedWriter(const UITabbedWriter&) = default;
    UITabbedWriter::~UITabbedWriter() = default;
    
    UITabbed* UITabbedWriter::element()
    {
        return static_cast<UITabbed*>(m_ui);
    }
    
    UITabbedWriter::UITabbedWriter(UITabbed* ui) : UIPanelWriter(ui)
    {
    }

}

