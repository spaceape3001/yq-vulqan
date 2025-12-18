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
        X_Y_Z_,
        X_Y_Zn,
        X_YnZ_,
        X_YnZn,
        XnY_Z_,
        XnY_Zn,
        XnYnZ_,
        XnYnZn,
        
        X_Z_Y_,
        X_Z_Yn,
        X_ZnY_,
        X_ZnYn,
        XnZ_Y_,
        XnZ_Yn,
        XnZnY_,
        XnZnYn,
        
        Y_X_Z_,
        Y_X_Zn,
        Y_XnZ_,
        Y_XnZn,
        YnX_Z_,
        YnX_Zn,
        YnXnZ_,
        YnXnZn,
        
        Y_Z_X_,
        Y_Z_Xn,
        Y_ZnX_,
        Y_ZnXn,
        YnZ_X_,
        YnZ_Xn,
        YnZnX_,
        YnZnXn,

        Z_X_Y_,
        Z_X_Yn,
        Z_XnY_,
        Z_XnYn,
        ZnX_Y_,
        ZnX_Yn,
        ZnXnY_,
        ZnXnYn,
        
        Z_Y_X_,
        Z_Y_Xn,
        Z_YnX_,
        Z_YnXn,
        ZnY_X_,
        ZnY_Xn,
        ZnYnX_,
        ZnYnXn
    )
    
    template <typename T>
    constexpr Vector3<T> remap(AxisRemap a, const Vector3<T>& v)
    {
        switch(a){
        case AxisRemap::X_Y_Z_:
            return { +v.x, +v.y, +v.z };
        case AxisRemap::X_Y_Zn:
            return { +v.x, +v.y, -v.z };
        case AxisRemap::X_YnZ_:
            return { +v.x, -v.y, +v.z };
        case AxisRemap::X_YnZn:
            return { +v.x, -v.y, -v.z };
        case AxisRemap::XnY_Z_:
            return { -v.x, +v.y, +v.z };
        case AxisRemap::XnY_Zn:
            return { -v.x, +v.y, -v.z };
        case AxisRemap::XnYnZ_:
            return { -v.x, -v.y, +v.z };
        case AxisRemap::XnYnZn:
            return { -v.x, -v.y, -v.z };

        case AxisRemap::X_Z_Y_:
            return { +v.x, +v.z, +v.y };
        case AxisRemap::X_Z_Yn:
            return { +v.x, +v.z, -v.y };
        case AxisRemap::X_ZnY_:
            return { +v.x, -v.z, +v.y };
        case AxisRemap::X_ZnYn:
            return { +v.x, -v.z, -v.y };
        case AxisRemap::XnZ_Y_:
            return { -v.x, +v.z, +v.y };
        case AxisRemap::XnZ_Yn:
            return { -v.x, +v.z, -v.y };
        case AxisRemap::XnZnY_:
            return { -v.x, -v.z, +v.y };
        case AxisRemap::XnZnYn:
            return { -v.x, -v.z, -v.y };
            
        case AxisRemap::Y_X_Z_:
            return { +v.y, +v.x, +v.z };
        case AxisRemap::Y_X_Zn:
            return { +v.y, +v.x, -v.z };
        case AxisRemap::Y_XnZ_:
            return { +v.y, -v.x, +v.z };
        case AxisRemap::Y_XnZn:
            return { +v.y, -v.x, -v.z };
        case AxisRemap::YnX_Z_:
            return { -v.y, +v.x, +v.z };
        case AxisRemap::YnX_Zn:
            return { -v.y, +v.x, -v.z };
        case AxisRemap::YnXnZ_:
            return { -v.y, -v.x, +v.z };
        case AxisRemap::YnXnZn:
            return { -v.y, -v.x, -v.z };
            
            
        case AxisRemap::Y_Z_X_:
            return { +v.y, +v.z, +v.x };
        case AxisRemap::Y_Z_Xn:
            return { +v.y, +v.z, -v.x };
        case AxisRemap::Y_ZnX_:
            return { +v.y, -v.z, +v.x };
        case AxisRemap::Y_ZnXn:
            return { +v.y, -v.z, -v.x };
        case AxisRemap::YnZ_X_:
            return { -v.y, +v.z, +v.x };
        case AxisRemap::YnZ_Xn:
            return { -v.y, +v.z, -v.x };
        case AxisRemap::YnZnX_:
            return { -v.y, -v.z, +v.x };
        case AxisRemap::YnZnXn:
            return { -v.y, -v.z, -v.x };
            
            
        case AxisRemap::Z_X_Y_:
            return { +v.z, +v.x, +v.y };
        case AxisRemap::Z_X_Yn:
            return { +v.z, +v.x, -v.y };
        case AxisRemap::Z_XnY_:
            return { +v.z, -v.x, +v.y };
        case AxisRemap::Z_XnYn:
            return { +v.z, -v.x, -v.y };
        case AxisRemap::ZnX_Y_:
            return { -v.z, +v.x, +v.y };
        case AxisRemap::ZnX_Yn:
            return { -v.z, +v.x, -v.y };
        case AxisRemap::ZnXnY_:
            return { -v.z, -v.x, +v.y };
        case AxisRemap::ZnXnYn:
            return { -v.z, -v.x, -v.y };
            
        case AxisRemap::Z_Y_X_:
            return { +v.z, +v.y, +v.z };
        case AxisRemap::Z_Y_Xn:
            return { +v.z, +v.y, -v.z };
        case AxisRemap::Z_YnX_:
            return { +v.z, -v.y, +v.z };
        case AxisRemap::Z_YnXn:
            return { +v.z, -v.y, -v.z };
        case AxisRemap::ZnY_X_:
            return { -v.z, +v.y, +v.z };
        case AxisRemap::ZnY_Xn:
            return { -v.z, +v.y, -v.z };
        case AxisRemap::ZnYnX_:
            return { -v.z, -v.y, +v.z };
        case AxisRemap::ZnYnXn:
            return { -v.z, -v.y, -v.z };

        default:    
            return v;
        }
    }
}

YQ_TYPE_DECLARE(yq::tachyon::AxisRemap)
