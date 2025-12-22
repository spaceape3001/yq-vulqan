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
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/app/Application.hpp>

#include <lua.hpp>

#include <yq/lua/lualua.hxx>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::tachyon;

namespace {
    static int lh_thread_current(lua_State* l)
    {
        lua::push(l, ANY, Thread::current_id());
        return 1;
    }
    
    static int  lh_thread_get(lua_State* l)
    {
        auto x  = lua::string(l, 1);
        if(!x)
            return 0;
        
        bool    ok = false;
        StdThread  st(*x, &ok);
        if(!ok)
            return 0;
        
    
        return 0;
    }
    
    static int   lh_thread_set(lua_State* l)
    {
        return 0;
    }

    static int lh_thread(lua_State* l)
    {
        switch(lua_gettop(l)){
        case 0:
            return lh_thread_current(l);
        case 1:
            return lh_thread_get(l);
        case 2:
            return lh_thread_set(l);
        default:    
            return 0;
        }
    }

  
    void reg_sys()
    {
        if(ModuleInfo* mi = lua::reg(MODULE, "sys")){
        }
    }


    YQ_INVOKE(reg_sys();)
}
