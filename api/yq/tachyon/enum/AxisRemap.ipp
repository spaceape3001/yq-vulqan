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
        auto & em = enumeration<AxisRemap>(WRITE);
        
        em.pretty(AxisRemap::X_Y_Z_, "X+ Y+ Z+");
        em.pretty(AxisRemap::X_Y_Zn, "X+ Y+ Z-");
        em.pretty(AxisRemap::X_YnZ_, "X+ Y- Z+");
        em.pretty(AxisRemap::X_YnZn, "X+ Y- Z-");
        em.pretty(AxisRemap::XnY_Z_, "X- Y+ Z+");
        em.pretty(AxisRemap::XnY_Zn, "X- Y+ Z-");
        em.pretty(AxisRemap::XnYnZ_, "X- Y- Z+");
        em.pretty(AxisRemap::XnYnZn, "X- Y- Z-");
        
        em.pretty(AxisRemap::X_Z_Y_, "X+ Z+ Y+");
        em.pretty(AxisRemap::X_Z_Yn, "X+ Z+ Y-");
        em.pretty(AxisRemap::X_ZnY_, "X+ Z- Y+");
        em.pretty(AxisRemap::X_ZnYn, "X+ Z- Y-");
        em.pretty(AxisRemap::XnZ_Y_, "X- Z+ Y+");
        em.pretty(AxisRemap::XnZ_Yn, "X- Z+ Y-");
        em.pretty(AxisRemap::XnZnY_, "X- Z- Y+");
        em.pretty(AxisRemap::XnZnYn, "X- Z- Y-");
        
        em.pretty(AxisRemap::Y_X_Z_, "Y+ X+ Z+");
        em.pretty(AxisRemap::Y_X_Zn, "Y+ X+ Z-");
        em.pretty(AxisRemap::Y_XnZ_, "Y+ X- Z+");
        em.pretty(AxisRemap::Y_XnZn, "Y+ X- Z-");
        em.pretty(AxisRemap::YnX_Z_, "Y- X+ Z+");
        em.pretty(AxisRemap::YnX_Zn, "Y- X+ Z-");
        em.pretty(AxisRemap::YnXnZ_, "Y- X- Z+");
        em.pretty(AxisRemap::YnXnZn, "Y- X- Z-");
        
        em.pretty(AxisRemap::Y_Z_X_, "Y+ Z+ X+");
        em.pretty(AxisRemap::Y_Z_Xn, "Y+ Z+ X-");
        em.pretty(AxisRemap::Y_ZnX_, "Y+ Z- X+");
        em.pretty(AxisRemap::Y_ZnXn, "Y+ Z- X-");
        em.pretty(AxisRemap::YnZ_X_, "Y- Z+ X+");
        em.pretty(AxisRemap::YnZ_Xn, "Y- Z+ X-");
        em.pretty(AxisRemap::YnZnX_, "Y- Z- X+");
        em.pretty(AxisRemap::YnZnXn, "Y- Z- X-");

        em.pretty(AxisRemap::Z_X_Y_, "Z+ X+ Y+");
        em.pretty(AxisRemap::Z_X_Yn, "Z+ X+ Y-");
        em.pretty(AxisRemap::Z_XnY_, "Z+ X- Y+");
        em.pretty(AxisRemap::Z_XnYn, "Z+ X- Y-");
        em.pretty(AxisRemap::ZnX_Y_, "Z- X+ Y+");
        em.pretty(AxisRemap::ZnX_Yn, "Z- X+ Y-");
        em.pretty(AxisRemap::ZnXnY_, "Z- X- Y+");
        em.pretty(AxisRemap::ZnXnYn, "Z- X- Y-");

        em.pretty(AxisRemap::Z_Y_X_, "Z+ Y+ X+");
        em.pretty(AxisRemap::Z_Y_Xn, "Z+ Y+ X-");
        em.pretty(AxisRemap::Z_YnX_, "Z+ Y- X+");
        em.pretty(AxisRemap::Z_YnXn, "Z+ Y- X-");
        em.pretty(AxisRemap::ZnY_X_, "Z- Y+ X+");
        em.pretty(AxisRemap::ZnY_Xn, "Z- Y+ X-");
        em.pretty(AxisRemap::ZnYnX_, "Z- Y- X+");
        em.pretty(AxisRemap::ZnYnXn, "Z- Y- X-");
    }
    
    YQ_INVOKE(reg_axisremap();)
}
