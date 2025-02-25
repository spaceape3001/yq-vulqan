////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PMinSize2.hpp>
#include <ya/commands/size/AddMinSize2.hpp>
#include <ya/commands/size/AddMinSizeX.hpp>
#include <ya/commands/size/AddMinSizeY.hpp>
#include <ya/commands/size/MultiplyMinSize.hpp>
#include <ya/commands/size/MultiplyMinSize2.hpp>
#include <ya/commands/size/MultiplyMinSizeX.hpp>
#include <ya/commands/size/MultiplyMinSizeY.hpp>
#include <ya/commands/size/SetMinSize2.hpp>
#include <ya/commands/size/SetMinSizeX.hpp>
#include <ya/commands/size/SetMinSizeY.hpp>

namespace yq::tachyon {
    PMinSize²::PMinSize²(const IMinSize²& i) : m_min_size(i.min_size())
    {
        if(i.min_size(DISABLED))
            m_flags |= F::Disabled;
        if(i.min_size(SETTABLE))
            m_flags |= F::Settable;
        if(i.min_size(ADDABLE))
            m_flags |= F::Addable;
        if(i.min_size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PMinSize²::~PMinSize²()
    {
    }

    bool        PMinSize²::min_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMinSize²::min_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMinSize²::min_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMinSize²::min_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMinSize²::min_size(set_k, const Size2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSize²({.target=object()}, v));
        }
    }

    void        PMinSize²::min_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeˣ({.target=object()}, x));
        }
    }
    
    void        PMinSize²::min_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeʸ({.target=object()}, y));
        }
    }
    
    void        PMinSize²::min_size(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSize²({.target=object()}, Δ));
        }
    }

    void        PMinSize²::min_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMinSize²::min_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeʸ({.target=object()}, Δy));
        }
    }

    void        PMinSize²::min_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize({.target=object()}, Δ));
        }
    }

    void        PMinSize²::min_size(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize²({.target=object()}, Δ));
        }
    }

    void        PMinSize²::min_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMinSize²::min_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeʸ({.target=object()}, Δy));
        }
    }
}
