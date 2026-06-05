////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition2CM.hpp"
#include <yq/tachyon/command/position/centimeter/AddPosition2CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPosition2CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>

namespace yq::tachyon {
    PPosition²CM::PPosition²CM(const IPosition²CM& i) : m_position(i.position())
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

    bool        PPosition²CM::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }

    bool        PPosition²CM::position(settable_k) const 
    {
        return m_flags(F::Settable);
    }
    
    bool        PPosition²CM::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition²CM::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition²CM::position(set_k, const Centimeter2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition²CMCommand({.target=object()}, v));
        }
    }

    void        PPosition²CM::position(set_k, x_k, Centimeter x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣCMCommand({.target=object()}, x));
        }
    }
    
    void        PPosition²CM::position(set_k, y_k, Centimeter y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸCMCommand({.target=object()}, y));
        }
    }

    void        PPosition²CM::position(add_k, const Centimeter2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition²CMCommand({.target=object()}, Δ));
        }
    }

    void        PPosition²CM::position(add_k, x_k, Centimeter Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣCMCommand({.target=object()}, Δx));
        }
    }

    void        PPosition²CM::position(add_k, y_k, Centimeter Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸCMCommand({.target=object()}, Δy));
        }
    }

    void        PPosition²CM::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition²CM::position(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition²DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition²CM::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition²CM::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸDCommand({.target=object()}, Δy));
        }
    }
}
