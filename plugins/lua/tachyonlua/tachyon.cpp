////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/core/DelayInit.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/lua/info.hpp>
#include <yq/lua/logging.hpp>
#include <yq/lua/lualua.hpp>
#include <yq/lua/keys.hpp>
#include <yq/lua/info/FunctionInfo.hpp>
#include <yq/lua/info/ModuleInfo.hpp>
#include <yq/luavk/vm/id.hxx>
#include <yq/luavk/vm/extract.hpp>
#include <yq/meta/ObjectMeta.hpp>
#include <yq/meta/TypeMeta.hpp>
#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Reply.hpp>
#include <yq/tachyon/api/Request.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/api/InterfaceMeta.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/text/match.hpp>
#include <lua.hpp>

#include <yq/lua/lualua.hxx>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::tachyon;

namespace {
    int lh_tachyon_metas(lua_State* l)
    {
        lua_newtable(l);
        int ti = lua_gettop(l);
        int cnt = 0;
        for(const TachyonMeta* tm : TachyonMeta::all()){
            lua_pushinteger(l, ++cnt);
            lua::push(l, META, tm);
            lua_settable(l, ti);
        }
        return 1;
    }
    
    int lh_tid_meta(lua_State* l)
    {
        if(lua_gettop(l) < 1)
            return 0;
        auto tidx   = tachyonID(l, 1);
        if(!tidx)
            return 0;
        if(const Frame* f = Frame::current()){
            lua::push(l, f->meta(*tidx));
            return 1;
        }
        return 0;
    }
    
    int lh_tid_name(lua_State*l)
    {
        if(lua_gettop(l) < 1)
            return 0;
        auto tidx   = tachyonID(l, 1);
        if(!tidx)
            return 0;
        
        if(const Frame* f = Frame::current()){
            if(const TachyonSnap* sn = f->snap(*tidx)){
                lua::push(l, sn->name);
                return 1;
            }
        }
        return 0;
    }
    
    int  lh_tid_type(lua_State*l)
    {
        if(lua_gettop(l) < 1)
            return 0;
        auto tidx   = tachyonID(l, 1);
        if(!tidx){
        luaError << "Not a tachyon ID!";
            return 0;
        }
        
        if(const Frame* f = Frame::current()){
            if(const Tachyon* obj = f->object(*tidx)){
                lua::push(l, obj->metaInfo().name());
                return 1;
            }
luaError << "No tachyon";
        }
        return 0;
    }

    int lh_tm_interfaces(lua_State* l)
    {
        int nargs   = lua_gettop(l);
        for(int n=1;n<=nargs;++n){
            std::set<const PostMeta*>   seen;
            lua_newtable(l);
            int ti  = lua_gettop(l);
            int cnt = 0;

            auto mm  = lua::meta(l,n);
            if(!mm)
                continue;
            const TachyonMeta* tm = dynamic_cast<const TachyonMeta*>(*mm);
            if(!tm)
                continue;
            for(auto & i : tm->interfaces(true).all){
                lua_pushinteger(l, ++cnt);
                lua::push(l, META, i);
                lua_settable(l, ti);
            }
        }
        return nargs;
    }
    
    int lh_tm_slots(lua_State* l)
    {
        int nargs   = lua_gettop(l);
        for(int n=1;n<=nargs;++n){
            std::set<const PostMeta*>   seen;
            lua_newtable(l);
            int ti  = lua_gettop(l);
            int cnt = 0;

            auto mm  = lua::meta(l,n);
            if(!mm)
                continue;
            const TachyonMeta* tm = dynamic_cast<const TachyonMeta*>(*mm);
            if(!tm)
                continue;
            for(auto & i : tm->dispatch_map()){
                if(!seen.insert(i.first).second)
                    continue;
                lua_pushinteger(l, ++cnt);
                lua::push(l, META, i.first);
                lua_settable(l, ti);
            }
        }
        return nargs;
    }
    
    void reg_tachyon()
    {
        using namespace yq::lua;
        if(ModuleInfo* mi = reg(MODULE, "meta")){
            if(FunctionInfo* fi = mi -> add("tachyon", lh_object_meta_as<Tachyon>)){
                fi -> brief("Looks up tachyon meta");
            }
            if(FunctionInfo* fi = mi -> add("tachyons", lh_tachyon_metas)){
                fi -> brief("Returns all tachyon metas");
            }
        }
        
        if(ModuleInfo* mi = reg(META, meta<Tachyon>())){
            if(FunctionInfo* fi = mi -> add("interfaces", lh_tm_interfaces)){
                fi -> brief("Returns all interfaces on the meta");
            }
            if(FunctionInfo* fi = mi -> add("slots", lh_tm_slots)){
                fi->brief("Returns all slots on the meta");
            }
        }
        
        if(auto* tti = reg<TachyonID>()){
            tti->pusher(lua_pushID<Tachyon>);
            tti->extractor(lua_extractID<Tachyon>);
            tti->add("meta", lh_tid_meta);
            tti->add("name", lh_tid_name);
            tti->add("type", lh_tid_type);
        }
    }
    
    YQ_INVOKE(reg_tachyon();)
}

