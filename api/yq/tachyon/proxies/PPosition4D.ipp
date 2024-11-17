////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition4D.hpp"

namespace yq::tachyon {
    PPosition4D::PPosition4D(IPosition4D& i) : m_interface(i), m_position(i.position4d())
    {
    }

    void        PPosition4D::position4d(set_t, const Vector4D& v) 
    {
        dispatch([=,this](){ m_interface.position4d(SET, v); });
    }
    
    void        PPosition4D::position4d(move_t, const Vector4D& v) 
    {
        dispatch([=,this](){ m_interface.position4d(MOVE, v); });
    }
}
