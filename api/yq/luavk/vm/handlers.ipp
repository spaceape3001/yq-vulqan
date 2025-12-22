////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "handlers.hpp"
#include "handlers.hxx"
#include <yq/lua/keys.hpp>
#include <yq/lua/impl.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <lua.hpp>

namespace yq::tachyon {
    bool    lh_typedid_push(lua_State*l, const TypedID& typedId)
    {
        lua_newtable(l);
        int n = lua_gettop(l);
        lua::_push_id(l, (uint64_t) typedId.id);
        lua_setfield(l, n, lua::keyID); 
        return true;
    }
    
    bool    lh_typedid_extract(lua_State*l, int n, TypedID& typedId)
    {
        typedId.id  = lua::_id(l, n);
        const Frame* f  = Frame::current();
        if(f)
            typedId.types   = f->typed(TachyonID{typedId.id}).types;
        return true;
    }
}
