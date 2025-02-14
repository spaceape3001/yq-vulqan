////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>
#include <yq/typedef/axbox3.hpp>
#include <yq/typedef/sphere3.hpp>

namespace yq::tachyon {
    using bounds³_t = std::variant<std::monostate, AxBox3D, Sphere3D>;
}
