////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    Simple "demo" utilitiy
*/

#include <io/PluginLoader.hpp>
#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/widget/ImGuiDemo.hpp>
#include <iostream>

using namespace yq;
using namespace yq::tachyon;

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
    
    Ref<Viewer>     v   = new Viewer(wi, new widget::ImGuiDemo);
    app.run(v.ptr(), { 0.0 });
    return 0;
}
