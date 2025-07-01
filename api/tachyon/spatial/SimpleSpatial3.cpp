////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/spatial/SimpleSpatial3.hpp>
#include <tachyon/api/Spatial3MetaWriter.hpp>
#include <tachyon/aspect/AOrientation3Writer.hxx>
#include <tachyon/aspect/APosition3Writer.hxx>
#include <tachyon/aspect/AScale3Writer.hxx>
#include <tachyon/command/position/MoveBy3Command.hpp>
#include <tachyon/command/position/MoveByXCommand.hpp>
#include <tachyon/command/position/MoveByYCommand.hpp>
#include <tachyon/command/position/MoveByZCommand.hpp>
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

    void    SimpleSpatial³::on_move³(const MoveBy³Command& cmd)
    {
        if(cmd.target() != id())
            return;
            
        position(ADD, orientation(REF) * scale(REF).emul(cmd.Δ()));
    }
    
    void    SimpleSpatial³::on_moveˣ(const MoveByˣCommand& cmd)
    {
        if(cmd.target() != id())
            return;
            
        position(ADD, orientation(REF) * Vector3D(X, scale(X) * cmd.Δx()));
    }
    
    void    SimpleSpatial³::on_moveʸ(const MoveByʸCommand& cmd)
    {
        if(cmd.target() != id())
            return;

        position(ADD, orientation(REF) * Vector3D(Y, scale(Y) * cmd.Δy()));
    }
    
    void    SimpleSpatial³::on_moveᶻ(const MoveByᶻCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        
        position(ADD, orientation(REF) * Vector3D(Z, scale(Z) * cmd.Δz()));
    }

    void    SimpleSpatial³::set_orientation(const Quaternion3D& Q)
    {
        SimpleSpatial³::orientation(SET, Q);
    }
    
    void    SimpleSpatial³::set_position(const Vector3D& v)
    {
        SimpleSpatial³::position(SET, v);
    }

    void    SimpleSpatial³::set_scale(const Vector3D& v)
    {
        SimpleSpatial³::scale(SET, v);
    }

    void SimpleSpatial³::snap(Spatial³Snap& sn) const
    {
        Spatial³::snap(sn);

        Tensor33D   T    = tensor(m_orientation) * diagonal(m_scale);
        Tensor33D   T2   = inverse(T);
        Vector3D    pos2 = T2 * m_position;
        
        sn.local2domain = Tensor44D(
            T.xx, T.xy, T.xz, m_position.x,
            T.yx, T.yy, T.yz, m_position.y,
            T.zx, T.zy, T.zz, m_position.z,
            0., 0., 0., 1.
        );
        
        sn.domain2local = Tensor44D(
            T2.xx, T2.xy, T2.xz, -pos2.x,
            T2.yx, T2.yy, T2.yz, -pos2.y,
            T2.zx, T2.zy, T2.zz, -pos2.z,
            0., 0., 0., 1.
        );
    }

    void SimpleSpatial³::init_meta()
    {
        auto w = writer<SimpleSpatial³>();
        
        APosition³::init_meta(w);
        AScale³::init_meta(w);
        AOrientation³::init_meta(w);
        
        w.slot(&SimpleSpatial³::on_move³);
        w.slot(&SimpleSpatial³::on_moveˣ);
        w.slot(&SimpleSpatial³::on_moveʸ);
        w.slot(&SimpleSpatial³::on_moveᶻ);
        
        w.description("Simple Spatial in 3 dimensions");
    }
}
