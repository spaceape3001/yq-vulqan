////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition3M.hpp"
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPosition3MCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionYMCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionZMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPosition3MCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionYMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionZMCommand.hpp>

namespace yq::tachyon {
    PPosition³M::PPosition³M(const IPosition³M& i) : m_position(i.position())
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

    PPosition³M::~PPosition³M()
    {
    }

    bool        PPosition³M::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition³M::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition³M::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition³M::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition³M::position(set_k, const Meter3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition³MCommand({.target=object()}, v));
        }
    }

    void        PPosition³M::position(set_k, x_k, Meter x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣMCommand({.target=object()}, x));
        }
    }
    
    void        PPosition³M::position(set_k, y_k, Meter y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸMCommand({.target=object()}, y));
        }
    }
    
    void        PPosition³M::position(set_k, z_k, Meter z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻMCommand({.target=object()}, z));
        }
    }

    void        PPosition³M::position(add_k, const Meter3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition³MCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³M::position(add_k, x_k, Meter Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣMCommand({.target=object()}, Δx));
        }
    }

    void        PPosition³M::position(add_k, y_k, Meter Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸMCommand({.target=object()}, Δy));
        }
    }

    void        PPosition³M::position(add_k, z_k, Meter Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻMCommand({.target=object()}, Δz));
        }
    }

    void        PPosition³M::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³M::position(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition³DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³M::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition³M::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸDCommand({.target=object()}, Δy));
        }
    }

    void        PPosition³M::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻDCommand({.target=object()}, Δz));
        }
    }
}
