////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>
#include <vector>
#include <yt/keywords.hpp>

namespace yq::tachyon {
    using QueueSpec   = std::variant<std::monostate, bool, optional_k, maximum_k, uint32_t, std::vector<float>>;

    size_t  count(const QueueSpec&);
    bool    is_empty(const QueueSpec&);
    bool    is_required(const QueueSpec&);
}
