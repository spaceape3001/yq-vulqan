////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/aspect/AOrientation2.hpp>
#include <yq/tachyon/command/orientation/RotateBy2Command.hpp>
#include <yq/tachyon/command/orientation/SetHeadingCommand.hpp>
#include <yq/tachyon/command/orientation/SetOrientation2Command.hpp>
#include <yq/tachyon/command/orientation/YawByCommand.hpp>
#include <yq/tachyon/event/spatial/Orientation2Event.hpp>
#include <yq/vector/Spinor2.hxx>
#include "AOrientation2Writer.hxx"

namespace yq::tachyon {
    AOrientation²::AOrientation²()
    {
    }
    
    AOrientation²::~AOrientation²()
    {
    }

    void        AOrientation²::orientation(emit_k)
    {
        send(new Orientation²Event({.source=typed()}, m_orientation));
    }

    void            AOrientation²::orientation(set_k, const Spinor2D& Q) 
    {
        double  q   = Q.length²();
        if(q < 1e-6)
            return ;
        m_orientation = Q / sqrt(q);
        mark();
        orientation(EMIT);
    }

    void    AOrientation²::orientation(set_k, heading_k, Radian r) 
    {
        orientation(SET, Spinor2D(CLOCKWISE, r));
    }
    
    void            AOrientation²::orientation(rotate_k, const Spinor2D& Q)
    {
        orientation(SET, m_orientation * Q);
    }
    
    void            AOrientation²::orientation(rotate_k, Radian Q) 
    {
        orientation(ROTATE, Spinor2D(CCW, Q));
    }
    
    void            AOrientation²::orientation(rotate_k, yaw_k, Radian r)
    {
        orientation(ROTATE, Spinor2D(CLOCKWISE, r));
    }

    // --- COMMANDS

    void AOrientation²::on_rotate_by(const RotateBy²Command&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, cmd.δ());
    }
    
    void AOrientation²::on_set_heading(const SetHeadingCommand&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, HEADING, cmd.θ());
    }
    
    void AOrientation²::on_set_orientation²(const SetOrientation²Command&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, cmd.orientation());
    }
    
    void AOrientation²::on_yaw_by(const YawByCommand&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, YAW, cmd.θ());
    }

}
