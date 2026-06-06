////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/model.hpp>
#include <yq/typedef/vector3.hpp>
#include <yq/unit/declare.hpp>
#include <functional>

namespace yq::tachyon {
    using FNAcceleration³M   = std::function<MeterPerSecond²3D(ModelID)>;
}

