////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition3I.hpp"

namespace yq::tachyon {
    PPosition3I::PPosition3I(IPosition3I& i) : m_interface(i), m_position(i.position3i())
    {
    }

    void        PPosition3I::position3i(set_t, const Vector3I& v) 
    {
        dispatch([=,this](){ m_interface.position3i(SET, v); });
    }
    
    void        PPosition3I::position3i(move_t, const Vector3I& v) 
    {
        dispatch([=,this](){ m_interface.position3i(MOVE, v); });
    }
}
