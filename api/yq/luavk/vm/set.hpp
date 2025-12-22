////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::lua {
    std::error_code set(lua_State*, int, table_k, const char*, const tachyon::TypedID&);
    
    template <typename T>
    std::error_code set(lua_State*, int, table_k, const char*, const ID&);
    
}
