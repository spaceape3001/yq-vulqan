////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition4M.hpp"

namespace yq::tachyon {
    PPosition4M::PPosition4M(IPosition4M& i) : m_interface(i), m_position(i.position4m())
    {
    }

    void        PPosition4M::position4m(set_t, const Vector4M& v) 
    {
        dispatch([=,this](){ m_interface.position4m(SET, v); });
    }
    
    void        PPosition4M::position4m(move_t, const Vector4M& v) 
    {
        dispatch([=,this](){ m_interface.position4m(MOVE, v); });
    }
}
