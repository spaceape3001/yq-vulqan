////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/PPosition4.hpp>
#include <tachyon/command/position/AddPosition4.hpp>
#include <tachyon/command/position/AddPositionW.hpp>
#include <tachyon/command/position/AddPositionX.hpp>
#include <tachyon/command/position/AddPositionY.hpp>
#include <tachyon/command/position/AddPositionZ.hpp>
#include <tachyon/command/position/MultiplyPosition.hpp>
#include <tachyon/command/position/MultiplyPosition4.hpp>
#include <tachyon/command/position/MultiplyPositionW.hpp>
#include <tachyon/command/position/MultiplyPositionX.hpp>
#include <tachyon/command/position/MultiplyPositionY.hpp>
#include <tachyon/command/position/MultiplyPositionZ.hpp>
#include <tachyon/command/position/SetPosition4.hpp>
#include <tachyon/command/position/SetPositionW.hpp>
#include <tachyon/command/position/SetPositionX.hpp>
#include <tachyon/command/position/SetPositionY.hpp>
#include <tachyon/command/position/SetPositionZ.hpp>

namespace yq::tachyon {
    PPosition⁴::PPosition⁴(const IPosition⁴& i) : m_position(i.position())
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

    PPosition⁴::~PPosition⁴()
    {
    }

    bool        PPosition⁴::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition⁴::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition⁴::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition⁴::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition⁴::position(set_k, const Vector4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition⁴({.target=object()}, v));
        }
    }

    void        PPosition⁴::position(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʷ({.target=object()}, w));
        }
    }
    
    void        PPosition⁴::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣ({.target=object()}, x));
        }
    }
    
    void        PPosition⁴::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸ({.target=object()}, y));
        }
    }
    
    void        PPosition⁴::position(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻ({.target=object()}, z));
        }
    }

    void        PPosition⁴::position(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition⁴({.target=object()}, Δ));
        }
    }

    void        PPosition⁴::position(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʷ({.target=object()}, Δw));
        }
    }

    void        PPosition⁴::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣ({.target=object()}, Δx));
        }
    }

    void        PPosition⁴::position(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸ({.target=object()}, Δy));
        }
    }

    void        PPosition⁴::position(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻ({.target=object()}, Δz));
        }
    }

    void        PPosition⁴::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition({.target=object()}, Δ));
        }
    }

    void        PPosition⁴::position(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition⁴({.target=object()}, Δ));
        }
    }

    void        PPosition⁴::position(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʷ({.target=object()}, Δw));
        }
    }

    void        PPosition⁴::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣ({.target=object()}, Δx));
        }
    }

    void        PPosition⁴::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸ({.target=object()}, Δy));
        }
    }

    void        PPosition⁴::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻ({.target=object()}, Δz));
        }
    }
}
