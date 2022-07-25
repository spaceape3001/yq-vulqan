////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    Simple "demo" utilitiy
*/

#include <basic/Logging.hpp>
#include <basic/PluginLoader.hpp>
#include <basic/meta/Meta.hpp>
#include <basic/meta/ObjectInfoWriter.hpp>
#include <engine/Application.hpp>
#include <engine/Viewer.hpp>
#include <engine/vulqan/VqUtils.hpp>
#include <MyImGui.hpp>
#include <iostream>

using namespace yq;
using namespace yq::engine;

class DemoWindow : public Viewer {
    YQ_OBJECT_DECLARE(DemoWindow, Viewer)
public:
    DemoWindow(const ViewerCreateInfo & wci=ViewerCreateInfo ()) : Viewer(wci)
    {
    }
    
    ~DemoWindow()
    {
    }
    
    void   draw_imgui() override 
    {
        ImGui::ShowDemoWindow();
    }
};

YQ_OBJECT_IMPLEMENT(DemoWindow)

int main(int argc, char* argv[])
{
    AppCreateInfo        vi;
    vi.app_name     = "im_demo";

    Application app(argc, argv, vi);
    load_plugin_dir("plugin");
    app.finalize();
    
    ViewerCreateInfo      wi;
    wi.title        = "ImGUI Demo!";
    wi.clear        = { 0.0, 0.2, 0.5, 1. };
    wi.resizable    = true;
    wi.imgui        = true;
    //wi.pmode        = VK_PRESENT_MODE_IMMEDIATE_KHR;  // <-< Set this if you want to see how fast your CPU & GPU can go!  (Metrics under Tools menu.)
    Ref<DemoWindow>   window  = new DemoWindow(wi);
    
    app.run_window(window.ptr(), 0.0);
    return 0;
}
