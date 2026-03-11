////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition3D.hpp"
#include <yq/tachyon/command/position/AddPosition3DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionZDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition3DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionZDCommand.hpp>

namespace yq::tachyon {
    PPosition³D::PPosition³D(const IPosition³D& i) : m_position(i.position())
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

    PPosition³D::~PPosition³D()
    {
    }

    bool        PPosition³D::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition³D::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition³D::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition³D::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition³D::position(set_k, const Vector3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition³DCommand({.target=object()}, v));
        }
    }

    void        PPosition³D::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣDCommand({.target=object()}, x));
        }
    }
    
    void        PPosition³D::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸDCommand({.target=object()}, y));
        }
    }
    
    void        PPosition³D::position(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻDCommand({.target=object()}, z));
        }
    }

    void        PPosition³D::position(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition³DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³D::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition³D::position(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸDCommand({.target=object()}, Δy));
        }
    }

    void        PPosition³D::position(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PPosition³D::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³D::position(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition³DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition³D::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition³D::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸDCommand({.target=object()}, Δy));
        }
    }

    void        PPosition³D::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻDCommand({.target=object()}, Δz));
        }
    }
}
