////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/core/DelayInit.hpp>
#include <yq/lua/info.hpp>
#include <yq/lua/logging.hpp>
#include <yq/lua/lualua.hpp>
#include <yq/lua/keys.hpp>
#include <yq/lua/info/FunctionInfo.hpp>
#include <yq/lua/info/ModuleInfo.hpp>
#include <yq/luavk/LuaID.hxx>
#include <yq/tachyon/api/Scene.hpp>

#include <lua.hpp>

#include <yq/lua/lualua.hxx>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::tachyon;

namespace {
    void reg_scene()
    {
        if(auto* tti = lua::reg<SceneID>()){
            tti->pusher(lua_pushID<Scene>);
            tti->extractor(lua_extractID<Scene>);
        }
    }


    YQ_INVOKE(reg_scene();)
}
