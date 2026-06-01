////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition3CM.hpp"
#include <yq/physicsvk/command/position/centimeter/AddPosition3CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionYCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionZCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPosition3CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionYCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionZCMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>

namespace yq::tachyon {
    PPosition³CM::PPosition³CM(const IPosition³CM& i) : m_position(i.position())
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

    PPosition³CM::~PPosition³CM()
    {
    }

    bool        PPosition³CM::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition³CM::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition³CM::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition³CM::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition³CM::position(set_k, const Centimeter3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition³CMCommand({.target=object()}, v));
        }
    }

    void        PPosition³CM::position(set_k, x_k, Centimeter x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣCMCommand({.target=object()}, x));
        }
    }
    
    void        PPosition³CM::position(set_k, y_k, Centimeter y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸCMCommand({.target=object()}, y));
        }
    }
    
    void        PPosition³CM::position(set_k, z_k, Centimeter z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻCMCommand({.target=object()}, z));
        }
    }

    void        PPosition³CM::position(add_k, const Centimeter3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition³CMCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³CM::position(add_k, x_k, Centimeter Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣCMCommand({.target=object()}, Δx));
        }
    }

    void        PPosition³CM::position(add_k, y_k, Centimeter Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸCMCommand({.target=object()}, Δy));
        }
    }

    void        PPosition³CM::position(add_k, z_k, Centimeter Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻCMCommand({.target=object()}, Δz));
        }
    }

    void        PPosition³CM::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³CM::position(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition³DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³CM::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition³CM::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸDCommand({.target=object()}, Δy));
        }
    }

    void        PPosition³CM::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻDCommand({.target=object()}, Δz));
        }
    }
}
