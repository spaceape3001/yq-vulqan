////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaWin.hpp"

#include <yq/lua/lualua.hpp>
#include <yq/process/PluginLoader.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/tachyon/LuaTVM.hpp>
#include <yq/tachyon/api/Tachyon.hxx>

using namespace yq;
using namespace yq::lua;
using namespace yq::tachyon;


int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    
    aci.thread.auxillary    = true;
    aci.thread.sim          = true;
    aci.view.clear          = { 0.005f, 0.005f, 0.005f, 1.f };
    aci.view.imgui          = true;
    aci.view.resizable      = true;
    aci.view.size           = { 1920, 1080 };
    aci.view.title          = "LUA!";

    Application app(argc, argv, aci);
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    load_plugin_dir("plugin/lua");
    Meta::init();
    load_plugin_dir("plugin/luavk");
    Meta::init();
    
    for(int n=1;n<argc;++n){
        std::string_view    arg(argv[n]);
        if(argv[n][0] != '-')
            continue;
        if(argv[n][1] == '-')
            break;
        switch(argv[n][1]){
        case 'L':
            {
                std::filesystem::path   bit(2+argv[n]);
                std::filesystem::path   path;
                
                if(std::filesystem::exists(bit)){
                    path    = bit;
                } else if(std::filesystem::exists("plugin"/bit)){
                    path    = "plugin" / bit;
                } else {
                    path    = bit;
                }
                
                load_plugin_dir(path);
            }
            break;
        }
    }
    
    
    lua::initialize();

    app.start();
    
    Ref<LuaTVM> tvm = LuaTVM::create<LuaTVM>();
    Ref<LuaWin> w   = LuaWin::create<LuaWin>(*tvm);
    
    tvm->subscribe(w->id());
    w->subscribe(tvm->id());
    
    tvm -> subscribe(w->id());
    tvm -> owner(PUSH, AUXILLARY);
    
    app.run(w);
    return 0;
}
