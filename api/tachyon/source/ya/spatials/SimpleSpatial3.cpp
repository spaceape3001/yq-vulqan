////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/spatials/SimpleSpatial3.hpp>
#include <yt/3D/Spatial3InfoWriter.hpp>
#include <ya/commands/spatial/AddScale3.hpp>
#include <ya/commands/spatial/AddScaleX.hpp>
#include <ya/commands/spatial/AddScaleY.hpp>
#include <ya/commands/spatial/AddScaleZ.hpp>
#include <ya/commands/spatial/AddPosition3.hpp>
#include <ya/commands/spatial/AddPositionX.hpp>
#include <ya/commands/spatial/AddPositionY.hpp>
#include <ya/commands/spatial/AddPositionZ.hpp>
#include <ya/commands/spatial/MultiplyScale.hpp>
#include <ya/commands/spatial/MultiplyScale3.hpp>
#include <ya/commands/spatial/MultiplyScaleX.hpp>
#include <ya/commands/spatial/MultiplyScaleY.hpp>
#include <ya/commands/spatial/MultiplyScaleZ.hpp>
#include <ya/commands/spatial/PitchBy.hpp>
#include <ya/commands/spatial/RollBy.hpp>
#include <ya/commands/spatial/RotateBy3.hpp>
#include <ya/commands/spatial/SetHeading.hpp>
#include <ya/commands/spatial/SetOrientation3.hpp>
#include <ya/commands/spatial/SetPitch.hpp>
#include <ya/commands/spatial/SetPosition3.hpp>
#include <ya/commands/spatial/SetPositionX.hpp>
#include <ya/commands/spatial/SetPositionY.hpp>
#include <ya/commands/spatial/SetPositionZ.hpp>
#include <ya/commands/spatial/SetRoll.hpp>
#include <ya/commands/spatial/SetScale3.hpp>
#include <ya/commands/spatial/SetScaleX.hpp>
#include <ya/commands/spatial/SetScaleY.hpp>
#include <ya/commands/spatial/SetScaleZ.hpp>
#include <ya/commands/spatial/YawBy.hpp>
#include <ya/events/spatial/Orientation3Event.hpp>
#include <ya/events/spatial/Position3Event.hpp>
#include <ya/events/spatial/Scale3Event.hpp>
#include <yq/tensor/Tensor44.hxx>
#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Vector3.hxx>
#include <yq/vector/Quaternion3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleSpatial³)

namespace yq::tachyon {
    SimpleSpatial³::SimpleSpatial³(const Param&p) : Spatial³(p)
    {
        if(!is_nan(p.position))
            m_position    = p.position;
        if(!is_nan(p.orientation))
            m_orientation = p.orientation;
        if(!is_nan(p.scale))
            m_scale       = p.scale;
    }
    
    SimpleSpatial³::~SimpleSpatial³()
    {
    }    

    
    void    SimpleSpatial³::rotate_by(const Quaternion3D& δQ)
    {
        SimpleSpatial³::orientation(ROTATE, δQ);
    }
    
    void    SimpleSpatial³::rotate_by(const unit::Radian3D& Δang )
    {
        SimpleSpatial³::orientation(ROTATE, Δang);
    }
    
    void    SimpleSpatial³::inflate_by(const Vector3D& δZ)
    {
        SimpleSpatial³::scale(MULTIPLY, δZ);
    }

    void SimpleSpatial³::on_pitch_by(const PitchBy& cmd)
    {
        if(cmd.target() != id())
            return;
        SimpleSpatial³::orientation(ROTATE, PITCH, cmd.θ());
   }
    
    void SimpleSpatial³::on_roll_by(const RollBy& cmd)
    {
        if(cmd.target() != id())
            return;
        SimpleSpatial³::orientation(ROTATE, ROLL, cmd.θ());
    }

    void SimpleSpatial³::on_rotate_by(const RotateBy³&cmd)
    {
        if(cmd.target() != id())
            return;
        SimpleSpatial³::orientation(ROTATE, cmd.δ());
    }

    void SimpleSpatial³::on_set_heading(const SetHeading& cmd)
    {
        if(cmd.target() != id())
            return;
        SimpleSpatial³::orientation(SET, HEADING, cmd.θ());
    }

    void SimpleSpatial³::on_set_orientation³(const SetOrientation³&cmd)
    {
        if(cmd.target() != id())
            return;
        SimpleSpatial³::orientation(SET, cmd.orientation());
    }

    void SimpleSpatial³::on_set_pitch(const SetPitch&cmd)
    {
        if(cmd.target() != id())
            return;
        SimpleSpatial³::orientation(SET, PITCH, cmd.θ());
    }

    void SimpleSpatial³::on_set_roll(const SetRoll&cmd)
    {
        if(cmd.target() != id())
            return;
        SimpleSpatial³::orientation(SET, ROLL, cmd.θ());
    }


