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
#include <yq/text/match.hpp>

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
    
    std::vector<std::filesystem::path>  imports, plugins, vlibs;
    
    for(int n=1;n<argc;++n){
        if(argv[n][0] == '-'){
            std::string_view    rem(argv[n]+2);
            switch(argv[n][1]){
            case 'R':
                Resource::add_path(rem);
                break;
            case 'P':
                plugins.push_back(rem);
                break;
            }
        } else
            imports.push_back(argv[n]);
    }
    
    Application app(argc, argv, aci);
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    
    #ifdef YQ_LUA_ENABLE
    load_plugin_dir("plugin/lua");
    load_plugin_dir("plugin/luavk");
    #endif
    
    for(auto& fp : plugins){
        std::error_code ec;
        if(std::filesystem::is_directory(fp, ec)){
            load_plugin_dir(fp);
        } else {
            load_plugin(fp);
        }
    }
    
    Meta::freeze();
    
    //  TODO
    //std::vector< ResourceTBD > open

    for(const std::filesystem::path& pth : Resource::all_paths())
        yInfo() << "resource path> " << pth;
    
    app.start();
    
    for(StdThread st : StdThread::all_values())
        yInfo() << "thread " << st.key() << "> " << Thread::standard(st).id;
    
    gFileIO             = Tachyon::create_on<FileIOManager>(IO)->typed_id();
    SceneEditor* w      = Widget::create<SceneEditor>([&](SceneEditor& se){
        for(auto& fp : imports)
            se._import(fp);
    });
    app.run(w);
    return 0;
}

