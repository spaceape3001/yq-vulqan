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
#include <yq/lua/info/FunctionInfo.hpp>
#include <yq/lua/info/ModuleInfo.hpp>
#include <yq/meta/ObjectMeta.hpp>
#include <yq/meta/TypeMeta.hpp>
#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/api/Reply.hpp>
#include <yq/tachyon/api/Request.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/api/InterfaceMeta.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/text/match.hpp>
#include <lua.hpp>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::tachyon;

namespace {
    int lh_tachyon_metas(lua_State* l)
    {
        int n   = 0;
        for(const TachyonMeta* tm : TachyonMeta::all()){
            lua::push(l, META, tm);
            ++n;
        }
        return n;
    }

    int lh_tm_interfaces(lua_State* l)
    {
        int nargs   = lua_gettop(l);
        for(int n=1;n<nargs;++n){
            auto mm  = lua::meta(l,n);
            if(!mm)
                continue;
            const TachyonMeta* tm = dynamic_cast<const TachyonMeta*>(*mm);
            if(!tm)
                continue;
            for(auto & i : tm->interfaces(true).all)
                lua::push(l, META, i);
        }
        return lua_gettop(l) - nargs;
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
        
        if(ModuleInfo* mi = reg(META, yq::meta<Tachyon>())){
            if(FunctionInfo* fi = mi -> add("interfaces", lh_tm_interfaces)){
                fi -> brief("Returns all interfaces on the meta");
            }
        }
        
    }
    
    YQ_INVOKE(reg_tachyon();)
}

