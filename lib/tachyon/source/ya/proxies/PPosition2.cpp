////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PPosition2.hpp>
#include <yq/tachyon/commands/spatial/MoveBy2.hpp>
#include <yq/tachyon/commands/spatial/MoveByX.hpp>
#include <yq/tachyon/commands/spatial/MoveByY.hpp>
#include <yq/tachyon/commands/spatial/SetPosition2.hpp>
#include <yq/tachyon/commands/spatial/SetPositionX.hpp>
#include <yq/tachyon/commands/spatial/SetPositionY.hpp>

namespace yq::tachyon {
    PPosition²::PPosition²(const IPosition²& i) : m_position(i.position())
    {
        if(i.position(DISABLED))
            m_flags |= F::Disabled;
        if(i.position(SETTABLE))
            m_flags |= F::Settable;
        if(i.position(MOVEABLE))
            m_flags |= F::Moveable;
    }

    bool        PPosition²::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition²::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition²::position(moveable_k) const 
    {
        return m_flags(F::Moveable);
    }
        
    void        PPosition²::position(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition²(id(), v));
        }
    }

    void        PPosition²::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣ(id(), x));
        }
    }
    
    void        PPosition²::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸ(id(), y));
        }
    }

    void        PPosition²::position(move_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            mail(new MoveBy²(id(), Δ));
        }
    }

    void        PPosition²::position(move_k, x_k, double Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByˣ(id(), Δx));
        }
    }

    void        PPosition²::position(move_k, y_k, double Δy) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByY(id(), Δy));
        }
    }
}
