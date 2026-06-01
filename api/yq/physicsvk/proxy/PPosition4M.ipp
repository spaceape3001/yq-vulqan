////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition4M.hpp"
#include <yq/physicsvk/command/position/AddPosition4MCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionWMCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionXMCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionYMCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionZMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/physicsvk/command/position/SetPosition4MCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionWMCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionXMCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionYMCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionZMCommand.hpp>

namespace yq::tachyon {
    PPosition⁴M::PPosition⁴M(const IPosition⁴M& i) : m_position(i.position())
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

    PPosition⁴M::~PPosition⁴M()
    {
    }

    bool        PPosition⁴M::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition⁴M::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition⁴M::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition⁴M::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition⁴M::position(set_k, const Meter4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition⁴MCommand({.target=object()}, v));
        }
    }

    void        PPosition⁴M::position(set_k, w_k, Meter w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʷMCommand({.target=object()}, w));
        }
    }
    
    void        PPosition⁴M::position(set_k, x_k, Meter x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣMCommand({.target=object()}, x));
        }
    }
    
    void        PPosition⁴M::position(set_k, y_k, Meter y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸMCommand({.target=object()}, y));
        }
    }
    
    void        PPosition⁴M::position(set_k, z_k, Meter z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻMCommand({.target=object()}, z));
        }
    }

    void        PPosition⁴M::position(add_k, const Meter4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition⁴MCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴M::position(add_k, w_k, Meter Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʷMCommand({.target=object()}, Δw));
        }
    }

    void        PPosition⁴M::position(add_k, x_k, Meter Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣMCommand({.target=object()}, Δx));
        }
    }

    void        PPosition⁴M::position(add_k, y_k, Meter Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸMCommand({.target=object()}, Δy));
        }
    }

    void        PPosition⁴M::position(add_k, z_k, Meter Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻMCommand({.target=object()}, Δz));
        }
    }

    void        PPosition⁴M::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴M::position(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴M::position(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʷDCommand({.target=object()}, Δw));
        }
    }

    void        PPosition⁴M::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition⁴M::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸDCommand({.target=object()}, Δy));
        }
    }

    void        PPosition⁴M::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻDCommand({.target=object()}, Δz));
        }
    }
}
