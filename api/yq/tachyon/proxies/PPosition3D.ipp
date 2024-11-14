////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "PPosition3D.hpp"
#include <yq/tachyon/api/ProxyWriter.hpp>

namespace yq::tachyon {
    PPosition3D::PPosition3D(Tachyon* t, IPosition3D& i, const Vector3D& p, uint64_t rev) : 
        Proxy(t, rev), m_interface(i), m_position(p)
    {
    }

    void        PPosition3D::position3d(set_t, const Vector3D& v) 
    {
        dispatch([=](){ this.m_interface.position3d(SET, v) });
    }
    
    void        PPosition3D::position3d(move_t, const Vector3D& v) 
    {
        dispatch([=](){ this.m_interface.position3d(MOVE, v) });
    }

    Proxy*    PPosition3D::reproxy() const 
    {
        Vector3D        pos = m_interface.position3d();
        if(m_position != pos)
            return new PPosition3D(object(), m_interface, pos, revision()+1);
        return nullptr;
    }
}
