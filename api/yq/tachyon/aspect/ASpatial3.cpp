////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ASpatial3Writer.hxx"

#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    ASpatial³::ASpatial³()
    {
    }
    
    ASpatial³::ASpatial³(const Param& p) :
        APosition³(p.position), AOrientation³(p.orientation), AScale³(p.scale)
    {
    }

    ASpatial³::ASpatial³(const Vector3D& pos, const Quaternion3D& ori, const Vector3D& scale) :
        APosition³(pos), AOrientation³(ori), AScale³(scale)
    {
    }
    
    ASpatial³::~ASpatial³()
    {
    }

    void    ASpatial³::rotate_by(const Quaternion3D& δQ)
    {
        ASpatial³::orientation(ROTATE, δQ);
    }
    
    void    ASpatial³::rotate_by(const unit::Radian3D& Δang )
    {
        ASpatial³::orientation(ROTATE, Δang);
    }
    
    void    ASpatial³::inflate_by(const Vector3D& δZ)
    {
        ASpatial³::scale(MULTIPLY, δZ);
    }

    void    ASpatial³::on_move³(const MoveBy³Command& cmd)
    {
        if(cmd.target() != typed())
            return;
            
        position(ADD, orientation(REF) * scale(REF).emul(cmd.Δ()));
    }
    
    void    ASpatial³::on_moveˣ(const MoveByˣCommand& cmd)
    {
        if(cmd.target() != typed())
            return;
            
        position(ADD, orientation(REF) * Vector3D(X, scale(X) * cmd.Δx()));
    }
    
    void    ASpatial³::on_moveʸ(const MoveByʸCommand& cmd)
    {
        if(cmd.target() != typed())
            return;

        position(ADD, orientation(REF) * Vector3D(Y, scale(Y) * cmd.Δy()));
    }
    
    void    ASpatial³::on_moveᶻ(const MoveByᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        
        position(ADD, orientation(REF) * Vector3D(Z, scale(Z) * cmd.Δz()));
    }

    void    ASpatial³::set_orientation(const Quaternion3D& Q)
    {
        ASpatial³::orientation(SET, Q);
    }
    
    void    ASpatial³::set_position(const Vector3D& v)
    {
        ASpatial³::position(SET, v);
    }

    void    ASpatial³::set_scale(const Vector3D& v)
    {
        ASpatial³::scale(SET, v);
    }
}

