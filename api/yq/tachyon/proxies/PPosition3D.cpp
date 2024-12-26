////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition3D.hpp"
#include <yq/tachyon/commands/AdjustPosition3D.hpp>
#include <yq/tachyon/commands/SetPosition3D.hpp>

namespace yq::tachyon {
    PPosition3D::PPosition3D(const IPosition3D& i)
    {
        if(i.position3d(DISABLED))
            m_flags |= F::Disabled;
        if(i.position3d(SETTABLE))
            m_flags |= F::Settable;
        if(i.position3d(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition3D::position3d(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition3D::position3d(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition3D::position3d(adjustable_k) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition3D::position3d(set_k, const Vector3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition3D(id(), v));
        }
    }
    
    void        PPosition3D::position3d(adjust_k, const Vector3D& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition3D(id(), v));
        }
    }
}
