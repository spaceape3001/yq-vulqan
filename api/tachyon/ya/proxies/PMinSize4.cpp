////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PMinSize4.hpp>
#include <tachyon/command/size/AddMinSize4.hpp>
#include <tachyon/command/size/AddMinSizeW.hpp>
#include <tachyon/command/size/AddMinSizeX.hpp>
#include <tachyon/command/size/AddMinSizeY.hpp>
#include <tachyon/command/size/AddMinSizeZ.hpp>
#include <tachyon/command/size/MultiplyMinSize.hpp>
#include <tachyon/command/size/MultiplyMinSize4.hpp>
#include <tachyon/command/size/MultiplyMinSizeW.hpp>
#include <tachyon/command/size/MultiplyMinSizeX.hpp>
#include <tachyon/command/size/MultiplyMinSizeY.hpp>
#include <tachyon/command/size/MultiplyMinSizeZ.hpp>
#include <tachyon/command/size/SetMinSize4.hpp>
#include <tachyon/command/size/SetMinSizeW.hpp>
#include <tachyon/command/size/SetMinSizeX.hpp>
#include <tachyon/command/size/SetMinSizeY.hpp>
#include <tachyon/command/size/SetMinSizeZ.hpp>

namespace yq::tachyon {
    PMinSize⁴::PMinSize⁴(const IMinSize⁴& i) : m_min_size(i.min_size())
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

    PMinSize⁴::~PMinSize⁴()
    {
    }

    bool        PMinSize⁴::min_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMinSize⁴::min_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMinSize⁴::min_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMinSize⁴::min_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMinSize⁴::min_size(set_k, const Size4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSize⁴({.target=object()}, v));
        }
    }

    void        PMinSize⁴::min_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeˣ({.target=object()}, x));
        }
    }
    
    void        PMinSize⁴::min_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeʸ({.target=object()}, y));
        }
    }
    
    void        PMinSize⁴::min_size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeᶻ({.target=object()}, z));
        }
    }

    void        PMinSize⁴::min_size(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeʷ({.target=object()}, w));
        }
    }

    void        PMinSize⁴::min_size(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSize⁴({.target=object()}, Δ));
        }
    }

    void        PMinSize⁴::min_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMinSize⁴::min_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeʸ({.target=object()}, Δy));
        }
    }

    void        PMinSize⁴::min_size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeᶻ({.target=object()}, Δz));
        }
    }

    void        PMinSize⁴::min_size(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeʷ({.target=object()}, Δw));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize({.target=object()}, Δ));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize⁴({.target=object()}, Δ));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeʸ({.target=object()}, Δy));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeᶻ({.target=object()}, Δz));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeʷ({.target=object()}, Δw));
        }
    }
}
