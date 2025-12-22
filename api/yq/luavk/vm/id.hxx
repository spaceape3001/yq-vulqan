////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/lua/push.hpp>
#include <yq/lua/set.hpp>
#include <lua.hpp>

namespace yq::tachyon {
    template <typename T>
    bool    lua_pushID(lua_State* l, const ID<T>& tid) 
    {
        lua_newtable(l);
        lua::set(l, -1, TABLE, "id", (int) tid.id);     // eventually more
        return true;
    }
    
    template <typename T>
    bool    lua_extractID(lua_State* l, int n, ID<T>& tid)
    {
        auto x  = lua::integer(l, n, TABLE, "id");
        if(!x)
            return false;
        tid.id  = *x;
        return true;
    };
}
