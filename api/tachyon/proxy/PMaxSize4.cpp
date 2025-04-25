////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/PMaxSize4.hpp>
#include <tachyon/command/size/AddMaxSize4.hpp>
#include <tachyon/command/size/AddMaxSizeW.hpp>
#include <tachyon/command/size/AddMaxSizeX.hpp>
#include <tachyon/command/size/AddMaxSizeY.hpp>
#include <tachyon/command/size/AddMaxSizeZ.hpp>
#include <tachyon/command/size/MultiplyMaxSize.hpp>
#include <tachyon/command/size/MultiplyMaxSize4.hpp>
#include <tachyon/command/size/MultiplyMaxSizeW.hpp>
#include <tachyon/command/size/MultiplyMaxSizeX.hpp>
#include <tachyon/command/size/MultiplyMaxSizeY.hpp>
#include <tachyon/command/size/MultiplyMaxSizeZ.hpp>
#include <tachyon/command/size/SetMaxSize4.hpp>
#include <tachyon/command/size/SetMaxSizeW.hpp>
#include <tachyon/command/size/SetMaxSizeX.hpp>
#include <tachyon/command/size/SetMaxSizeY.hpp>
#include <tachyon/command/size/SetMaxSizeZ.hpp>

namespace yq::tachyon {
    PMaxSize⁴::PMaxSize⁴(const IMaxSize⁴& i) : m_max_size(i.max_size())
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

    PMaxSize⁴::~PMaxSize⁴()
    {
    }

    bool        PMaxSize⁴::max_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMaxSize⁴::max_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMaxSize⁴::max_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMaxSize⁴::max_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMaxSize⁴::max_size(set_k, const Size4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSize⁴({.target=object()}, v));
        }
    }

    void        PMaxSize⁴::max_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeˣ({.target=object()}, x));
        }
    }
    
    void        PMaxSize⁴::max_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʸ({.target=object()}, y));
        }
    }
    
    void        PMaxSize⁴::max_size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeᶻ({.target=object()}, z));
        }
    }

    void        PMaxSize⁴::max_size(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʷ({.target=object()}, w));
        }
    }

    void        PMaxSize⁴::max_size(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSize⁴({.target=object()}, Δ));
        }
    }

    void        PMaxSize⁴::max_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMaxSize⁴::max_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʸ({.target=object()}, Δy));
        }
    }

    void        PMaxSize⁴::max_size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeᶻ({.target=object()}, Δz));
        }
    }

    void        PMaxSize⁴::max_size(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʷ({.target=object()}, Δw));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize({.target=object()}, Δ));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize⁴({.target=object()}, Δ));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʸ({.target=object()}, Δy));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeᶻ({.target=object()}, Δz));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʷ({.target=object()}, Δw));
        }
    }
}
