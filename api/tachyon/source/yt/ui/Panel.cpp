////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/ui/Panel.hpp>
#include <yt/ui/PanelInfoWriter.hpp>
#include <yt/ui/MyImGui.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Panel)

namespace yq::tachyon {
    PanelInfo::PanelInfo(std::string_view n, WidgetInfo& base, const std::source_location& sl) : WidgetInfo(n, base, sl)
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
    
    void Panel::init_info()
    {
        auto w = writer<Panel>();
        w.description("Panel base");
    }
}
