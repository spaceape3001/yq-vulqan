////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaWin.hpp"

#include <yq/lua/lualua.hpp>
#include <yq/luavk/LuaTVM.hpp>
#include <yq/process/PluginLoader.hpp>
#include <yq/tachyon/application.hpp>
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
    
    lua::initialize();

    app.start();
    
    Ref<LuaTVM> tvm = LuaTVM::create<LuaTVM>();
    Ref<LuaWin> w   = LuaWin::create<LuaWin>(tvm->id());
    
    tvm->subscribe(w->id());
    w->subscribe(tvm->id());
    
    tvm -> subscribe(w->id());
    tvm -> owner(PUSH, AUXILLARY);
    
    app.run(w);
    return 0;
}
