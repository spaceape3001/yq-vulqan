////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/aspect/AOrientation3.hpp>
#include <yq/tachyon/command/orientation/PitchByCommand.hpp>
#include <yq/tachyon/command/orientation/RollByCommand.hpp>
#include <yq/tachyon/command/orientation/RotateBy3Command.hpp>
#include <yq/tachyon/command/orientation/SetHeadingCommand.hpp>
#include <yq/tachyon/command/orientation/SetOrientation3Command.hpp>
#include <yq/tachyon/command/orientation/SetPitchCommand.hpp>
#include <yq/tachyon/command/orientation/SetRollCommand.hpp>
#include <yq/tachyon/command/orientation/YawByCommand.hpp>
#include <yq/tachyon/event/spatial/Orientation3Event.hpp>
#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Vector3.hxx>
#include <yq/vector/Quaternion3.hxx>

namespace yq::tachyon {
    AOrientation³::AOrientation³(const Quaternion3D& ori)
    {
        if(!is_nan(ori))
            m_orientation   = ori;
    }

    AOrientation³::AOrientation³(const Param& p) : AOrientation³(p.orientation)
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
        if(is_nan(q))
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
        orientation(SET, m_orientation * Q);
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
        orientation(ROTATE, Quaternion3D(CCW, Z, r));
    }

    // --- COMMANDS

    void AOrientation³::on_pitch_by(const PitchByCommand&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, PITCH, cmd.θ());
    }
    
    void AOrientation³::on_roll_by(const RollByCommand&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, ROLL, cmd.θ());
    }
    
    void AOrientation³::on_rotate_by(const RotateBy³Command&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, cmd.δ());
    }
    
    void AOrientation³::on_set_heading(const SetHeadingCommand&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, HEADING, cmd.θ());
    }
    
    void AOrientation³::on_set_orientation³(const SetOrientation³Command&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, cmd.orientation());
    }
    
    void AOrientation³::on_set_pitch(const SetPitchCommand&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, PITCH, cmd.θ());
    }
    
    void AOrientation³::on_set_roll(const SetRollCommand&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, ROLL, cmd.θ());
    }
    
    void AOrientation³::on_yaw_by(const YawByCommand&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, YAW, cmd.θ());
    }

}
