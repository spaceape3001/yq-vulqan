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
#include <yq/tachyon/api/Camera.hpp>

#include <lua.hpp>

#include <yq/lua/lualua.hxx>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::tachyon;

namespace {
    void reg_camera()
    {
        if(auto* tti = lua::reg<CameraID>()){
            tti->pusher(lua_pushID<Camera>);
            tti->extractor(lua_extractID<Camera>);
        }
    }


    YQ_INVOKE(reg_camera();)
}
