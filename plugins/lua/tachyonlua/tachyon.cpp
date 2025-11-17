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
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/text/match.hpp>
#include <lua.hpp>
#include <yq/lua/stdhandlers.hxx>

using namespace yq;
using namespace yq::lua;
using namespace yq::tachyon;

namespace {
    int lh_tachyon_metas(lua_State* l)
    {
        int n   = 0;
        for(const TachyonMeta* tm : TachyonMeta::all()){
            push(l, META, tm);
            ++n;
        }
        return n;
    }

    void reg_tachyon()
    {
        if(ModuleInfo* mi = reg(MODULE, "meta")){
            if(FunctionInfo* fi = mi -> add("command", lh_object_meta_as<Command>)){
                fi -> brief("Looks up command meta");
            }
            if(FunctionInfo* fi = mi -> add("event", lh_object_meta_as<Event>)){
                fi -> brief("Looks up event meta");
            }
            if(FunctionInfo* fi = mi -> add("post", lh_object_meta_as<Post>)){
                fi -> brief("Looks up post meta");
            }
            if(FunctionInfo* fi = mi -> add("reply", lh_object_meta_as<Reply>)){
                fi -> brief("Looks up reply meta");
            }
            if(FunctionInfo* fi = mi -> add("request", lh_object_meta_as<Request>)){
                fi -> brief("Looks up request meta");
            }
            if(FunctionInfo* fi = mi -> add("tachyon", lh_object_meta_as<Tachyon>)){
                fi -> brief("Looks up tachyon meta");
            }
            if(FunctionInfo* fi = mi -> add("tachyons", lh_tachyon_metas)){
                fi -> brief("Returns all tachyon metas");
            }
        }
    }
    
    YQ_INVOKE(reg_tachyon();)
}

