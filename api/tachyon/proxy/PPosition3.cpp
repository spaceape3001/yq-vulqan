////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/PPosition3.hpp>
#include <tachyon/command/position/AddPosition3Command.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/AddPositionYCommand.hpp>
#include <tachyon/command/position/AddPositionZCommand.hpp>
#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/command/position/MultiplyPosition3Command.hpp>
#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <tachyon/command/position/MultiplyPositionZCommand.hpp>
#include <tachyon/command/position/SetPosition3Command.hpp>
#include <tachyon/command/position/SetPositionXCommand.hpp>
#include <tachyon/command/position/SetPositionYCommand.hpp>
#include <tachyon/command/position/SetPositionZCommand.hpp>

namespace yq::tachyon {
    PPosition³::PPosition³(const IPosition³& i) : m_position(i.position())
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

    PPosition³::~PPosition³()
    {
    }

    bool        PPosition³::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition³::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition³::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition³::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition³::position(set_k, const Vector3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition³Command({.target=object()}, v));
        }
    }

    void        PPosition³::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣCommand({.target=object()}, x));
        }
    }
    
    void        PPosition³::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸCommand({.target=object()}, y));
        }
    }
    
    void        PPosition³::position(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻCommand({.target=object()}, z));
        }
    }

    void        PPosition³::position(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition³Command({.target=object()}, Δ));
        }
    }

    void        PPosition³::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣCommand({.target=object()}, Δx));
        }
    }

    void        PPosition³::position(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸCommand({.target=object()}, Δy));
        }
    }

    void        PPosition³::position(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻCommand({.target=object()}, Δz));
        }
    }

    void        PPosition³::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³::position(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition³Command({.target=object()}, Δ));
        }
    }

    void        PPosition³::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣCommand({.target=object()}, Δx));
        }
    }

    void        PPosition³::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸCommand({.target=object()}, Δy));
        }
    }

    void        PPosition³::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻCommand({.target=object()}, Δz));
        }
    }
}
