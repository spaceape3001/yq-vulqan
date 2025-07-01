////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppWidget.hpp"
#include "AppWidgetMetaWriter.hpp"
#include <tachyon/MyImGui.hpp>

namespace yq::tachyon {
    AppWidgetMeta::AppWidgetMeta(std::string_view zName, WidgetMeta& base, const std::source_location& sl) : WidgetMeta(zName, base, sl)
    {
        set(Flag::IMGUI);
    }
    
    ////////////////////

    void AppWidget::init_meta()
    {
        auto w = writer<AppWidget>();
        w.description("Application Widget");
    }
    
    AppWidget::AppWidget()
    {
    }
    
    AppWidget::~AppWidget()
    {
    }
    
    void    AppWidget::imgui(ViContext& u) 
    {
        if(menubar(ENABLED) && metaInfo().menu_bar()){
            if(ImGui::BeginMainMenuBar()){
                menubar(u);
                ImGui::EndMainMenuBar();
            }                
        }
        
        Widget::imgui(u);
        content(u);
        //  TODO....
    }

    unsigned    AppWidget::menubar(height_k, ViContext&) const
    {
        return menubar(HEIGHT);
    }

    unsigned    AppWidget::statusbar(height_k, ViContext&) const
    {
        return statusbar(HEIGHT);
    }
}

YQ_WIDGET_IMPLEMENT(yq::tachyon::AppWidget)
