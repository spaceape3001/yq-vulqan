////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleSpatial3.hpp"
#include <yq/tachyon/api/Spatial3MetaWriter.hpp>
#include <yq/tachyon/aspect/ASpatial3Writer.hxx>
#include <yq/tachyon/command/position/MoveBy3Command.hpp>
#include <yq/tachyon/command/position/MoveByXCommand.hpp>
#include <yq/tachyon/command/position/MoveByYCommand.hpp>
#include <yq/tachyon/command/position/MoveByZCommand.hpp>
#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Vector3.hxx>
#include <yq/vector/Quaternion3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleSpatial³)

namespace yq::tachyon {
    SimpleSpatial³::SimpleSpatial³(const Vector3D& pos, const Quaternion3D& ori, const Vector3D& scale, const Param& p) :
        Spatial³(p)
    {
        if(!is_nan(pos))
            m_position    = pos;
        if(!is_nan(ori))
            m_orientation = ori;
        if(!is_nan(scale))
            m_scale       = scale;
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
        Spatial³::snap(sn, m_position, m_orientation, m_scale);
    }

    void SimpleSpatial³::init_meta()
    {
        auto w = writer<SimpleSpatial³>();
        
        ASpatial³::init_meta(w);
        
        w.slot(&SimpleSpatial³::on_move³);
        w.slot(&SimpleSpatial³::on_moveˣ);
        w.slot(&SimpleSpatial³::on_moveʸ);
        w.slot(&SimpleSpatial³::on_moveᶻ);
        
        w.description("Simple Spatial in 3 dimensions");
    }
}
