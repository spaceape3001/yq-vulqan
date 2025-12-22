////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneEditor.hpp"

#include <yq/assetvk/io/FileIOManager.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/core/Logging.hpp>
#include <yq/file/FileResolver.hpp>
#include <yq/process/PluginLoader.hpp>
#include <yq/tachyon/api/Tachyon.hxx>

TypedID     gFileIO;

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.thread.auxillary    = true;
    aci.thread.io           = true;
    aci.thread.edit         = true;
    aci.view.title          = "Scenery Editor";
    aci.view.size           = { 1920, 1080 };
    aci.view.clear          = { 0.0f, 0.0f, 0.0f, 1.f };
    aci.view.imgui          = true;
    aci.view.resizable      = true;
    //aci.view.depth_buffer   = ENABLE;
    
    Application app(argc, argv, aci);
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    
    #ifdef YQ_LUA_ENABLE
    load_plugin_dir("plugin/lua");
    load_plugin_dir("plugin/luavk");
    #endif
    
    Meta::freeze();
    
    for(const std::filesystem::path& pth : Resource::all_paths())
        yInfo() << "resource path> " << pth;
    
    app.start();
    
    for(StdThread st : StdThread::all_values())
        yInfo() << "thread " << st.key() << "> " << Thread::standard(st).id;
    
    //  TODO
    //std::vector< ResourceTBD > open
    
    gFileIO             = Tachyon::create_on<FileIOManager>(IO)->typed_id();
    SceneEditor* w      = Widget::create<SceneEditor>([&](SceneEditor& se){
        for(int n=1;n<argc;++n)
            se._import(argv[n]);
    });
    app.run(w);
    return 0;
}

