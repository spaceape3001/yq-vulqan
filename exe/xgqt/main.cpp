////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Tachyon.hxx>
#include <yq/vkqt/app/YApp.hpp>
#include <yq/process/PluginLoader.hpp>
#include "MainWindow.hpp"

using namespace yq;
using namespace yq::tachyon;

int main(int argc, char* argv[])
{
    AppCreateInfo   aci;
    aci.thread.viewer   = false;
    aci.vulkan.enable   = false;
    aci.platform        = Platform::None;
    YApp            app(argc, argv, aci);
    
    Meta::init();
    load_plugin_dir("plugin/xg");
    Meta::init();
    load_plugin_dir("plugin/xgvk");
    Meta::init();
    Meta::freeze();

    app.start();
    auto mw   = Tachyon::create<MainWindow>();
    mw -> cmdNewTab();
    mw -> show();
    app.run();
    return 0;
}
