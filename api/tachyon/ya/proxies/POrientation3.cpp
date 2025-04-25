////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/proxies/POrientation3.hpp>
#include <tachyon/command/orientation/RollBy.hpp>
#include <tachyon/command/orientation/PitchBy.hpp>
#include <tachyon/command/orientation/RotateBy3.hpp>
#include <tachyon/command/orientation/SetHeading.hpp>
#include <tachyon/command/orientation/SetOrientation3.hpp>
#include <tachyon/command/orientation/SetPitch.hpp>
#include <tachyon/command/orientation/SetRoll.hpp>
#include <tachyon/command/orientation/YawBy.hpp>
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
            mail(new SetOrientation³({.target=object()}, Q));
        }
    }
    
    void            POrientation³::orientation(set_k, hpr_k, Radian h, Radian p, Radian r)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetOrientation³({.target=object()}, HPR, h, p, r));
        }
    }
    
    void            POrientation³::orientation(set_k, heading_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetHeading({.target=object()}, θ));
        }
    }
    
    void            POrientation³::orientation(set_k, pitch_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPitch({.target=object()}, θ));
        }
    }
    
    void            POrientation³::orientation(set_k, roll_k, Radian θ) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRoll({.target=object()}, θ));
        }
    }

    void            POrientation³::orientation(rotate_k, const Quaternion3D& Q)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy³({.target=object()}, Q));
        }
    }
    
    void            POrientation³::orientation(rotate_k, const unit::Radian3D& R)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RotateBy³({.target=object()}, R));
        }
    }
    
    void            POrientation³::orientation(rotate_k, pitch_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new PitchBy({.target=object()}, θ));
        }
    }
    
    void            POrientation³::orientation(rotate_k, roll_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new RollBy({.target=object()}, θ));
        }
    }
    
    void            POrientation³::orientation(rotate_k, yaw_k, Radian θ)
    {
        if(m_flags(F::Rotatable) && !m_flags(F::Disabled)){
            mail(new YawBy({.target=object()}, θ));
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
