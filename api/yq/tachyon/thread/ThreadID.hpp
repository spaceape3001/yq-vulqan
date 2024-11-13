////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <yq/tachyon/core/TachyonID.hpp>

namespace yq::tachyon {
    struct ThreadID {
        uint64_t    id  = 0ULL;
        constexpr auto operator<=>(const ThreadID&) const noexcept = default;
        constexpr operator TachyonID() const noexcept { return { id }; }
    };
}
