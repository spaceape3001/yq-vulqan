////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/spatials/SimpleSpatial3.hpp>
#include <yt/3D/Spatial3InfoWriter.hpp>
#include <ya/aspects/AOrientation3Writer.hxx>
#include <ya/aspects/APosition3Writer.hxx>
#include <ya/aspects/AScale3Writer.hxx>
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


    void    SimpleSpatial³::set_orientation(const Quaternion3D& Q)
    {
        SimpleSpatial³::orientation(SET, Q);
    }
    
    void    SimpleSpatial³::set_scale(const Vector3D& v)
    {
        SimpleSpatial³::scale(SET, v);
    }

    void SimpleSpatial³::snap(Spatial³Snap& sn) const
    {
        Spatial³::snap(sn);

        Tensor33D   T       = tensor(m_orientation);
        Tensor33D   T1   = T * diagonal(m_scale);
        Tensor33D   T2   = diagonal(1./m_scale.x, 1./m_scale.y, 1./m_scale.z) * T;
        Vector3D    pos2 = T2 * m_position;
        
        sn.local2domain = Tensor44D(
            T1.xx, T1.xy, T1.xz, m_position.z,
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
        
        APosition³::init_info(w);
        AScale³::init_info(w);
        AOrientation³::init_info(w);
        w.description("Simple Spatial in 3 dimensions");
    }
}
