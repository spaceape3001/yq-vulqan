////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "AxisRemap.hpp"

namespace yq::tachyon {
    static void reg_axisremap()
    {
        AxisRemap::pretty(AxisRemap::X_Y_Z_, "X+ Y+ Z+");
        AxisRemap::pretty(AxisRemap::X_Y_Zn, "X+ Y+ Z-");
        AxisRemap::pretty(AxisRemap::X_YnZ_, "X+ Y- Z+");
        AxisRemap::pretty(AxisRemap::X_YnZn, "X+ Y- Z-");
        AxisRemap::pretty(AxisRemap::XnY_Z_, "X- Y+ Z+");
        AxisRemap::pretty(AxisRemap::XnY_Zn, "X- Y+ Z-");
        AxisRemap::pretty(AxisRemap::XnYnZ_, "X- Y- Z+");
        AxisRemap::pretty(AxisRemap::XnYnZn, "X- Y- Z-");
        
        AxisRemap::pretty(AxisRemap::X_Z_Y_, "X+ Z+ Y+");
        AxisRemap::pretty(AxisRemap::X_Z_Yn, "X+ Z+ Y-");
        AxisRemap::pretty(AxisRemap::X_ZnY_, "X+ Z- Y+");
        AxisRemap::pretty(AxisRemap::X_ZnYn, "X+ Z- Y-");
        AxisRemap::pretty(AxisRemap::XnZ_Y_, "X- Z+ Y+");
        AxisRemap::pretty(AxisRemap::XnZ_Yn, "X- Z+ Y-");
        AxisRemap::pretty(AxisRemap::XnZnY_, "X- Z- Y+");
        AxisRemap::pretty(AxisRemap::XnZnYn, "X- Z- Y-");
        
        AxisRemap::pretty(AxisRemap::Y_X_Z_, "Y+ X+ Z+");
        AxisRemap::pretty(AxisRemap::Y_X_Zn, "Y+ X+ Z-");
        AxisRemap::pretty(AxisRemap::Y_XnZ_, "Y+ X- Z+");
        AxisRemap::pretty(AxisRemap::Y_XnZn, "Y+ X- Z-");
        AxisRemap::pretty(AxisRemap::YnX_Z_, "Y- X+ Z+");
        AxisRemap::pretty(AxisRemap::YnX_Zn, "Y- X+ Z-");
        AxisRemap::pretty(AxisRemap::YnXnZ_, "Y- X- Z+");
        AxisRemap::pretty(AxisRemap::YnXnZn, "Y- X- Z-");
        
        AxisRemap::pretty(AxisRemap::Y_Z_X_, "Y+ Z+ X+");
        AxisRemap::pretty(AxisRemap::Y_Z_Xn, "Y+ Z+ X-");
        AxisRemap::pretty(AxisRemap::Y_ZnX_, "Y+ Z- X+");
        AxisRemap::pretty(AxisRemap::Y_ZnXn, "Y+ Z- X-");
        AxisRemap::pretty(AxisRemap::YnZ_X_, "Y- Z+ X+");
        AxisRemap::pretty(AxisRemap::YnZ_Xn, "Y- Z+ X-");
        AxisRemap::pretty(AxisRemap::YnZnX_, "Y- Z- X+");
        AxisRemap::pretty(AxisRemap::YnZnXn, "Y- Z- X-");

        AxisRemap::pretty(AxisRemap::Z_X_Y_, "Z+ X+ Y+");
        AxisRemap::pretty(AxisRemap::Z_X_Yn, "Z+ X+ Y-");
        AxisRemap::pretty(AxisRemap::Z_XnY_, "Z+ X- Y+");
        AxisRemap::pretty(AxisRemap::Z_XnYn, "Z+ X- Y-");
        AxisRemap::pretty(AxisRemap::ZnX_Y_, "Z- X+ Y+");
        AxisRemap::pretty(AxisRemap::ZnX_Yn, "Z- X+ Y-");
        AxisRemap::pretty(AxisRemap::ZnXnY_, "Z- X- Y+");
        AxisRemap::pretty(AxisRemap::ZnXnYn, "Z- X- Y-");

        AxisRemap::pretty(AxisRemap::Z_Y_X_, "Z+ Y+ X+");
        AxisRemap::pretty(AxisRemap::Z_Y_Xn, "Z+ Y+ X-");
        AxisRemap::pretty(AxisRemap::Z_YnX_, "Z+ Y- X+");
        AxisRemap::pretty(AxisRemap::Z_YnXn, "Z+ Y- X-");
        AxisRemap::pretty(AxisRemap::ZnY_X_, "Z- Y+ X+");
        AxisRemap::pretty(AxisRemap::ZnY_Xn, "Z- Y+ X-");
        AxisRemap::pretty(AxisRemap::ZnYnX_, "Z- Y- X+");
        AxisRemap::pretty(AxisRemap::ZnYnXn, "Z- Y- X-");
    }
    
    YQ_INVOKE(reg_axisremap();)
}
