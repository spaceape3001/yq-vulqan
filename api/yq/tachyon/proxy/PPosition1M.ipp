////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition1M.hpp"
#include <yq/tachyon/command/position/AddPosition1MCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition1MCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXMCommand.hpp>

namespace yq::tachyon {
    PPosition¹M::PPosition¹M(const IPosition¹M& i) : m_position(i.position())
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

    bool        PPosition¹M::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition¹M::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition¹M::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition¹M::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    void        PPosition¹M::position(set_k, const Meter1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition¹MCommand({.target=object()}, v));
        }
    }

    void        PPosition¹M::position(set_k, x_k, Meter x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣMCommand({.target=object()}, x));
        }
    }
    
    void        PPosition¹M::position(add_k, const Meter1D& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddPosition¹MCommand({.target=object()}, Δ));
        }
    }

    void        PPosition¹M::position(add_k, x_k, Meter Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣMCommand({.target=object()}, Δx));
        }
    }

    void        PPosition¹M::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition¹M::position(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition¹DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition¹M::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }
}
