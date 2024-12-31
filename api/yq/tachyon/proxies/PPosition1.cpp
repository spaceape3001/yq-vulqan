////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition1.hpp"
#include <yq/tachyon/commands/spatial/MoveBy1.hpp>
#include <yq/tachyon/commands/spatial/MoveByX.hpp>
#include <yq/tachyon/commands/spatial/SetPosition1.hpp>
#include <yq/tachyon/commands/spatial/SetPositionX.hpp>

namespace yq::tachyon {
    PPosition1::PPosition1(const IPosition1& i)
    {
        if(i.position(DISABLED))
            m_flags |= F::Disabled;
        if(i.position(SETTABLE))
            m_flags |= F::Settable;
        if(i.position(MOVEABLE))
            m_flags |= F::Moveable;
    }

    bool        PPosition1::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition1::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition1::position(moveable_k) const 
    {
        return m_flags(F::Moveable);
    }
        
    void        PPosition1::position(set_k, const Vector1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition1(id(), v));
        }
    }

    void        PPosition1::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionX(id(), x));
        }
    }
    
    void        PPosition1::position(move_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveBy1(id(), Δ));
        }
    }

    void        PPosition1::position(move_k, x_k, double Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByX(id(), Δx));
        }
    }
}
