////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition2D.hpp"
#include <yq/tachyon/command/position/AddPosition2DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition2DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYDCommand.hpp>

namespace yq::tachyon {
    PPosition²D::PPosition²D(const IPosition²D& i) : m_position(i.position())
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

    bool        PPosition²D::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }

    bool        PPosition²D::position(settable_k) const 
    {
        return m_flags(F::Settable);
    }
    
    bool        PPosition²D::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition²D::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition²D::position(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition²DCommand({.target=object()}, v));
        }
    }

    void        PPosition²D::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣDCommand({.target=object()}, x));
        }
    }
    
    void        PPosition²D::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸDCommand({.target=object()}, y));
        }
    }

    void        PPosition²D::position(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition²DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition²D::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition²D::position(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸDCommand({.target=object()}, Δy));
        }
    }

    void        PPosition²D::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition²D::position(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition²DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition²D::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition²D::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸDCommand({.target=object()}, Δy));
        }
    }
}
