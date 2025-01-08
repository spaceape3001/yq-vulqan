////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PScale3.hpp>
#include <ya/commands/spatial/AddScale3.hpp>
#include <ya/commands/spatial/AddScaleX.hpp>
#include <ya/commands/spatial/AddScaleY.hpp>
#include <ya/commands/spatial/AddScaleZ.hpp>
#include <ya/commands/spatial/MultiplyScale3.hpp>
#include <ya/commands/spatial/MultiplyScaleX.hpp>
#include <ya/commands/spatial/MultiplyScaleY.hpp>
#include <ya/commands/spatial/MultiplyScaleZ.hpp>
#include <ya/commands/spatial/SetScale3.hpp>
#include <ya/commands/spatial/SetScaleX.hpp>
#include <ya/commands/spatial/SetScaleY.hpp>
#include <ya/commands/spatial/SetScaleZ.hpp>

namespace yq::tachyon {
    PScale³::PScale³(const IScale³& i) : m_scale(i.scale())
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

    PScale³::~PScale³()
    {
    }

    bool        PScale³::scale(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PScale³::scale(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PScale³::scale(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PScale³::scale(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PScale³::scale(set_k, const Vector3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScale³({.target=object()}, v));
        }
    }

    void        PScale³::scale(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleˣ({.target=object()}, x));
        }
    }
    
    void        PScale³::scale(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleʸ({.target=object()}, y));
        }
    }
    
    void        PScale³::scale(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleᶻ({.target=object()}, z));
        }
    }

    void        PScale³::scale(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScale³({.target=object()}, Δ));
        }
    }

    void        PScale³::scale(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleˣ({.target=object()}, Δx));
        }
    }

    void        PScale³::scale(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleʸ({.target=object()}, Δy));
        }
    }

    void        PScale³::scale(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleᶻ({.target=object()}, Δz));
        }
    }

    void        PScale³::scale(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScale³({.target=object()}, Δ));
        }
    }

    void        PScale³::scale(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleˣ({.target=object()}, Δx));
        }
    }

    void        PScale³::scale(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleʸ({.target=object()}, Δy));
        }
    }

    void        PScale³::scale(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleᶻ({.target=object()}, Δz));
        }
    }
}
