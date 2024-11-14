////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <yq/tachyon/api/ID.hpp>

namespace yq::tachyon {
    struct PluginID {
        uint64_t    id  = 0ULL;
        constexpr auto operator<=>(const PluginID&) const noexcept = default;
        constexpr operator uint64_t() const noexcept { return id; }
        constexpr operator ID() const noexcept { return { id }; }
    };
}
