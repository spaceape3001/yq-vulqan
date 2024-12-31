////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition2.hpp"
#include <yq/tachyon/commands/spatial/MoveBy2.hpp>
#include <yq/tachyon/commands/spatial/MoveByX.hpp>
#include <yq/tachyon/commands/spatial/MoveByY.hpp>
#include <yq/tachyon/commands/spatial/SetPosition2.hpp>
#include <yq/tachyon/commands/spatial/SetPositionX.hpp>
#include <yq/tachyon/commands/spatial/SetPositionY.hpp>

namespace yq::tachyon {
    PPosition2::PPosition2(const IPosition2& i) : m_position(i.position())
    {
        if(i.position(DISABLED))
            m_flags |= F::Disabled;
        if(i.position(SETTABLE))
            m_flags |= F::Settable;
        if(i.position(MOVEABLE))
            m_flags |= F::Moveable;
    }

    bool        PPosition2::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition2::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition2::position(moveable_k) const 
    {
        return m_flags(F::Moveable);
    }
        
    void        PPosition2::position(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition2(id(), v));
        }
    }

    void        PPosition2::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionX(id(), x));
        }
    }
    
    void        PPosition2::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionY(id(), y));
        }
    }

    void        PPosition2::position(move_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            mail(new MoveBy2(id(), Δ));
        }
    }

    void        PPosition2::position(move_k, x_k, double Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByX(id(), Δx));
        }
    }

    void        PPosition2::position(move_k, y_k, double Δy) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByY(id(), Δy));
        }
    }
}
