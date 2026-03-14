////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ASpatial3DWriter.hxx"

#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    ASpatial³D::ASpatial³D()
    {
    }
    
    ASpatial³D::ASpatial³D(const Param& p) :
        APosition³D(p.position), AOrientation³D(p.orientation), AScale³D(p.scale)
    {
    }

    ASpatial³D::ASpatial³D(const Vector3D& pos, const Quaternion3D& ori, const Vector3D& scale) :
        APosition³D(pos), AOrientation³D(ori), AScale³D(scale)
    {
    }
    
    ASpatial³D::~ASpatial³D()
    {
    }

    void    ASpatial³D::rotate_by(const Quaternion3D& δQ)
    {
        ASpatial³D::orientation(ROTATE, δQ);
    }
    
    void    ASpatial³D::rotate_by(const unit::Radian3D& Δang )
    {
        ASpatial³D::orientation(ROTATE, Δang);
    }
    
    void    ASpatial³D::inflate_by(const Vector3D& δZ)
    {
        ASpatial³D::scale(MULTIPLY, δZ);
    }

    void    ASpatial³D::on_move³(const MoveBy³DCommand& cmd)
    {
        if(cmd.target() != typed())
            return;
            
        position(ADD, orientation(REF) * scale(REF).emul(cmd.Δ()));
    }
    
    void    ASpatial³D::on_moveˣ(const MoveByˣDCommand& cmd)
    {
        if(cmd.target() != typed())
            return;
            
        position(ADD, orientation(REF) * Vector3D(X, scale(X) * cmd.Δx()));
    }
    
    void    ASpatial³D::on_moveʸ(const MoveByʸDCommand& cmd)
    {
        if(cmd.target() != typed())
            return;

        position(ADD, orientation(REF) * Vector3D(Y, scale(Y) * cmd.Δy()));
    }
    
    void    ASpatial³D::on_moveᶻ(const MoveByᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        
        position(ADD, orientation(REF) * Vector3D(Z, scale(Z) * cmd.Δz()));
    }

    void    ASpatial³D::set_orientation(const Quaternion3D& Q)
    {
        ASpatial³D::orientation(SET, Q);
    }
    
    void    ASpatial³D::set_position(const Vector3D& v)
    {
        ASpatial³D::position(SET, v);
    }

    void    ASpatial³D::set_scale(const Vector3D& v)
    {
        ASpatial³D::scale(SET, v);
    }
}

