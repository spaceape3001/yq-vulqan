////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/StdThread.hpp>
#include <yq/typedef/url.hpp>
#include <variant>

namespace yq::tachyon {
    using save_origin_t          = std::variant<std::monostate, std::string, Url>;
    using save_value_t           = std::variant<std::monostate, Any, uint64_t>;
    using save_key_t             = std::variant<std::monostate, uint32_t, std::string>;
    using save_u32_value_map_t   = std::map<uint32_t, save_value_t>;
    using save_str_value_map_t   = std::map<std::string, save_value_t, IgCase>;
    using save_str_value_xmap_t  = std::map<std::string, save_value_t>;

    using save_u32_value_mmap_t  = std::multimap<uint32_t, save_value_t>;
    using save_str_value_mmap_t  = std::multimap<std::string, save_value_t, IgCase>;
    using save_str_value_xmmap_t = std::multimap<std::string, save_value_t>;
    using uint32_u64_mmap_t     = std::multimap<uint32_t, uint64_t>;
    using owner_spec_t = std::variant<std::monostate, uint64_t, StdThread>;

}
