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
        std::error_code ec  = _prime(l, tm, X::ID);
        if(ec != std::error_code())
            return ec;
        set(l, -1, TABLE, keyID, RAW, (void*) v);
        return {};
    }
}
