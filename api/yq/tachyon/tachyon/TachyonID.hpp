////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>

namespace yq::tachyon {
    struct TachyonID {
        uint64_t    id  = 0ULL;
        constexpr auto operator<=>(const TachyonID&) const noexcept = default;
        constexpr operator uint64_t() const noexcept { return id; }
    };
}
