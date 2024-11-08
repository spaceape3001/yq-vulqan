////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>
#include <vector>
#include <yq/keywords.hpp>

namespace yq::tachyon {
    using QueueSpec   = std::variant<std::monostate, bool, optional_t, uint32_t, std::vector<float>>;
}
