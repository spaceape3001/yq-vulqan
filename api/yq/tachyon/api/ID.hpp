////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>

namespace yq::tachyon {
    struct ID {
        uint64_t    id  = 0ULL;
        constexpr auto operator<=>(const ID&) const noexcept = default;
        constexpr operator uint64_t() const noexcept { return id; }
    };
}
