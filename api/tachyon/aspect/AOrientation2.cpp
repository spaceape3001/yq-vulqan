////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/logging.hpp>
#include <tachyon/aspect/AOrientation2.hpp>
#include <tachyon/command/orientation/RotateBy2.hpp>
#include <tachyon/command/orientation/SetHeading.hpp>
#include <tachyon/command/orientation/SetOrientation2.hpp>
#include <tachyon/command/orientation/YawBy.hpp>
#include <tachyon/event/spatial/Orientation2Event.hpp>
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

    void AOrientation²::on_rotate_by(const RotateBy²&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, cmd.δ());
    }
    
    void AOrientation²::on_set_heading(const SetHeading&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, HEADING, cmd.θ());
    }
    
    void AOrientation²::on_set_orientation²(const SetOrientation²&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(SET, cmd.orientation());
    }
    
    void AOrientation²::on_yaw_by(const YawBy&cmd)
    {
        if(cmd.target() != typed())
            return ;
        orientation(ROTATE, YAW, cmd.θ());
    }

}
