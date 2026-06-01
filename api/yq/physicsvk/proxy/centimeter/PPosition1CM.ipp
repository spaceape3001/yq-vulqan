////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition1CM.hpp"
#include <yq/physicsvk/command/position/centimeter/AddPosition1CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPosition1CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>

namespace yq::tachyon {
    PPosition¹CM::PPosition¹CM(const IPosition¹CM& i) : m_position(i.position())
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

    bool        PPosition¹CM::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition¹CM::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition¹CM::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition¹CM::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    void        PPosition¹CM::position(set_k, const Centimeter1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition¹CMCommand({.target=object()}, v));
        }
    }

    void        PPosition¹CM::position(set_k, x_k, Centimeter x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣCMCommand({.target=object()}, x));
        }
    }
    
    void        PPosition¹CM::position(add_k, const Centimeter1D& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddPosition¹CMCommand({.target=object()}, Δ));
        }
    }

    void        PPosition¹CM::position(add_k, x_k, Centimeter Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣCMCommand({.target=object()}, Δx));
        }
    }

    void        PPosition¹CM::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition¹CM::position(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition¹DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition¹CM::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }
}
