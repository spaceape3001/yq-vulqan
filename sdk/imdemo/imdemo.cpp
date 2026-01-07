////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    Simple "demo" utilitiy
*/

#include <yq/process/PluginLoader.hpp>

#include <yq/tachyon/application.hpp>
#include <yq/assetvk/widget/ImGuiDemoWidget.hpp>

#include <iostream>
#include <yq/tachyon/api/Tachyon.hxx>

using namespace yq;
using namespace yq::tachyon;

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.app_name        = "im_demo";
    aci.view.title      = "ImGUI Demo!";
    aci.view.clear      = { 0.0, 0.2, 0.5, 1. };
    aci.view.resizable  = true;
    aci.view.imgui      = true;
    //aci.view.pmode        = VK_PRESENT_MODE_IMMEDIATE_KHR;  // <-< Set this if you want to see how fast your CPU & GPU can go!  (Metrics under Tools menu.)
    

    Application app(argc, argv, aci);
    load_plugin_dir("plugin");
    app.finalize();
    app.start();
    WidgetPtr   w   = Widget::create_on<ImGuiDemoWidget>(VIEWER);
    app.tick();
    app.run(w);
    return 0;
}
