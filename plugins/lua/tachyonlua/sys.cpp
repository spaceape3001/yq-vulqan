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
#include <yq/luavk/vm/extract.hpp>
#include <yq/luavk/vm/id.hxx>
#include <yq/luavk/vm/push.hxx>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/app/Application.hpp>
#include <yq/text/match.hpp>

#include <lua.hpp>

#include <yq/lua/lualua.hxx>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::lua;
using namespace yq::tachyon;

namespace {
    static int lh_app_name(lua_State* l)
    {
        lua::push(l, (std::string_view) Application::app_name());
        return 1;
    }
    
    static int lh_headless(lua_State*l)
    {
        if(Application* a = Application::app()){
            if(lua_gettop(l) > 0){
                a->set_headless(lua_toboolean(l,1));
                return 0;
            } else {
                lua_pushboolean(l, a->is_headless());
                return 1;
            }
        } else
            return 0;
    }

    static int lh_thread_current(lua_State* l)
    {
        lua::push(l, ANY, Thread::current_id());
        return 1;
    }
    
    static int  lh_thread_get(lua_State* l)
    {
        auto stx    = stdThread(l,1);
        if(!stx){
            lua_pushnil(l);
            return 1;
        }
        
        push(l, Thread::standard(*stx));
        return 1;
    }
    
    static int   lh_thread_set(lua_State* l)
    {
        auto stx    = stdThread(l,1);
        if(!stx)
            return 0;
        
        Application*    app = Application::app();
        if(!app)
            return 0;
            
        StdThread   st  = *stx;
        switch(lua_type(l,2)){
        case LUA_TBOOLEAN:
            app->set_thread(st, static_cast<bool>(lua_toboolean(l, 2)));
            break;
        case LUA_TSTRING:
            {
                std::string_view cmd = lua_tostring(l,2);
                bool ok;
                if(is_similar(cmd, "per")){
                    app->set_thread(st, PER);
                    break;
                }
                
                StdThread   st2(cmd, &ok);
                if(ok){
                    app->set_thread(st, st2);
                    break;
                }
            }
            break;
        }
    
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
        using namespace yq::lua;
        if(ModuleInfo* mi = reg(MODULE, "sys")){
            if(FunctionInfo* fi = mi->add("appname", lh_app_name)){
                fi->brief("Application name");
            }
            
            if(FunctionInfo* fi = mi->add("headless", lh_headless)){
                fi->brief("Get/Set headless mode (set only valid before start)");
            }
            
            if(FunctionInfo* fi = mi->add("thread", lh_thread)){
                fi->brief("Get/Set standard threads (set only valid before start)");
            }
        }
    }

    YQ_INVOKE(reg_sys();)
}
