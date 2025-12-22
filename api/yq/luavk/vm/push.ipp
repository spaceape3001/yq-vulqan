////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "push.hpp"
#include <yq/lua/errors.hpp>
#include <yq/lua/lualua.hpp>
#include <yq/lua/keys.hpp>
#include <yq/lua/impl.hpp>
#include <yq/tachyon/api/Frame.hpp>

namespace yq::lua {
    std::error_code _push(lua_State*l, uint64_t v, const TypeMeta& tm)
    {
        if(!l)  
            return errors::lua_null();
        lua_newtable(l);
        int n = lua_gettop(l);
        _push_id(l, v);
        lua_setfield(l, n, keyID);
        _meta_add(l, tm);
        return {};
    }
}
