////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/PMaxSize3.hpp>
#include <tachyon/command/size/AddMaxSize3.hpp>
#include <tachyon/command/size/AddMaxSizeX.hpp>
#include <tachyon/command/size/AddMaxSizeY.hpp>
#include <tachyon/command/size/AddMaxSizeZ.hpp>
#include <tachyon/command/size/MultiplyMaxSize.hpp>
#include <tachyon/command/size/MultiplyMaxSize3.hpp>
#include <tachyon/command/size/MultiplyMaxSizeX.hpp>
#include <tachyon/command/size/MultiplyMaxSizeY.hpp>
#include <tachyon/command/size/MultiplyMaxSizeZ.hpp>
#include <tachyon/command/size/SetMaxSize3.hpp>
#include <tachyon/command/size/SetMaxSizeX.hpp>
#include <tachyon/command/size/SetMaxSizeY.hpp>
#include <tachyon/command/size/SetMaxSizeZ.hpp>

namespace yq::tachyon {
    PMaxSize³::PMaxSize³(const IMaxSize³& i) : m_max_size(i.max_size())
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

    PMaxSize³::~PMaxSize³()
    {
    }

    bool        PMaxSize³::max_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMaxSize³::max_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMaxSize³::max_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMaxSize³::max_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMaxSize³::max_size(set_k, const Size3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSize³({.target=object()}, v));
        }
    }

    void        PMaxSize³::max_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeˣ({.target=object()}, x));
        }
    }
    
    void        PMaxSize³::max_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʸ({.target=object()}, y));
        }
    }
    
    void        PMaxSize³::max_size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeᶻ({.target=object()}, z));
        }
    }

    void        PMaxSize³::max_size(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSize³({.target=object()}, Δ));
        }
    }

    void        PMaxSize³::max_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMaxSize³::max_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʸ({.target=object()}, Δy));
        }
    }

    void        PMaxSize³::max_size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeᶻ({.target=object()}, Δz));
        }
    }

    void        PMaxSize³::max_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize({.target=object()}, Δ));
        }
    }

    void        PMaxSize³::max_size(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize³({.target=object()}, Δ));
        }
    }

    void        PMaxSize³::max_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeˣ({.target=object()}, Δx));
        }
    }

    void        PMaxSize³::max_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʸ({.target=object()}, Δy));
        }
    }

    void        PMaxSize³::max_size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeᶻ({.target=object()}, Δz));
        }
    }
}
