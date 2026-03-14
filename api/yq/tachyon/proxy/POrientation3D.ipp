////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "POrientation3D.hpp"

#include <yq/tachyon/command/orientation/RollByCommand.hpp>
#include <yq/tachyon/command/orientation/PitchByCommand.hpp>
#include <yq/tachyon/command/orientation/RotateBy3Command.hpp>
#include <yq/tachyon/command/orientation/SetHeadingCommand.hpp>
#include <yq/tachyon/command/orientation/SetOrientation3Command.hpp>
#include <yq/tachyon/command/orientation/SetPitchCommand.hpp>
#include <yq/tachyon/command/orientation/SetRollCommand.hpp>
#include <yq/tachyon/command/orientation/YawByCommand.hpp>
#include <yq/vector/Quaternion3.hxx>

namespace yq::tachyon {
    POrientation³D::POrientation³D(const IOrientation³D& i) : m_orientation(i.orientation())
    {
        if(i.orientation(DISABLED))
            m_flags |= F::Disabled;
        if(i.orientation(SETTABLE))
            m_flags |= F::Settable;
        if(i.orientation(ROTATABLE))
            m_flags |= F::Rotatable;
    }
    
    POrientation³D::~POrientation³D()
    {
    }

    Quaternion3D    POrientation³D::orientation() const
    {
        return m_orientation;
    }
    
    bool            POrientation³D::orientation(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool            POrientation³D::orientation(settable_k) const
    {
        return m_flags(F::Settable);
    }
    
    bool            POrientation³D::orientation(rotatable_k) const
    {
        return m_flags(F::Rotatable);
    }
    
    void            POrientation³D::orientation(set_k, const Quaternion3D& Q)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetOrientation³Command({.target=object()}, Q));
        }
    }
    
    void            POrientation³D::orientation(set_k, hpr_k, Radian h, Radian p, Radian r)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetOrientation³Command({.target=object()}, HPR, h, p, r));
        }
    }
    
    void            POrientation³D::orientation(set_k, heading_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetHeadingCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation³D::orientation(set_k, pitch_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPitchCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation³D::orientation(set_k, roll_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRollCommand({.target=object()}, θ));
        }
    }

    void            POrientation³D::orientation(rotate_k, const Quaternion3D& Q)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy³Command({.target=object()}, Q));
        }
    }
    
    void            POrientation³D::orientation(rotate_k, const unit::Radian3D& R)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy³Command({.target=object()}, R));
        }
    }
    
    void            POrientation³D::orientation(rotate_k, pitch_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new PitchByCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation³D::orientation(rotate_k, roll_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RollByCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation³D::orientation(rotate_k, yaw_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new YawByCommand({.target=object()}, θ));
        }
    }
    
    Radian          POrientation³D::heading() const
    {
        return m_orientation.angle(ZYX, Z);
    }
    
    Radian          POrientation³D::pitch() const
    {
        return m_orientation.angle(ZYX, Y);
    }
    
    Radian          POrientation³D::roll() const
    {
        return m_orientation.angle(ZYX, X);
    }
}
