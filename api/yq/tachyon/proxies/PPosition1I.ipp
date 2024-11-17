////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition1I.hpp"

namespace yq::tachyon {
    PPosition1I::PPosition1I(IPosition1I& i) : m_interface(i), m_position(i.position1i())
    {
    }

    void        PPosition1I::position1i(set_t, const Vector1I& v) 
    {
        dispatch([=,this](){ m_interface.position1i(SET, v); });
    }
    
    void        PPosition1I::position1i(move_t, const Vector1I& v) 
    {
        dispatch([=,this](){ m_interface.position1i(MOVE, v); });
    }
}
