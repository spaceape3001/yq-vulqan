////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/PPosition2.hpp>
#include <tachyon/command/position/AddPosition2Command.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/AddPositionYCommand.hpp>
#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/command/position/MultiplyPosition2Command.hpp>
#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <tachyon/command/position/SetPosition2Command.hpp>
#include <tachyon/command/position/SetPositionXCommand.hpp>
#include <tachyon/command/position/SetPositionYCommand.hpp>

namespace yq::tachyon {
    PPosition²::PPosition²(const IPosition²& i) : m_position(i.position())
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

    bool        PPosition²::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }

    bool        PPosition²::position(settable_k) const 
    {
        return m_flags(F::Settable);
    }
    
    bool        PPosition²::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition²::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition²::position(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition²Command({.target=object()}, v));
        }
    }

    void        PPosition²::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣCommand({.target=object()}, x));
        }
    }
    
    void        PPosition²::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸCommand({.target=object()}, y));
        }
    }

    void        PPosition²::position(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition²Command({.target=object()}, Δ));
        }
    }

    void        PPosition²::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣCommand({.target=object()}, Δx));
        }
    }

    void        PPosition²::position(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸCommand({.target=object()}, Δy));
        }
    }

    void        PPosition²::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition({.target=object()}, Δ));
        }
    }

    void        PPosition²::position(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition²Command({.target=object()}, Δ));
        }
    }

    void        PPosition²::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣCommand({.target=object()}, Δx));
        }
    }

    void        PPosition²::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸCommand({.target=object()}, Δy));
        }
    }
}
