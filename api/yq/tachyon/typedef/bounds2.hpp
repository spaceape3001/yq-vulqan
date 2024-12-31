////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>
#include <yq/typedef/axbox2.hpp>
#include <yq/typedef/circle2.hpp>

namespace yq::tachyon {
    using bounds²_t = std::variant<std::monostate, AxBox2D, Circle2D>;
}
