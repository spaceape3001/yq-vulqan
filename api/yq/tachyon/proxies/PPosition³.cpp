////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition3.hpp"
#include <yq/tachyon/commands/spatial/MoveBy3.hpp>
#include <yq/tachyon/commands/spatial/MoveByX.hpp>
#include <yq/tachyon/commands/spatial/MoveByY.hpp>
#include <yq/tachyon/commands/spatial/MoveByZ.hpp>
#include <yq/tachyon/commands/spatial/SetPosition3.hpp>
#include <yq/tachyon/commands/spatial/SetPositionX.hpp>
#include <yq/tachyon/commands/spatial/SetPositionY.hpp>
#include <yq/tachyon/commands/spatial/SetPositionZ.hpp>

namespace yq::tachyon {
    PPosition3::PPosition3(const IPosition3& i) : m_position(i.position())
    {
        if(i.position(DISABLED))
            m_flags |= F::Disabled;
        if(i.position(SETTABLE))
            m_flags |= F::Settable;
        if(i.position(MOVEABLE))
            m_flags |= F::Moveable;
    }

    PPosition3::~PPosition3()
    {
    }

    bool        PPosition3::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition3::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition3::position(moveable_k) const 
    {
        return m_flags(F::Moveable);
    }
        
    void        PPosition3::position(set_k, const Vector3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition3(id(), v));
        }
    }

    void        PPosition3::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionX(id(), x));
        }
    }
    
    void        PPosition3::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionY(id(), y));
        }
    }
    
    void        PPosition3::position(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionZ(id(), z));
        }
    }

    void        PPosition3::position(move_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveBy3(id(), Δ));
        }
    }

    void        PPosition3::position(move_k, x_k, double Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByX(id(), Δx));
        }
    }

    void        PPosition3::position(move_k, y_k, double Δy) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByY(id(), Δy));
        }
    }

    void        PPosition3::position(move_k, z_k, double Δz) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByZ(id(), Δz));
        }
    }
}
