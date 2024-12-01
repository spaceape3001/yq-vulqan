////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition3M.hpp"

namespace yq::tachyon {
    PPosition3M::PPosition3M(IPosition3M& i) : m_interface(i), m_position(i.position3m())
    {
    }

    void        PPosition3M::position3m(set_t, const Vector3M& v) 
    {
        dispatch([=,this](){ m_interface.position3m(SET, v); });
    }
    
    void        PPosition3M::position3m(move_t, const Vector3M& v) 
    {
        dispatch([=,this](){ m_interface.position3m(MOVE, v); });
    }
}
