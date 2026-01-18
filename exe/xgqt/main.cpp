////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/core/Logging.hpp>
#include <yq/tachyon/api/Tachyon.hxx>
#include <yq/vkqt/app/YApp.hpp>
#include <yq/resource/Resource.hpp>
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
    //configure_standand_resource_path();
    
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    load_plugin_dir("plugin/xg");
    Meta::init();
    load_plugin_dir("plugin/xgvk");
    Meta::init();
    
    
    Meta::freeze();
    for(const std::filesystem::path& pth : Resource::all_paths())
        yInfo() << "resource path> " << pth;

    app.start();
    auto mw   = Tachyon::create<MainWindow>();
    mw -> cmdNewTab();
    mw -> show();
    app.run();
    return 0;
}
