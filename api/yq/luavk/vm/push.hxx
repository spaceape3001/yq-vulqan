////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/vm/push.hpp>

namespace yq::lua {
    template <typename T>
    std::error_code push(lua_State* l, const tachyon::ID<T>& id)
    {
        return _push(l, id.id, ::yq::meta<tachyon::ID<T>>());
    }
}
