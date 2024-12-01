////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition1M.hpp"

namespace yq::tachyon {
    PPosition1M::PPosition1M(IPosition1M& i) : m_interface(i), m_position(i.position1m())
    {
    }

    void        PPosition1M::position1m(set_t, const Vector1M& v) 
    {
        dispatch([=,this](){ m_interface.position1m(SET, v); });
    }
    
    void        PPosition1M::position1m(move_t, const Vector1M& v) 
    {
        dispatch([=,this](){ m_interface.position1m(MOVE, v); });
    }
}
