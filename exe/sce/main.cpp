////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <yq/assetvk/io/FileIOManager.hpp>
#include <yq/core/Logging.hpp>
#include <yq/tachyon/api/Tachyon.hxx>
#include <yq/tedit/TEApp.hpp>
#include <yq/vkqt/app/YApp.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/process/PluginLoader.hpp>

#include "SCEApp.hpp"
#include "SCEMain.hpp"
//#include "SCEProject.hpp"

TypedID     gFileIO;
TypedID     gProjectID;

int main(int argc, char* argv[])
{
    AppCreateInfo       aci;
    aci.thread.io           = true;
    aci.thread.viewer       = PER;
    aci.view.title          = "Scenery Editor";
    aci.view.size           = { 1920, 1080 };
    aci.view.clear          = { 0.0f, 0.0f, 0.0f, 1.f };
    aci.view.imgui          = true;
    aci.view.resizable      = true;
    aci.view.depth_buffer   = ENABLE;
    aci.vulkan.graphics     = 16U;      // why not????

    SCEApp        app(argc, argv, aci);

    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    load_plugin_dir("plugin/xg");
    Meta::init();
    load_plugin_dir("plugin/xgvk");
    Meta::init();
    //load_plugin_dir("plugin/gtools");
    Meta::init();
    #ifdef YQ_LUA_ENABLE
    load_plugin_dir("plugin/lua");
    //load_plugin_dir("plugin/luavk");
    #endif
    
    Meta::freeze();
    app.info_resource_paths();
    app.start();
    app.info_std_threads();

    gFileIO     = Tachyon::create_on<FileIOManager>(IO)->typed_id();
    //gProjectID  = Tachyon::create_on<SCEProject>(IO)->typed_id();
    
    SCEMain*w           = Tachyon::create<SCEMain>();
    w -> show();
    app.run();
    return 0;
}
