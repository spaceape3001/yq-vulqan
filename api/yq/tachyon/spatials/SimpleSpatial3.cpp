////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleSpatial3.hpp"
#include <yq/tachyon/commands/spatial/MoveBy3.hpp>
#include <yq/tachyon/commands/spatial/MoveByX.hpp>
#include <yq/tachyon/commands/spatial/MoveByY.hpp>
#include <yq/tachyon/commands/spatial/MoveByZ.hpp>
#include <yq/tachyon/commands/spatial/PitchBy.hpp>
#include <yq/tachyon/commands/spatial/RollBy.hpp>
#include <yq/tachyon/commands/spatial/SetOrientation3.hpp>
#include <yq/tachyon/commands/spatial/SetPosition3.hpp>
#include <yq/tachyon/commands/spatial/SetPositionX.hpp>
#include <yq/tachyon/commands/spatial/SetPositionY.hpp>
#include <yq/tachyon/commands/spatial/SetPositionZ.hpp>
#include <yq/tachyon/commands/spatial/SetScale3.hpp>
#include <yq/tachyon/commands/spatial/SetScaleX.hpp>
#include <yq/tachyon/commands/spatial/SetScaleY.hpp>
#include <yq/tachyon/commands/spatial/SetScaleZ.hpp>
#include <yq/tachyon/commands/spatial/YawBy.hpp>
#include <yq/tachyon/scene/Spatial³InfoWriter.hpp>
#include <yq/tensor/Tensor44.hxx>
#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector3.hxx>

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
        m_orientation = δQ * m_orientation;
    }
    
    void    SimpleSpatial³::rotate_by(const unit::Radian3D& Δang )
    {
        // rotate_by(rotor(Δang)); // TODO
    }
    
    void    SimpleSpatial³::inflate_by(const Vector3D& δZ)
    {
        m_scale = δZ.emul(m_scale);
    }

    void SimpleSpatial³::on_move3(const MoveBy3&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position += cmd.Δ();
        mark();
    }
    
    void SimpleSpatial³::on_moveX(const MoveByX&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.x += cmd.Δx();
        mark();
    }
    
    void SimpleSpatial³::on_moveY(const MoveByY&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.y += cmd.Δy();
        mark();
    }
    
    void SimpleSpatial³::on_moveZ(const MoveByZ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.z += cmd.Δz();
        mark();
    }

    void SimpleSpatial³::on_pitch_by(const PitchBy& cmd)
    {
        if(cmd.tachyon() != id())
            return;
         m_orientation = rotor_y(cmd.θ()) * m_orientation;
         mark();
   }
    
    void SimpleSpatial³::on_roll_by(const RollBy& cmd)
    {
        if(cmd.tachyon() != id())
            return;
         m_orientation = rotor_x(cmd.θ()) * m_orientation;
         mark();
    }

    void SimpleSpatial³::on_set_orientation3(const SetOrientation3&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_orientation   = cmd.orientation();
        mark();
    }

    void SimpleSpatial³::on_set_position3(const SetPosition3&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position = cmd.position();
        mark();
    }
    
    void SimpleSpatial³::on_set_positionX(const SetPositionX&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.x = cmd.x();
        mark();
    }
    
    void SimpleSpatial³::on_set_positionY(const SetPositionY&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.y = cmd.y();
        mark();
    }
    
    void SimpleSpatial³::on_set_positionZ(const SetPositionZ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_position.z = cmd.z();
        mark();
    }

    void SimpleSpatial³::on_set_scale3(const SetScale3&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_scale = cmd.scale();
        mark();
    }
    
    void SimpleSpatial³::on_set_scaleX(const SetScaleX&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_scale.x = cmd.x();
        mark();
    }
    
    void SimpleSpatial³::on_set_scaleY(const SetScaleY&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_scale.y = cmd.y();
        mark();
    }
    
    void SimpleSpatial³::on_set_scaleZ(const SetScaleZ&cmd)
    {
        if(cmd.tachyon() != id())
            return;
        m_scale.z = cmd.z();
        mark();
    }

    void SimpleSpatial³::on_yaw_by(const YawBy& cmd)
    {
        if(cmd.tachyon() != id())
            return;
         m_orientation = rotor_z(cmd.θ()) * m_orientation;
         mark();
    }

    Vector3D    SimpleSpatial³::position() const 
    {   
        return m_position;
    }

    void        SimpleSpatial³::position(set_k, const Vector3D&v) 
    {
        m_position      = v;
        mark();
    }
    
    void        SimpleSpatial³::position(set_k, x_k, double x) 
    {
        m_position.x    = x;
        mark();
    }
    
    void        SimpleSpatial³::position(set_k, y_k, double y) 
    {
        m_position.y    = y;
        mark();
    }
    
    void        SimpleSpatial³::position(set_k, z_k, double z) 
    {
        m_position.z        = z;
        mark();
    }
    
    
    void        SimpleSpatial³::position(move_k, const Vector3D&Δ) 
    {
        m_position += Δ;
        mark();
    }

    void        SimpleSpatial³::position(move_k, x_k, double Δx) 
    {
        m_position.x += Δx;
        mark();
    }
    
    void    SimpleSpatial³::position(move_k, y_k, double Δy) 
    {
        m_position.y += Δy;
        mark();
    }
    
    void    SimpleSpatial³::position(move_k, z_k, double Δz) 
    {
        m_position.z += Δz;
        mark();
    }

    void    SimpleSpatial³::set_orientation(const Quaternion3D& Q)
    {
        m_orientation = Q;
        mark();
    }
    
    void    SimpleSpatial³::set_scale(const Vector3D& v)
    {
        m_scale       = v;
        mark();
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
        w.interface<IPosition3>();
        w.description("Simple Spatial in 3 dimensions");
        w.slot(&SimpleSpatial³::on_move3);
        w.slot(&SimpleSpatial³::on_moveX);
        w.slot(&SimpleSpatial³::on_moveY);
        w.slot(&SimpleSpatial³::on_moveZ);
        w.slot(&SimpleSpatial³::on_set_orientation3);
        w.slot(&SimpleSpatial³::on_set_position3);
        w.slot(&SimpleSpatial³::on_set_positionX);
        w.slot(&SimpleSpatial³::on_set_positionY);
        w.slot(&SimpleSpatial³::on_set_positionZ);
        w.slot(&SimpleSpatial³::on_set_scale3);
        w.slot(&SimpleSpatial³::on_set_scaleX);
        w.slot(&SimpleSpatial³::on_set_scaleY);
        w.slot(&SimpleSpatial³::on_set_scaleZ);
    }
}
