////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PPosition1.hpp>
#include <ya/commands/spatial/MoveBy1.hpp>
#include <ya/commands/spatial/MoveByX.hpp>
#include <ya/commands/spatial/SetPosition1.hpp>
#include <ya/commands/spatial/SetPositionX.hpp>

namespace yq::tachyon {
    PPosition¹::PPosition¹(const IPosition¹& i)
    {
        if(i.position(DISABLED))
            m_flags |= F::Disabled;
        if(i.position(SETTABLE))
            m_flags |= F::Settable;
        if(i.position(MOVEABLE))
            m_flags |= F::Moveable;
    }

    bool        PPosition¹::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition¹::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition¹::position(moveable_k) const 
    {
        return m_flags(F::Moveable);
    }
        
    void        PPosition¹::position(set_k, const Vector1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition¹({.target=object()}, v));
        }
    }

    void        PPosition¹::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣ({.target=object()}, x));
        }
    }
    
    void        PPosition¹::position(move_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveBy¹({.target=object()}, Δ));
        }
    }

    void        PPosition¹::position(move_k, x_k, double Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new MoveByˣ({.target=object()}, Δx));
        }
    }
}
