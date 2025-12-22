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
#include <yq/tachyon/api/Thread.hpp>

#include <lua.hpp>

#include <yq/lua/lualua.hxx>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::tachyon;

namespace {
    void reg_thread()
    {
        if(auto* tti = lua::reg<ThreadID>()){
            tti->pusher(lua_pushID<Thread>);
            tti->extractor(lua_extractID<Thread>);
        }
    }


    YQ_INVOKE(reg_thread();)
}
