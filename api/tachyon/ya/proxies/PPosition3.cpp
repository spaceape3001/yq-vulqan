////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PPosition3.hpp>
#include <ya/commands/position/AddPosition3.hpp>
#include <ya/commands/position/AddPositionX.hpp>
#include <ya/commands/position/AddPositionY.hpp>
#include <ya/commands/position/AddPositionZ.hpp>
#include <ya/commands/position/MultiplyPosition.hpp>
#include <ya/commands/position/MultiplyPosition3.hpp>
#include <ya/commands/position/MultiplyPositionX.hpp>
#include <ya/commands/position/MultiplyPositionY.hpp>
#include <ya/commands/position/MultiplyPositionZ.hpp>
#include <ya/commands/position/SetPosition3.hpp>
#include <ya/commands/position/SetPositionX.hpp>
#include <ya/commands/position/SetPositionY.hpp>
#include <ya/commands/position/SetPositionZ.hpp>

namespace yq::tachyon {
    PPosition³::PPosition³(const IPosition³& i) : m_position(i.position())
    {
        if(i.position(DISABLED))
            m_flags |= F::Disabled;
        if(i.position(SETTABLE))
            m_flags |= F::Settable;
        if(i.position(ADDABLE))
            m_flags |= F::Addable;
        if(i.position(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PPosition³::~PPosition³()
    {
    }

    bool        PPosition³::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition³::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition³::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition³::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition³::position(set_k, const Vector3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition³({.target=object()}, v));
        }
    }

    void        PPosition³::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣ({.target=object()}, x));
        }
    }
    
    void        PPosition³::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸ({.target=object()}, y));
        }
    }
    
    void        PPosition³::position(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻ({.target=object()}, z));
        }
    }

    void        PPosition³::position(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition³({.target=object()}, Δ));
        }
    }

    void        PPosition³::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣ({.target=object()}, Δx));
        }
    }

    void        PPosition³::position(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸ({.target=object()}, Δy));
        }
    }

    void        PPosition³::position(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻ({.target=object()}, Δz));
        }
    }

    void        PPosition³::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition({.target=object()}, Δ));
        }
    }

    void        PPosition³::position(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition³({.target=object()}, Δ));
        }
    }

    void        PPosition³::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣ({.target=object()}, Δx));
        }
    }

    void        PPosition³::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸ({.target=object()}, Δy));
        }
    }

    void        PPosition³::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻ({.target=object()}, Δz));
        }
    }
}