    void SimpleSpatial³::on_yaw_by(const YawBy& cmd)
    {
        if(cmd.target() != id())
            return;
        SimpleSpatial³::orientation(ROTATE, YAW, cmd.θ());
    }

    Quaternion3D    SimpleSpatial³::orientation() const 
    {
        return m_orientation;
    }
    
    void            SimpleSpatial³::orientation(set_k, const Quaternion3D& Q) 
    {
        m_orientation = Q;
        mark();
        send(new Orientation³Event({.source=this}, m_orientation));
    }
    
    void            SimpleSpatial³::orientation(set_k, hpr_k, Radian h, Radian p, Radian r) 
    {
        orientation(SET, Quaternion3D(HPR, h, p, r));
    }
    
    void            SimpleSpatial³::orientation(set_k, heading_k, Radian r) 
    {
        unit::Radian3D  angles  = m_orientation.angle(ZYX);
        m_orientation   = Quaternion3D(HPR, r, angles.y, angles.x);
        mark();
        send(new Orientation³Event({.source=this}, m_orientation));
    }
    
    void            SimpleSpatial³::orientation(set_k, pitch_k, Radian r)
    {
        unit::Radian3D  angles  = m_orientation.angle(ZYX);
        m_orientation   = Quaternion3D(HPR, angles.x, r, angles.x);
        mark();
        send(new Orientation³Event({.source=this}, m_orientation));
    }
    
    void            SimpleSpatial³::orientation(set_k, roll_k, Radian r)
    {
        unit::Radian3D  angles  = m_orientation.angle(ZYX);
        m_orientation   = Quaternion3D(HPR, angles.z, angles.y, r);
        mark();
        send(new Orientation³Event({.source=this}, m_orientation));
    }

    void            SimpleSpatial³::orientation(rotate_k, const Quaternion3D& Q)
    {
        m_orientation   = Q * m_orientation;
        mark();
        send(new Orientation³Event({.source=this}, m_orientation));
    }
    
    void            SimpleSpatial³::orientation(rotate_k, const unit::Radian3D& Q) 
    {
        SimpleSpatial³::orientation(ROTATE, Quaternion3D(CCW, Q));
    }
    
    void            SimpleSpatial³::orientation(rotate_k, pitch_k, Radian r) 
    {
        SimpleSpatial³::orientation(ROTATE, Quaternion3D(CCW, Y, r));
    }
    
    void            SimpleSpatial³::orientation(rotate_k, roll_k, Radian r)
    {
        SimpleSpatial³::orientation(ROTATE, Quaternion3D(CCW, X, r));
    }
    
    void            SimpleSpatial³::orientation(rotate_k, yaw_k, Radian r)
    {
        SimpleSpatial³::orientation(ROTATE, Quaternion3D(CCW, Z, r));
    }


    void    SimpleSpatial³::set_orientation(const Quaternion3D& Q)
    {
        m_orientation = Q;
        mark();
        send(new Orientation³Event({.source=this}, m_orientation));
    }
    
    void    SimpleSpatial³::set_scale(const Vector3D& v)
    {
        m_scale       = v;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }

    void SimpleSpatial³::snap(Spatial³Snap& sn) const
    {
        Spatial³::snap(sn);

        Tensor33D   T       = tensor(m_orientation);
        Tensor33D   T1   = T * diagonal(scale(REF));
        Tensor33D   T2   = diagonal(1./scale(X), 1./scale(Y), 1./scale(Z)) * T;
        Vector3D    pos2 = T2 * m_position;
        
        sn.local2domain = Tensor44D(
            T1.xx, T1.xy, T1.xz, position(X),
            T1.yx, T1.yy, T1.yz, position(Y),
            T1.zx, T1.zy, T1.zz, position(Z),
            0., 0., 0., 1.
        );
        
        sn.domain2local = Tensor44D(
            T2.xx, T2.xy, T2.xz, -pos2.x,
            T2.yx, T2.yy, T2.yz, -pos2.y,
            T2.zx, T2.zy, T2.zz, -pos2.z,
            0., 0., 0., 1.
        );
    }

    void SimpleSpatial³::init_info()
    {
        auto w = writer<SimpleSpatial³>();
        w.interface<IOrientation³>();
        w.interface<IPosition³>();
        w.interface<IScale³>();
        w.description("Simple Spatial in 3 dimensions");
        w.slot(&SimpleSpatial³::on_pitch_by);
        w.slot(&SimpleSpatial³::on_roll_by);
        w.slot(&SimpleSpatial³::on_rotate_by);
        w.slot(&SimpleSpatial³::on_set_heading);
        w.slot(&SimpleSpatial³::on_set_orientation³);
        w.slot(&SimpleSpatial³::on_set_pitch);
        w.slot(&SimpleSpatial³::on_set_roll);
        w.slot(&SimpleSpatial³::on_yaw_by);
    }
}
