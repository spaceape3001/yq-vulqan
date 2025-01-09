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
#include <ya/commands/spatial/MoveBy3.hpp>
#include <ya/commands/spatial/MoveByX.hpp>
#include <ya/commands/spatial/MoveByY.hpp>
#include <ya/commands/spatial/MoveByZ.hpp>
#include <ya/commands/spatial/MultiplyScale.hpp>
#include <ya/commands/spatial/MultiplyScale3.hpp>
#include <ya/commands/spatial/MultiplyScaleX.hpp>
#include <ya/commands/spatial/MultiplyScaleY.hpp>
#include <ya/commands/spatial/MultiplyScaleZ.hpp>
#include <ya/commands/spatial/PitchBy.hpp>
#include <ya/commands/spatial/RollBy.hpp>
#include <ya/commands/spatial/RotateBy3.hpp>
#include <ya/commands/spatial/SetOrientation3.hpp>
#include <ya/commands/spatial/SetPosition3.hpp>
#include <ya/commands/spatial/SetPositionX.hpp>
#include <ya/commands/spatial/SetPositionY.hpp>
#include <ya/commands/spatial/SetPositionZ.hpp>
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
        orientation(ROTATE, δQ);
    }
    
    void    SimpleSpatial³::rotate_by(const unit::Radian3D& Δang )
    {
        orientation(ROTATE, Δang);
    }
    
    void    SimpleSpatial³::inflate_by(const Vector3D& δZ)
    {
        scale(MULTIPLY, δZ);
    }

    void SimpleSpatial³::on_add_scale³(const AddScale³&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void SimpleSpatial³::on_add_scaleˣ(const AddScaleˣ&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void SimpleSpatial³::on_add_scaleʸ(const AddScaleʸ&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(ADD, Y, cmd.Δy());
    }
    
    void SimpleSpatial³::on_add_scaleᶻ(const AddScaleᶻ&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(ADD, Z, cmd.Δz());
    }

    void SimpleSpatial³::on_move³(const MoveBy³&cmd)
    {
        if(cmd.target() != id())
            return;
        position(MOVE, cmd.Δ());
    }
    
    void SimpleSpatial³::on_moveˣ(const MoveByˣ&cmd)
    {
        if(cmd.target() != id())
            return;
        position(MOVE, X, cmd.Δx());
    }
    
    void SimpleSpatial³::on_moveʸ(const MoveByʸ&cmd)
    {
        if(cmd.target() != id())
            return;
            
        position(MOVE, Y, cmd.Δy());
    }
    
    void SimpleSpatial³::on_moveᶻ(const MoveByᶻ&cmd)
    {
        if(cmd.target() != id())
            return;
        position(MOVE, Z, cmd.Δz());
    }

    void SimpleSpatial³::on_multiply_scale(const MultiplyScale&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void SimpleSpatial³::on_multiply_scale³(const MultiplyScale³&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void SimpleSpatial³::on_multiply_scaleˣ(const MultiplyScaleˣ&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
    
    void SimpleSpatial³::on_multiply_scaleʸ(const MultiplyScaleʸ&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(MULTIPLY, Y, cmd.δy());
    }
    
    void SimpleSpatial³::on_multiply_scaleᶻ(const MultiplyScaleᶻ&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(MULTIPLY, Z, cmd.δz());
    }

    void SimpleSpatial³::on_pitch_by(const PitchBy& cmd)
    {
        if(cmd.target() != id())
            return;
        orientation(ROTATE, PITCH, cmd.θ());
   }
    
    void SimpleSpatial³::on_roll_by(const RollBy& cmd)
    {
        if(cmd.target() != id())
            return;
        orientation(ROTATE, ROLL, cmd.θ());
    }

    void SimpleSpatial³::on_rotate_by(const RotateBy³&cmd)
    {
        if(cmd.target() != id())
            return;
        orientation(ROTATE, cmd.δ());
    }

    void SimpleSpatial³::on_set_orientation³(const SetOrientation³&cmd)
    {
        if(cmd.target() != id())
            return;
        orientation(SET, cmd.orientation());
    }

    void SimpleSpatial³::on_set_position³(const SetPosition³&cmd)
    {
        if(cmd.target() != id())
            return;
        position(SET, cmd.position());
    }
    
    void SimpleSpatial³::on_set_positionˣ(const SetPositionˣ&cmd)
    {
        if(cmd.target() != id())
            return;
        position(SET, X, cmd.x());
    }
    
    void SimpleSpatial³::on_set_positionʸ(const SetPositionʸ&cmd)
    {
        if(cmd.target() != id())
            return;
        position(SET, Y, cmd.y());
    }
    
    void SimpleSpatial³::on_set_positionᶻ(const SetPositionᶻ&cmd)
    {
        if(cmd.target() != id())
            return;
        position(SET, Z, cmd.z());
    }

    void SimpleSpatial³::on_set_scale³(const SetScale³&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(SET, cmd.scale());
    }
    
    void SimpleSpatial³::on_set_scaleˣ(const SetScaleˣ&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(SET, X, cmd.x());
    }
    
    void SimpleSpatial³::on_set_scaleʸ(const SetScaleʸ&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(SET, Y, cmd.y());
    }
    
    void SimpleSpatial³::on_set_scaleᶻ(const SetScaleᶻ&cmd)
    {
        if(cmd.target() != id())
            return;
        scale(SET, Z, cmd.z());
    }

    void SimpleSpatial³::on_yaw_by(const YawBy& cmd)
    {
        if(cmd.target() != id())
            return;
        orientation(ROTATE, YAW, cmd.θ());
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
    
    void            SimpleSpatial³::orientation(rotate_k, const Quaternion3D& Q)
    {
        m_orientation   = Q * m_orientation;
        mark();
        send(new Orientation³Event({.source=this}, m_orientation));
    }
    
    void            SimpleSpatial³::orientation(rotate_k, const unit::Radian3D& Q) 
    {
        orientation(ROTATE, Quaternion3D(CCW, Q));
    }
    
    void            SimpleSpatial³::orientation(rotate_k, pitch_k, Radian r) 
    {
        orientation(ROTATE, Quaternion3D(CCW, Y, r));
    }
    
    void            SimpleSpatial³::orientation(rotate_k, roll_k, Radian r)
    {
        orientation(ROTATE, Quaternion3D(CCW, X, r));
    }
    
    void            SimpleSpatial³::orientation(rotate_k, yaw_k, Radian r)
    {
        orientation(ROTATE, Quaternion3D(CCW, Z, r));
    }


    Vector3D    SimpleSpatial³::position() const 
    {   
        return m_position;
    }

    void        SimpleSpatial³::position(set_k, const Vector3D&v) 
    {
        m_position      = v;
        mark();
        send(new Position³Event({.source=this}, m_position));
    }
    
    void        SimpleSpatial³::position(set_k, x_k, double x) 
    {
        m_position.x    = x;
        mark();
        send(new Position³Event({.source=this}, m_position));
    }
    
    void        SimpleSpatial³::position(set_k, y_k, double y) 
    {
        m_position.y    = y;
        mark();
        send(new Position³Event({.source=this}, m_position));
    }
    
    void        SimpleSpatial³::position(set_k, z_k, double z) 
    {
        m_position.z        = z;
        mark();
        send(new Position³Event({.source=this}, m_position));
    }
    
    
    void        SimpleSpatial³::position(move_k, const Vector3D&Δ) 
    {
        m_position += Δ;
        mark();
        send(new Position³Event({.source=this}, m_position));
    }

    void        SimpleSpatial³::position(move_k, x_k, double Δx) 
    {
        m_position.x += Δx;
        mark();
        send(new Position³Event({.source=this}, m_position));
    }
    
    void    SimpleSpatial³::position(move_k, y_k, double Δy) 
    {
        m_position.y += Δy;
        mark();
        send(new Position³Event({.source=this}, m_position));
    }
    
    void    SimpleSpatial³::position(move_k, z_k, double Δz) 
    {
        m_position.z += Δz;
        mark();
        send(new Position³Event({.source=this}, m_position));
    }

    Vector3D    SimpleSpatial³::scale() const
    {
        return m_scale;
    }
    
    void        SimpleSpatial³::scale(set_k, const Vector3D&v)
    {
        m_position = v;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(set_k, x_k, double v)
    {
        m_scale.x = v;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(set_k, y_k, double v)
    {
        m_scale.y = v;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(set_k, z_k, double v)
    {
        m_scale.z = v;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(add_k, const Vector3D&Δ)
    {
        m_scale += Δ;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(add_k, x_k, double Δx)
    {
        m_scale.x += Δx;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(add_k, y_k, double Δy)
    {
        m_scale.y += Δy;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(add_k, z_k, double Δz)
    {
        m_scale.z += Δz;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(multiply_k, double Δ) 
    {
        m_scale *= Δ;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }

    void        SimpleSpatial³::scale(multiply_k, const Vector3D&Δ)
    {
        m_scale = m_scale.emul(Δ);
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(multiply_k, x_k, double Δx)
    {
        m_scale.x *= Δx;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(multiply_k, y_k, double Δy)
    {
        m_scale.y *= Δy;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
    }
    
    void        SimpleSpatial³::scale(multiply_k, z_k, double Δz)
    {
        m_scale.z *= Δz;
        mark();
        send(new Scale³Event({.source=this}, m_scale));
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
        Tensor33D   T1   = T * diagonal(m_scale);
        Tensor33D   T2   = diagonal(1./m_scale.x, 1./m_scale.y, 1./m_scale.z) * T;
        Vector3D    pos2 = T2 * m_position;
        
        sn.local2domain = Tensor44D(
            T1.xx, T1.xy, T1.xz, m_position.x,
            T1.yx, T1.yy, T1.yz, m_position.y,
            T1.zx, T1.zy, T1.zz, m_position.z,
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
        w.slot(&SimpleSpatial³::on_add_scale³);
        w.slot(&SimpleSpatial³::on_add_scaleˣ);
        w.slot(&SimpleSpatial³::on_add_scaleʸ);
        w.slot(&SimpleSpatial³::on_add_scaleᶻ);
        w.slot(&SimpleSpatial³::on_move³);
        w.slot(&SimpleSpatial³::on_moveˣ);
        w.slot(&SimpleSpatial³::on_moveʸ);
        w.slot(&SimpleSpatial³::on_moveᶻ);
        w.slot(&SimpleSpatial³::on_multiply_scale);
        w.slot(&SimpleSpatial³::on_multiply_scale³);
        w.slot(&SimpleSpatial³::on_multiply_scaleˣ);
        w.slot(&SimpleSpatial³::on_multiply_scaleʸ);
        w.slot(&SimpleSpatial³::on_multiply_scaleᶻ);
        w.slot(&SimpleSpatial³::on_pitch_by);
        w.slot(&SimpleSpatial³::on_roll_by);
        w.slot(&SimpleSpatial³::on_rotate_by);
        w.slot(&SimpleSpatial³::on_set_orientation³);
        w.slot(&SimpleSpatial³::on_set_position³);
        w.slot(&SimpleSpatial³::on_set_positionˣ);
        w.slot(&SimpleSpatial³::on_set_positionʸ);
        w.slot(&SimpleSpatial³::on_set_positionᶻ);
        w.slot(&SimpleSpatial³::on_set_scale³);
        w.slot(&SimpleSpatial³::on_set_scaleˣ);
        w.slot(&SimpleSpatial³::on_set_scaleʸ);
        w.slot(&SimpleSpatial³::on_set_scaleᶻ);
        w.slot(&SimpleSpatial³::on_yaw_by);
    }
}
