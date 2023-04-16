////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    struct always_t {};
    struct once_t {};
    struct skip_t {};

    static const constexpr always_t ALWAYS;
    static const constexpr once_t   ONCE;
    static const constexpr skip_t   SKIP;
}
