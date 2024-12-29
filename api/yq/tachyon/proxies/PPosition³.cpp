////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition³.hpp"
#include <yq/tachyon/commands/MoveBy³.hpp>
#include <yq/tachyon/commands/MoveByˣ.hpp>
#include <yq/tachyon/commands/MoveByʸ.hpp>
#include <yq/tachyon/commands/MoveByᶻ.hpp>
#include <yq/tachyon/commands/SetPosition³.hpp>
#include <yq/tachyon/commands/SetPositionˣ.hpp>
#include <yq/tachyon/commands/SetPositionʸ.hpp>
#include <yq/tachyon/commands/SetPositionᶻ.hpp>

namespace yq::tachyon {
    PPosition³::PPosition³(const IPosition³& i) : m_position(i.position())
    {
        if(i.position(DISABLED))
            m_flags |= F::Disabled;
        if(i.position(SETTABLE))
            m_flags |= F::Settable;
        if(i.position(MOVEABLE))
            m_flags |= F::Moveable;
    }

    PPosition³::~PPosition³()
    {
    }

    bool        PPosition³::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition³::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition³::position(moveable_k) const 
    {
        return m_flags(F::Moveable);
    }
        
    void        PPosition³::position(set_k, const Vector3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition³(id(), v));
        }
    }

    void        PPosition³::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣ(id(), x));
        }
    }
    
    void        PPosition³::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸ(id(), y));
        }
    }
    
    void        PPosition³::position(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻ(id(), z));
        }
    }

    void        PPosition³::position(move_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveBy³(id(), Δ));
        }
    }

    void        PPosition³::position(move_k, x_k, double Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByˣ(id(), Δx));
        }
    }

    void        PPosition³::position(move_k, y_k, double Δy) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByʸ(id(), Δy));
        }
    }

    void        PPosition³::position(move_k, z_k, double Δz) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByᶻ(id(), Δz));
        }
    }
}
