////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition1D.hpp"

namespace yq::tachyon {
    PPosition1D::PPosition1D(IPosition1D& i) : m_interface(i), m_position(i.position1d())
    {
    }

    void        PPosition1D::position1d(set_t, const Vector1D& v) 
    {
        dispatch([=,this](){ m_interface.position1d(SET, v); });
    }
    
    void        PPosition1D::position1d(move_t, const Vector1D& v) 
    {
        dispatch([=,this](){ m_interface.position1d(MOVE, v); });
    }
}
