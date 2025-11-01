////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/accessor.hpp>
#include <yq/tachyon/api/Accessor.hpp>
#include <yq/core/Tristate.hpp>
#include <string_view>
#include <memory>

namespace yq::tachyon {
    using BooleanAccessor       = TypedAccessor<bool>;
    using DoubleAccessor        = TypedAccessor<double>;
    using FloatAccessor         = TypedAccessor<float>;
    using IntAccessor           = TypedAccessor<int>;
    using StringAccessor        = TypedAccessor<std::string_view>;
    using TristateAccessor      = TypedAccessor<Tristate>;
    using UInt64Accessor        = TypedAccessor<uint64_t>;
    
    using BooleanAccessorUPtr   = std::unique_ptr<BooleanAccessor>;
    using TristateAccessorUPtr  = std::unique_ptr<TristateAccessor>;
    
}
