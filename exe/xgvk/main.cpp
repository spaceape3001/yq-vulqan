////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGWin.hpp"
#include <yq/process/PluginLoader.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/tachyon/api/Tachyon.hxx>

#include <iostream>

using namespace yq;
using namespace yq::tachyon;

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    
    aci.view.clear          = { 0.005f, 0.005f, 0.005f, 1.f };
    aci.view.imgui          = true;
    aci.view.resizable      = true;
    aci.view.size           = { 1920, 1080 };
    aci.view.title          = "Executive Graph";

    Application app(argc, argv, aci);
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    load_plugin_dir("plugin/xg");
    Meta::init();
    load_plugin_dir("plugin/xgvk");
    Meta::init();
    Meta::freeze();
    
    app.start();
    
    XGWin* w   = XGWin::create<XGWin>();
    app.run(w);
    return 0;
}
