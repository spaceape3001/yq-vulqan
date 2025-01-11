////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PPosition2.hpp>
#include <ya/commands/spatial/AddPosition2.hpp>
#include <ya/commands/spatial/AddPositionX.hpp>
#include <ya/commands/spatial/AddPositionY.hpp>
#include <ya/commands/spatial/MultiplyPosition.hpp>
#include <ya/commands/spatial/MultiplyPosition2.hpp>
#include <ya/commands/spatial/MultiplyPositionX.hpp>
#include <ya/commands/spatial/MultiplyPositionY.hpp>
#include <ya/commands/spatial/SetPosition2.hpp>
#include <ya/commands/spatial/SetPositionX.hpp>
#include <ya/commands/spatial/SetPositionY.hpp>

namespace yq::tachyon {
    PPosition²::PPosition²(const IPosition²& i) : m_position(i.position())
    {
        if(i.position(DISABLED))
            m_flags |= F::Disabled;
        if(i.position(SETTABLE))
            m_flags |= F::Settable;
        if(i.position(ADDABLE))
            m_flags |= F::Addable;
        if(i.position(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    bool        PPosition²::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }

    bool        PPosition²::position(settable_k) const 
    {
        return m_flags(F::Settable);
    }
    
    bool        PPosition²::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition²::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition²::position(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition²({.target=object()}, v));
        }
    }

    void        PPosition²::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣ({.target=object()}, x));
        }
    }
    
    void        PPosition²::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸ({.target=object()}, y));
        }
    }

    void        PPosition²::position(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition²({.target=object()}, Δ));
        }
    }

    void        PPosition²::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣ({.target=object()}, Δx));
        }
    }

    void        PPosition²::position(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸ({.target=object()}, Δy));
        }
    }

    void        PPosition²::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition({.target=object()}, Δ));
        }
    }

    void        PPosition²::position(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition²({.target=object()}, Δ));
        }
    }

    void        PPosition²::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣ({.target=object()}, Δx));
        }
    }

    void        PPosition²::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸ({.target=object()}, Δy));
        }
    }
}
