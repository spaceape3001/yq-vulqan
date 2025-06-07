////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/spatial/SimpleSpatial2.hpp>
#include <tachyon/api/Spatial2InfoWriter.hpp>
#include <tachyon/aspect/AOrientation2Writer.hxx>
#include <tachyon/aspect/APosition2Writer.hxx>
#include <tachyon/aspect/AScale2Writer.hxx>
#include <tachyon/command/position/MoveBy2Command.hpp>
#include <tachyon/command/position/MoveByXCommand.hpp>
#include <tachyon/command/position/MoveByYCommand.hpp>
#include <yq/tensor/Tensor22.hxx>
#include <yq/vector/Vector2.hxx>
#include <yq/vector/Spinor2.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleSpatial²)

namespace yq::tachyon {
    SimpleSpatial²::SimpleSpatial²(const Param&p) : Spatial²(p)
    {
        if(!is_nan(p.position))
            m_position    = p.position;
        if(!is_nan(p.orientation))
            m_orientation = p.orientation;
        if(!is_nan(p.scale))
            m_scale       = p.scale;
    }
    
    SimpleSpatial²::~SimpleSpatial²()
    {
    }    

    
    void    SimpleSpatial²::rotate_by(const Spinor2D& δQ)
    {
        SimpleSpatial²::orientation(ROTATE, δQ);
    }
    
    void    SimpleSpatial²::rotate_by(Radian Δang )
    {
        SimpleSpatial²::orientation(ROTATE, Δang);
    }
    
    void    SimpleSpatial²::inflate_by(const Vector2D& δZ)
    {
        SimpleSpatial²::scale(MULTIPLY, δZ);
    }

    void    SimpleSpatial²::on_move²(const MoveBy²Command& cmd)
    {
        if(cmd.target() != id())
            return;
            
        position(ADD, orientation(REF) * scale(REF).emul(cmd.Δ()));
    }
    
    void    SimpleSpatial²::on_moveˣ(const MoveByˣCommand& cmd)
    {
        if(cmd.target() != id())
            return;
            
        position(ADD, orientation(REF) * Vector2D(X, scale(X) * cmd.Δx()));
    }
    
    void    SimpleSpatial²::on_moveʸ(const MoveByʸCommand& cmd)
    {
        if(cmd.target() != id())
            return;

        position(ADD, orientation(REF) * Vector2D(Y, scale(Y) * cmd.Δy()));
    }
    
    void    SimpleSpatial²::set_orientation(const Spinor2D& Q)
    {
        SimpleSpatial²::orientation(SET, Q);
    }
    
    void    SimpleSpatial²::set_position(const Vector2D& v)
    {
        SimpleSpatial²::position(SET, v);
    }

    void    SimpleSpatial²::set_scale(const Vector2D& v)
    {
        SimpleSpatial²::scale(SET, v);
    }

    void SimpleSpatial²::snap(Spatial²Snap& sn) const
    {
        Spatial²::snap(sn);

        Tensor22D   T    = tensor(m_orientation) * diagonal(m_scale);
        Tensor22D   T2   = inverse(T);
        Vector2D    pos2 = T2 * m_position;
        
        sn.local2domain = Tensor44D(
            T.xx, T.xy, 0., m_position.x,
            T.yx, T.yy, 0., m_position.y,
            0., 0., 1., 0.,
            0., 0., 0., 1.
        );
        
        sn.domain2local = Tensor44D(
            T2.xx, T2.xy, 0., -pos2.x,
            T2.yx, T2.yy, 0., -pos2.y,
            0., 0., 1., 0.,
            0., 0., 0., 1.
        );
    }

    void SimpleSpatial²::init_info()
    {
        auto w = writer<SimpleSpatial²>();
        
        APosition²::init_info(w);
        AScale²::init_info(w);
        AOrientation²::init_info(w);
        
        w.slot(&SimpleSpatial²::on_move²);
        w.slot(&SimpleSpatial²::on_moveˣ);
        w.slot(&SimpleSpatial²::on_moveʸ);
        
        w.description("Simple Spatial in 2 dimensions");
    }
}
