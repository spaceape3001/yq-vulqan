////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition1D.hpp"
#include <yq/tachyon/command/position/AddPosition1DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition1DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>

namespace yq::tachyon {
    PPosition¹D::PPosition¹D(const IPosition¹D& i) : m_position(i.position())
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

    bool        PPosition¹D::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition¹D::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition¹D::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition¹D::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    void        PPosition¹D::position(set_k, const Vector1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition¹DCommand({.target=object()}, v));
        }
    }

    void        PPosition¹D::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣDCommand({.target=object()}, x));
        }
    }
    
    void        PPosition¹D::position(add_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddPosition¹DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition¹D::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition¹D::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition¹D::position(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition¹DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition¹D::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }
}
