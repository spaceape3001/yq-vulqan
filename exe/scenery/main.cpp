////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneEditor.hpp"
#include "SceneApp.hpp"

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
//Common      gCommon;

//bool    Common::firstBuilt(uint64_t vid)
//{
    //lock_t _lock(m_mutex, true);
    //bool    ret = m_viewers.empty();
    //m_viewers.insert(vid);
    //return ret;
//}

//bool    Common::lastDestroyed(uint64_t vid)
//{
    //lock_t _lock(m_mutex, true);
    //m_viewers.erase(vid);
    //return m_viewers.empty();
//}


int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.thread.auxillary    = true;
    aci.thread.io           = true;
    aci.thread.edit         = true;
    aci.thread.viewer       = PER;
    aci.view.title          = "Scenery Editor";
    aci.view.size           = { 1920, 1080 };
    aci.view.clear          = { 0.0f, 0.0f, 0.0f, 1.f };
    aci.view.imgui          = true;
    aci.view.resizable      = true;
    aci.view.depth_buffer   = ENABLE;
    aci.vulkan.graphics     = 8U;

    SceneApp app(argc, argv, aci);
    
    for(auto& fp : app.respath())
        Resource::add_path(fp);
    configure_standand_resource_path();
    
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    
    #ifdef YQ_LUA_ENABLE
    load_plugin_dir("plugin/lua");
    load_plugin_dir("plugin/luavk");
    #endif
    
    for(auto& fp : app.plugins()){
        std::error_code ec;
        if(std::filesystem::is_directory(fp, ec)){
            load_plugin_dir(fp);
        } else {
            load_plugin(fp);
        }
    }
    
    Meta::freeze();
    for(const std::filesystem::path& pth : Resource::all_paths())
        yInfo() << "resource path> " << pth;
    
    app.start();
    
    for(StdThread st : StdThread::all_values())
        yInfo() << "thread " << st.key() << "> " << Thread::standard(st).id;
    
    gFileIO             = Tachyon::create_on<FileIOManager>(IO)->typed_id();
    SceneEditor* w      = Widget::create<SceneEditor>([&](SceneEditor& se){
        for(auto& fp : app.imports())
            se._import(fp);
    });
    app.run(w);
    return 0;
}

