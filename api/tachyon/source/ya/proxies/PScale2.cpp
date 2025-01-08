////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PScale2.hpp>
#include <ya/commands/spatial/AddScale2.hpp>
#include <ya/commands/spatial/AddScaleX.hpp>
#include <ya/commands/spatial/AddScaleY.hpp>
#include <ya/commands/spatial/MultiplyScale2.hpp>
#include <ya/commands/spatial/MultiplyScaleX.hpp>
#include <ya/commands/spatial/MultiplyScaleY.hpp>
#include <ya/commands/spatial/SetScale2.hpp>
#include <ya/commands/spatial/SetScaleX.hpp>
#include <ya/commands/spatial/SetScaleY.hpp>

namespace yq::tachyon {
    PScale²::PScale²(const IScale²& i) : m_scale(i.scale())
    {
        if(i.scale(DISABLED))
            m_flags |= F::Disabled;
        if(i.scale(SETTABLE))
            m_flags |= F::Settable;
        if(i.scale(ADDABLE))
            m_flags |= F::Addable;
        if(i.scale(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PScale²::~PScale²()
    {
    }

    bool        PScale²::scale(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PScale²::scale(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PScale²::scale(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PScale²::scale(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PScale²::scale(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScale²({.target=object()}, v));
        }
    }

    void        PScale²::scale(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleˣ({.target=object()}, x));
        }
    }
    
    void        PScale²::scale(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleʸ({.target=object()}, y));
        }
    }

    void        PScale²::scale(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScale²({.target=object()}, Δ));
        }
    }

    void        PScale²::scale(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleˣ({.target=object()}, Δx));
        }
    }

    void        PScale²::scale(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleʸ({.target=object()}, Δy));
        }
    }

    void        PScale²::scale(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScale²({.target=object()}, Δ));
        }
    }

    void        PScale²::scale(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleˣ({.target=object()}, Δx));
        }
    }

    void        PScale²::scale(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleʸ({.target=object()}, Δy));
        }
    }
}
