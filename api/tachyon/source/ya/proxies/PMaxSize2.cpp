////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PMaxSize2.hpp>
#include <ya/commands/spatial/AddMaxSize2.hpp>
#include <ya/commands/spatial/AddMaxSizeX.hpp>
#include <ya/commands/spatial/AddMaxSizeY.hpp>
#include <ya/commands/spatial/MultiplyMaxSize.hpp>
#include <ya/commands/spatial/MultiplyMaxSize2.hpp>
#include <ya/commands/spatial/MultiplyMaxSizeX.hpp>
#include <ya/commands/spatial/MultiplyMaxSizeY.hpp>
#include <ya/commands/spatial/SetMaxSize2.hpp>
#include <ya/commands/spatial/SetMaxSizeX.hpp>
#include <ya/commands/spatial/SetMaxSizeY.hpp>

namespace yq::tachyon {
    PMaxSize²::PMaxSize²(const IMaxSize²& i) : m_max_size(i.max_size())
    {
        if(i.max_size(DISABLED))
            m_flags |= F::Disabled;
        if(i.max_size(SETTABLE))
            m_flags |= F::Settable;
        if(i.max_size(ADDABLE))
            m_flags |= F::Addable;
        if(i.max_size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PMaxSize²::~PMaxSize²()
    {
    }

    bool        PMaxSize²::max_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMaxSize²::max_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMaxSize²::max_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMaxSize²::max_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMaxSize²::max_size(set_k, const Size2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSize²({.target=object()}, v));
        }
    }

    void        PMaxSize²::max_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeˣ({.target=object()}, x));
        }
    }
    
    void        PMaxSize²::max_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʸ({.target=object()}, y));
        }
    }
    
    void        PMaxSize²::max_size(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSize²({.target=object()}, Δ));
        }
    }

    void        PMaxSize²::max_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMaxSize²::max_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʸ({.target=object()}, Δy));
        }
    }

    void        PMaxSize²::max_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize({.target=object()}, Δ));
        }
    }

    void        PMaxSize²::max_size(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize²({.target=object()}, Δ));
        }
    }

    void        PMaxSize²::max_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMaxSize²::max_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʸ({.target=object()}, Δy));
        }
    }
}
