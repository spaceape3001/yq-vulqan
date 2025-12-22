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
#include <yq/luavk/vm/id.hxx>
#include <yq/tachyon/api/Light.hpp>

#include <lua.hpp>

#include <yq/lua/lualua.hxx>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::tachyon;

namespace {
    void reg_light()
    {
        if(auto* tti = lua::reg<LightID>()){
            tti->pusher(lua_pushID<Light>);
            tti->extractor(lua_extractID<Light>);
        }
    }


    YQ_INVOKE(reg_light();)
}
