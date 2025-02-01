////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PSize2.hpp>
#include <ya/commands/spatial/AddSize2.hpp>
#include <ya/commands/spatial/AddSizeX.hpp>
#include <ya/commands/spatial/AddSizeY.hpp>
#include <ya/commands/spatial/MultiplySize.hpp>
#include <ya/commands/spatial/MultiplySize2.hpp>
#include <ya/commands/spatial/MultiplySizeX.hpp>
#include <ya/commands/spatial/MultiplySizeY.hpp>
#include <ya/commands/spatial/SetSize2.hpp>
#include <ya/commands/spatial/SetSizeX.hpp>
#include <ya/commands/spatial/SetSizeY.hpp>

namespace yq::tachyon {
    PSize²::PSize²(const ISize²& i) : m_size(i.size())
    {
        if(i.size(DISABLED))
            m_flags |= F::Disabled;
        if(i.size(SETTABLE))
            m_flags |= F::Settable;
        if(i.size(ADDABLE))
            m_flags |= F::Addable;
        if(i.size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PSize²::~PSize²()
    {
    }

    bool        PSize²::size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize²::size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize²::size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PSize²::size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PSize²::size(set_k, const Size2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSize²({.target=object()}, v));
        }
    }

    void        PSize²::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣ({.target=object()}, x));
        }
    }
    
    void        PSize²::size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʸ({.target=object()}, y));
        }
    }
    
    void        PSize²::size(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize²({.target=object()}, Δ));
        }
    }

    void        PSize²::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣ({.target=object()}, Δx));
        }
    }

    void        PSize²::size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʸ({.target=object()}, Δy));
        }
    }

    void        PSize²::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize({.target=object()}, Δ));
        }
    }

    void        PSize²::size(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize²({.target=object()}, Δ));
        }
    }

    void        PSize²::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣ({.target=object()}, Δx));
        }
    }

    void        PSize²::size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʸ({.target=object()}, Δy));
        }
    }
}
