////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/POrientation2.hpp>
#include <tachyon/command/orientation/RotateBy2Command.hpp>
#include <tachyon/command/orientation/SetHeadingCommand.hpp>
#include <tachyon/command/orientation/SetOrientation2Command.hpp>
#include <tachyon/command/orientation/YawByCommand.hpp>
#include <yq/vector/Spinor2.hxx>

namespace yq::tachyon {
    POrientation²::POrientation²(const IOrientation²& i) : m_orientation(i.orientation())
    {
        if(i.orientation(DISABLED))
            m_flags |= F::Disabled;
        if(i.orientation(SETTABLE))
            m_flags |= F::Settable;
        if(i.orientation(ROTATABLE))
            m_flags |= F::Rotatable;
    }
    
    POrientation²::~POrientation²()
    {
    }

    Spinor2D    POrientation²::orientation() const
    {
        return m_orientation;
    }
    
    bool            POrientation²::orientation(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool            POrientation²::orientation(settable_k) const
    {
        return m_flags(F::Settable);
    }
    
    bool            POrientation²::orientation(rotatable_k) const
    {
        return m_flags(F::Rotatable);
    }
    
    void            POrientation²::orientation(set_k, const Spinor2D& Q)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetOrientation²Command({.target=object()}, Q));
        }
    }
    
    void            POrientation²::orientation(set_k, heading_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetHeadingCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation²::orientation(rotate_k, const Spinor2D& Q)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy²Command({.target=object()}, Q));
        }
    }
    
    void            POrientation²::orientation(rotate_k, Radian R)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy²Command({.target=object()}, R));
        }
    }
    
    void            POrientation²::orientation(rotate_k, yaw_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new YawByCommand({.target=object()}, θ));
        }
    }
    
    Radian          POrientation²::heading() const
    {
        return m_orientation.angle(CLOCKWISE);
    }
}
