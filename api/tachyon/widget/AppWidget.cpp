////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppWidget.hpp"
#include "AppWidgetInfoWriter.hpp"
#include <tachyon/MyImGui.hpp>

namespace yq::tachyon {
    AppWidgetInfo::AppWidgetInfo(std::string_view zName, WidgetInfo& base, const std::source_location& sl) : WidgetInfo(zName, base, sl)
    {
        set(Flag::IMGUI);
    }
    
    ////////////////////

    void AppWidget::init_info()
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
