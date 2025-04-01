////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/application.hpp>
#include "MainWidget.hpp"
#include <yt/ui/WidgetInfoWriter.hpp>
#include <iostream>

YQ_TACHYON_IMPLEMENT(MainWidget)

MainWidget::MainWidget()
{
}

MainWidget::~MainWidget()
{
}

void MainWidget::init_info()
{
    auto w = writer<MainWidget>();
    w.description("The main widget");
}


////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.thread.sim          = true;
    aci.view.title        = "Scenery Editor";
    aci.view.size         = { 1920, 1080 };
    aci.view.clear        = { 0.1f, 0.1f, 0.2f, 1.f };
    aci.view.imgui        = true;
    aci.view.resizable    = true;
    
    Application app(argc, argv, aci);
    app.start();
    
    MainWidget*     w   = Widget::create<MainWidget>();
    app.run(w);
    return 0;
}
