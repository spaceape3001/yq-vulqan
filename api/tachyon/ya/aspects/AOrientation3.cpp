////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/AOrientation3.hpp>
#include <ya/commands/spatial/PitchBy.hpp>
#include <ya/commands/spatial/RollBy.hpp>
#include <ya/commands/spatial/RotateBy3.hpp>
#include <ya/commands/spatial/SetHeading.hpp>
#include <ya/commands/spatial/SetOrientation3.hpp>
#include <ya/commands/spatial/SetPitch.hpp>
#include <ya/commands/spatial/SetRoll.hpp>
#include <ya/commands/spatial/YawBy.hpp>
#include <ya/events/spatial/Orientation3Event.hpp>
#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Vector3.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yt/logging.hpp>

namespace yq::tachyon {
    AOrientation³::AOrientation³()
    {
    }
    
    AOrientation³::~AOrientation³()
    {
    }

    void        AOrientation³::orientation(emit_k)
    {
        send(new Orientation³Event({.source=typed()}, m_orientation));
    }

    void            AOrientation³::orientation(set_k, const Quaternion3D& Q) 
    {
        double  q   = Q.length²();
        if(q < 1e-6)
            return ;
        m_orientation = Q / sqrt(q);
        mark();
        orientation(EMIT);
    }

    void    AOrientation³::orientation(set_k, hpr_k, Radian h, Radian p, Radian r) 
    {
        orientation(SET, Quaternion3D(HPR, h, p, r));
    }
    
    void    AOrientation³::orientation(set_k, heading_k, Radian r) 
    {
        unit::Radian3D  angles  = m_orientation.angle(ZYX);
        orientation(SET, HPR, r, angles.y, angles.x);
    }
    
    void    AOrientation³::orientation(set_k, pitch_k, Radian r)
    {
        unit::Radian3D  angles  = m_orientation.angle(ZYX);
        orientation(SET, HPR, angles.z, r, angles.x);
    }
    
    void    AOrientation³::orientation(set_k, roll_k, Radian r)
    {
        unit::Radian3D  angles  = m_orientation.angle(ZYX);
        orientation(SET, HPR, angles.z, angles.y, r);
    }

    void            AOrientation³::orientation(rotate_k, const Quaternion3D& Q)
    {
        orientation(SET, Q * m_orientation);
    }
    
    void            AOrientation³::orientation(rotate_k, const unit::Radian3D& Q) 
    {
        orientation(ROTATE, Quaternion3D(CCW, Q));
    }
    
    void            AOrientation³::orientation(rotate_k, pitch_k, Radian r) 
    {
        orientation(ROTATE, Quaternion3D(CCW, Y, r));
    }
    
    void            AOrientation³::orientation(rotate_k, roll_k, Radian r)
    {
        orientation(ROTATE, Quaternion3D(CCW, X, r));
    }
    
    void            AOrientation³::orientation(rotate_k, yaw_k, Radian r)
    {
        orientation(ROTATE, Quaternion3D(CCW, Z, -r));
    }

    // --- COMMANDS

    void AOrientation³::on_pitch_by(const PitchBy&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, PITCH, cmd.θ());
    }
    
    void AOrientation³::on_roll_by(const RollBy&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, ROLL, cmd.θ());
    }
    
    void AOrientation³::on_rotate_by(const RotateBy³&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, cmd.δ());
    }
    
    void AOrientation³::on_set_heading(const SetHeading&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, HEADING, cmd.θ());
    }
    
    void AOrientation³::on_set_orientation³(const SetOrientation³&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, cmd.orientation());
    }
    
    void AOrientation³::on_set_pitch(const SetPitch&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, PITCH, cmd.θ());
    }
    
    void AOrientation³::on_set_roll(const SetRoll&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, ROLL, cmd.θ());
    }
    
    void AOrientation³::on_yaw_by(const YawBy&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, YAW, cmd.θ());
    }

}
