////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition4I.hpp"

namespace yq::tachyon {
    PPosition4I::PPosition4I(IPosition4I& i) : m_interface(i), m_position(i.position4i())
    {
    }

    void        PPosition4I::position4i(set_t, const Vector4I& v) 
    {
        dispatch([=,this](){ m_interface.position4i(SET, v); });
    }
    
    void        PPosition4I::position4i(move_t, const Vector4I& v) 
    {
        dispatch([=,this](){ m_interface.position4i(MOVE, v); });
    }
}
