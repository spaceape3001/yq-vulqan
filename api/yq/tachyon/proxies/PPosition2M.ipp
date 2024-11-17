////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition2M.hpp"

namespace yq::tachyon {
    PPosition2M::PPosition2M(IPosition2M& i) : m_interface(i), m_position(i.position2m())
    {
    }

    void        PPosition2M::position2m(set_t, const Vector2M& v) 
    {
        dispatch([=,this](){ m_interface.position2m(SET, v); });
    }
    
    void        PPosition2M::position2m(move_t, const Vector2M& v) 
    {
        dispatch([=,this](){ m_interface.position2m(MOVE, v); });
    }
}
