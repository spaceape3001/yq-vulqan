////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/keywords.hpp>
#include <yq/tachyon/enum/DataActivity.hpp>

namespace yq::tachyon {

    // IF we define these in the toolbox, we'll derive the types
    struct common_t {
        consteval operator DataActivity() const noexcept { return DataActivity::COMMON; }
    };
    struct dynamic_t {
        consteval operator DataActivity() const noexcept { return DataActivity::DYNAMIC; }
    };
    struct fixed_t {
        consteval operator DataActivity() const noexcept { return DataActivity::FIXED; }
    };
    struct refresh_t {
        consteval operator DataActivity() const noexcept { return DataActivity::REFRESH; }
    };
    struct static_t {
        consteval operator DataActivity() const noexcept { return DataActivity::STATIC; }
    };
    
    struct probe_t {};
    struct close_t {};

    static constexpr close_t        CLOSE;
    static constexpr common_t       COMMON;
    static constexpr dynamic_t      DYNAMIC;
    static constexpr fixed_t        FIXED;
    static constexpr probe_t        PROBE;
    static constexpr refresh_t      REFRESH;
    static constexpr static_t       STATIC;
}
