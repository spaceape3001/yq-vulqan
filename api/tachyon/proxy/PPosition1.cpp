////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/PPosition1.hpp>
#include <tachyon/command/position/AddPosition1Command.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/command/position/MultiplyPosition1Command.hpp>
#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/command/position/SetPosition1Command.hpp>
#include <tachyon/command/position/SetPositionXCommand.hpp>

namespace yq::tachyon {
    PPosition¹::PPosition¹(const IPosition¹& i)
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

    bool        PPosition¹::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition¹::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition¹::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition¹::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    void        PPosition¹::position(set_k, const Vector1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition¹Command({.target=object()}, v));
        }
    }

    void        PPosition¹::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣCommand({.target=object()}, x));
        }
    }
    
    void        PPosition¹::position(add_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddPosition¹Command({.target=object()}, Δ));
        }
    }

    void        PPosition¹::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣCommand({.target=object()}, Δx));
        }
    }

    void        PPosition¹::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition({.target=object()}, Δ));
        }
    }

    void        PPosition¹::position(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition¹Command({.target=object()}, Δ));
        }
    }

    void        PPosition¹::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣCommand({.target=object()}, Δx));
        }
    }
}
