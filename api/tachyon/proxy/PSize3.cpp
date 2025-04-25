////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/PSize3.hpp>
#include <tachyon/command/size/AddSize3.hpp>
#include <tachyon/command/size/AddSizeX.hpp>
#include <tachyon/command/size/AddSizeY.hpp>
#include <tachyon/command/size/AddSizeZ.hpp>
#include <tachyon/command/size/MultiplySize.hpp>
#include <tachyon/command/size/MultiplySize3.hpp>
#include <tachyon/command/size/MultiplySizeX.hpp>
#include <tachyon/command/size/MultiplySizeY.hpp>
#include <tachyon/command/size/MultiplySizeZ.hpp>
#include <tachyon/command/size/SetSize3.hpp>
#include <tachyon/command/size/SetSizeX.hpp>
#include <tachyon/command/size/SetSizeY.hpp>
#include <tachyon/command/size/SetSizeZ.hpp>

namespace yq::tachyon {
    PSize³::PSize³(const ISize³& i) : m_size(i.size())
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

    PSize³::~PSize³()
    {
    }

    bool        PSize³::size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize³::size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize³::size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PSize³::size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PSize³::size(set_k, const Size3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSize³({.target=object()}, v));
        }
    }

    void        PSize³::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣ({.target=object()}, x));
        }
    }
    
    void        PSize³::size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʸ({.target=object()}, y));
        }
    }
    
    void        PSize³::size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeᶻ({.target=object()}, z));
        }
    }

    void        PSize³::size(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize³({.target=object()}, Δ));
        }
    }

    void        PSize³::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣ({.target=object()}, Δx));
        }
    }

    void        PSize³::size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʸ({.target=object()}, Δy));
        }
    }

    void        PSize³::size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeᶻ({.target=object()}, Δz));
        }
    }

    void        PSize³::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize({.target=object()}, Δ));
        }
    }

    void        PSize³::size(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize³({.target=object()}, Δ));
        }
    }

    void        PSize³::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣ({.target=object()}, Δx));
        }
    }

    void        PSize³::size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʸ({.target=object()}, Δy));
        }
    }

    void        PSize³::size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeᶻ({.target=object()}, Δz));
        }
    }
}
