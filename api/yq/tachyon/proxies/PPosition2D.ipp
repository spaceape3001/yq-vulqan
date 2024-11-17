////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition2D.hpp"

namespace yq::tachyon {
    PPosition2D::PPosition2D(IPosition2D& i) : m_interface(i), m_position(i.position2d())
    {
    }

    void        PPosition2D::position2d(set_t, const Vector2D& v) 
    {
        dispatch([=,this](){ m_interface.position2d(SET, v); });
    }
    
    void        PPosition2D::position2d(move_t, const Vector2D& v) 
    {
        dispatch([=,this](){ m_interface.position2d(MOVE, v); });
    }
}
