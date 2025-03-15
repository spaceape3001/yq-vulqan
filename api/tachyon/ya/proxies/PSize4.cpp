////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PSize4.hpp>
#include <ya/commands/size/AddSize4.hpp>
#include <ya/commands/size/AddSizeW.hpp>
#include <ya/commands/size/AddSizeX.hpp>
#include <ya/commands/size/AddSizeY.hpp>
#include <ya/commands/size/AddSizeZ.hpp>
#include <ya/commands/size/MultiplySize.hpp>
#include <ya/commands/size/MultiplySize4.hpp>
#include <ya/commands/size/MultiplySizeW.hpp>
#include <ya/commands/size/MultiplySizeX.hpp>
#include <ya/commands/size/MultiplySizeY.hpp>
#include <ya/commands/size/MultiplySizeZ.hpp>
#include <ya/commands/size/SetSize4.hpp>
#include <ya/commands/size/SetSizeW.hpp>
#include <ya/commands/size/SetSizeX.hpp>
#include <ya/commands/size/SetSizeY.hpp>
#include <ya/commands/size/SetSizeZ.hpp>

namespace yq::tachyon {
    PSize⁴::PSize⁴(const ISize⁴& i) : m_size(i.size())
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

    PSize⁴::~PSize⁴()
    {
    }

    bool        PSize⁴::size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize⁴::size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize⁴::size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PSize⁴::size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PSize⁴::size(set_k, const Size4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSize⁴({.target=object()}, v));
        }
    }

    void        PSize⁴::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣ({.target=object()}, x));
        }
    }
    
    void        PSize⁴::size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʸ({.target=object()}, y));
        }
    }
    
    void        PSize⁴::size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeᶻ({.target=object()}, z));
        }
    }

    void        PSize⁴::size(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʷ({.target=object()}, w));
        }
    }

    void        PSize⁴::size(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize⁴({.target=object()}, Δ));
        }
    }

    void        PSize⁴::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣ({.target=object()}, Δx));
        }
    }

    void        PSize⁴::size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʸ({.target=object()}, Δy));
        }
    }

    void        PSize⁴::size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeᶻ({.target=object()}, Δz));
        }
    }

    void        PSize⁴::size(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʷ({.target=object()}, Δw));
        }
    }

    void        PSize⁴::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize({.target=object()}, Δ));
        }
    }

    void        PSize⁴::size(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize⁴({.target=object()}, Δ));
        }
    }

    void        PSize⁴::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣ({.target=object()}, Δx));
        }
    }

    void        PSize⁴::size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʸ({.target=object()}, Δy));
        }
    }

    void        PSize⁴::size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeᶻ({.target=object()}, Δz));
        }
    }

    void        PSize⁴::size(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʷ({.target=object()}, Δw));
        }
    }
}
