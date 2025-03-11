////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/typedef/vector1.hpp>
#include <yq/typedef/vector2.hpp>
#include <yq/typedef/vector3.hpp>
#include <yq/typedef/vector4.hpp>
#include <functional>

namespace yq::tachyon {
    
    //  May eventually move these to the toolbox

    using FNMapper11   = std::function<Vector1D(const Vector1D&)>;
    using FNMapper12   = std::function<Vector1D(const Vector2D&)>;
    using FNMapper13   = std::function<Vector1D(const Vector3D&)>;
    using FNMapper14   = std::function<Vector1D(const Vector4D&)>;

    using FNMapper21   = std::function<Vector2D(const Vector1D&)>;
    using FNMapper22   = std::function<Vector2D(const Vector2D&)>;
    using FNMapper23   = std::function<Vector2D(const Vector3D&)>;
    using FNMapper24   = std::function<Vector2D(const Vector4D&)>;

    using FNMapper31   = std::function<Vector3D(const Vector1D&)>;
    using FNMapper32   = std::function<Vector3D(const Vector2D&)>;
    using FNMapper33   = std::function<Vector3D(const Vector3D&)>;
    using FNMapper34   = std::function<Vector3D(const Vector4D&)>;
    
    using FNMapper41   = std::function<Vector4D(const Vector1D&)>;
    using FNMapper42   = std::function<Vector4D(const Vector2D&)>;
    using FNMapper43   = std::function<Vector4D(const Vector3D&)>;
    using FNMapper44   = std::function<Vector4D(const Vector4D&)>;
}
