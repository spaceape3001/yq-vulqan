////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/MetaBinder.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    YQ_ENUM(AxisRemap,,
        XYZ,
        XZY,
        YXZ,
        YZX,
        ZXY,
        ZYX
    )
    
    template <typename T>
    constexpr Vector3<T> remap(AxisRemap a, const Vector3<T>& v)
    {
        switch(a){
        case AxisRemap::XYZ:
            return v;
        case AxisRemap::XZY:
            return { v.x, v.z, v.y };
        case AxisRemap::YXZ:
            return { v.y, v.x, v.z };
        case AxisRemap::YZX:
            return { v.y, v.z, v.x };
        case AxisRemap::ZXY:
            return { v.z, v.x, v.y };
        case AxisRemap::ZYX:
            return { v.z, v.y, v.z };
        default:    
            return v;
        }
    }
}

YQ_TYPE_DECLARE(yq::tachyon::AxisRemap)
