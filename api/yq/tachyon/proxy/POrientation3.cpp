////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/POrientation3.hpp>
#include <tachyon/command/orientation/RollByCommand.hpp>
#include <tachyon/command/orientation/PitchByCommand.hpp>
#include <tachyon/command/orientation/RotateBy3Command.hpp>
#include <tachyon/command/orientation/SetHeadingCommand.hpp>
#include <tachyon/command/orientation/SetOrientation3Command.hpp>
#include <tachyon/command/orientation/SetPitchCommand.hpp>
#include <tachyon/command/orientation/SetRollCommand.hpp>
#include <tachyon/command/orientation/YawByCommand.hpp>
#include <yq/vector/Quaternion3.hxx>

namespace yq::tachyon {
    POrientation³::POrientation³(const IOrientation³& i) : m_orientation(i.orientation())
    {
        if(i.orientation(DISABLED))
            m_flags |= F::Disabled;
        if(i.orientation(SETTABLE))
            m_flags |= F::Settable;
        if(i.orientation(ROTATABLE))
            m_flags |= F::Rotatable;
    }
    
    POrientation³::~POrientation³()
    {
    }

    Quaternion3D    POrientation³::orientation() const
    {
        return m_orientation;
    }
    
    bool            POrientation³::orientation(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool            POrientation³::orientation(settable_k) const
    {
        return m_flags(F::Settable);
    }
    
    bool            POrientation³::orientation(rotatable_k) const
    {
        return m_flags(F::Rotatable);
    }
    
    void            POrientation³::orientation(set_k, const Quaternion3D& Q)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetOrientation³Command({.target=object()}, Q));
        }
    }
    
    void            POrientation³::orientation(set_k, hpr_k, Radian h, Radian p, Radian r)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetOrientation³Command({.target=object()}, HPR, h, p, r));
        }
    }
    
    void            POrientation³::orientation(set_k, heading_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetHeadingCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation³::orientation(set_k, pitch_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPitchCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation³::orientation(set_k, roll_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRollCommand({.target=object()}, θ));
        }
    }

    void            POrientation³::orientation(rotate_k, const Quaternion3D& Q)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy³Command({.target=object()}, Q));
        }
    }
    
    void            POrientation³::orientation(rotate_k, const unit::Radian3D& R)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy³Command({.target=object()}, R));
        }
    }
    
    void            POrientation³::orientation(rotate_k, pitch_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new PitchByCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation³::orientation(rotate_k, roll_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RollByCommand({.target=object()}, θ));
        }
    }
    
    void            POrientation³::orientation(rotate_k, yaw_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new YawByCommand({.target=object()}, θ));
        }
    }
    
    Radian          POrientation³::heading() const
    {
        return m_orientation.angle(ZYX, Z);
    }
    
    Radian          POrientation³::pitch() const
    {
        return m_orientation.angle(ZYX, Y);
    }
    
    Radian          POrientation³::roll() const
    {
        return m_orientation.angle(ZYX, X);
    }
}
