////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition3D.hpp"

namespace yq::tachyon {
    PPosition3D::PPosition3D(IPosition3D& i) : m_interface(i), m_position(i.position3d())
    {
    }

    void        PPosition3D::position3d(set_t, const Vector3D& v) 
    {
        dispatch([=,this](){ m_interface.position3d(SET, v); });
    }
    
    void        PPosition3D::position3d(move_t, const Vector3D& v) 
    {
        dispatch([=,this](){ m_interface.position3d(MOVE, v); });
    }
}
