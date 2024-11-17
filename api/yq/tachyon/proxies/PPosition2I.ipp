////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition2I.hpp"

namespace yq::tachyon {
    PPosition2I::PPosition2I(IPosition2I& i) : m_interface(i), m_position(i.position2i())
    {
    }

    void        PPosition2I::position2i(set_t, const Vector2I& v) 
    {
        dispatch([=,this](){ m_interface.position2i(SET, v); });
    }
    
    void        PPosition2I::position2i(move_t, const Vector2I& v) 
    {
        dispatch([=,this](){ m_interface.position2i(MOVE, v); });
    }
}
