////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition2M.hpp"
#include <yq/physicsvk/command/position/AddPosition2MCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionXMCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionYMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/physicsvk/command/position/SetPosition2MCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionXMCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionYMCommand.hpp>

namespace yq::tachyon {
    PPosition²M::PPosition²M(const IPosition²M& i) : m_position(i.position())
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

    bool        PPosition²M::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }

    bool        PPosition²M::position(settable_k) const 
    {
        return m_flags(F::Settable);
    }
    
    bool        PPosition²M::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition²M::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition²M::position(set_k, const Meter2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition²MCommand({.target=object()}, v));
        }
    }

    void        PPosition²M::position(set_k, x_k, Meter x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣMCommand({.target=object()}, x));
        }
    }
    
    void        PPosition²M::position(set_k, y_k, Meter y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸMCommand({.target=object()}, y));
        }
    }

    void        PPosition²M::position(add_k, const Meter2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition²MCommand({.target=object()}, Δ));
        }
    }

    void        PPosition²M::position(add_k, x_k, Meter Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣMCommand({.target=object()}, Δx));
        }
    }

    void        PPosition²M::position(add_k, y_k, Meter Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸMCommand({.target=object()}, Δy));
        }
    }

    void        PPosition²M::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition²M::position(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition²DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition²M::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition²M::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸDCommand({.target=object()}, Δy));
        }
    }
}
