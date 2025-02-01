////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/typedef/accessor.hpp>
#include <yt/api/Accessor.hpp>
#include <string_view>

namespace yq::tachyon {
    using DoubleAccessor        = TypedAccessor<double>;
    using FloatAccessor         = TypedAccessor<float>;
    using IntAccessor           = TypedAccessor<int>;
    using StringAccessor        = TypedAccessor<std::string_view>;
    using UInt64Accessor        = TypedAccessor<uint64_t>;
}
