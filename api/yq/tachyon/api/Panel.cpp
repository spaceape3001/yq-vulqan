////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Panel.hpp>
#include <yq/tachyon/api/PanelMetaWriter.hpp>
#include <yq/tachyon/MyImGui.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Panel)

namespace yq::tachyon {
    PanelMeta::PanelMeta(std::string_view n, WidgetMeta& base, const std::source_location& sl) : WidgetMeta(n, base, sl)
    {
    }

    Panel::Panel()
    {
    }
    
    Panel::~Panel()
    {
    }
    
    /*
    void    Panel::imgui(ViContext&u)
    {
        if(metaInfo().menu_bar()){
            if(ImGui::BeginMainMenuBar()){
                menubar_(u);
                ImGui::EndMainMenuBar();
            }
        }
        Widget::imgui(u);
        content_(u);
    }
    */
    
    void Panel::init_meta()
    {
        auto w = writer<Panel>();
        w.description("Panel base");
    }
}
