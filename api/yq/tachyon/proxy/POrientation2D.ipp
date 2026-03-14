////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "POrientation2D.hpp"
#include <yq/tachyon/command/orientation/RotateBy2Command.hpp>
#include <yq/tachyon/command/orientation/SetHeadingCommand.hpp>
#include <yq/tachyon/command/orientation/SetOrientation2Command.hpp>
#include <yq/tachyon/command/orientation/YawByCommand.hpp>
#include <yq/vector/Spinor2.hxx>

namespace yq::tachyon {
    POrientation²D::POrientation²D(const IOrientation²D& i) : m_orientation(i.orientation())
    {
        if(i.orientation(DISABLED))
            m_flags |= F::Disabled;
        if(i.orientation(SETTABLE))
            m_flags |= F::Settable;
        if(i.orientation(ROTATABLE))
            m_flags |= F::Rotatable;
    }
    
    POrientation²D::~POrientation²D()
    {
    }

    Spinor2D    POrientation²D::orientation() const
    {
        return m_orientation;
    }
    
    bool            POrientation²D::orientation(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool            POrientation²D::orientation(settable_k) const
    {
        return m_flags(F::Settable);
    }
    
    bool            POrientation²D::orientation(rotatable_k) const
    {
        return m_flags(F::Rotatable);
    }
    
    void            POrientation²D::orientation(set_k, const Spinor2D& Q)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetOrientation²Command({.target=object()}, Q));
        }
    }
    
    void            POrientation²D::orientation(set_k, heading_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetHeadingCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation²D::orientation(rotate_k, const Spinor2D& Q)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy²Command({.target=object()}, Q));
        }
    }
    
    void            POrientation²D::orientation(rotate_k, Radian R)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy²Command({.target=object()}, R));
        }
    }
    
    void            POrientation²D::orientation(rotate_k, yaw_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new YawByCommand({.target=object()}, θ));
        }
    }
    
    Radian          POrientation²D::heading() const
    {
        return m_orientation.angle(CLOCKWISE);
    }
}
