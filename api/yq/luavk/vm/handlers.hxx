////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/lua/impl.hpp>
#include <yq/lua/keys.hpp>
#include <yq/lua/lualua.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <lua.hpp>

namespace yq::lua {
    template <typename T>
    bool lh_id_push(lua_State*l, const tachyon::ID<T>& tid)
    {
        lua_newtable(l);
        int n   = lua_gettop(l);
        _push(l, tid.id);
        lua_setfield(l, n, keyID);
        return true;
    }
    
    template <typename T>
    bool lh_id_extract(lua_State*l, int n, tachyon::ID<T>& tid)
    {
        tid.id  = _id(l, n);
        return true;
    }

}
