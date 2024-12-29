////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleSpatial³.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::SimpleSpatial³)

namespace yq::tachyon {
    SimpleSpatial³::SimpleSpatial³(const Param&p) 
    {
    }
    
    SimpleSpatial³::~SimpleSpatial³()
    {
    }    
    void    SimpleSpatial³::move_by(const Vector3D& Δx)
    {
        m_space.position += Δx;
    }
    
    void    SimpleSpatial³::rotate_by(const Quaternion3D& δQ)
    {
        m_space.orientation = δQ * m_space.orientation;
    }
    
    void    SimpleSpatial³::rotate_by(const unit::Radian3D& Δang )
    {
        rotate_by(rotor(Δang));
    }
    
    void    SimpleSpatial³::inflate_by(const Vector3D& δZ)
    {
        m_scale = δZ.emul(m_scale);
    }

    void    SimpleSpatial³::set_position(const Vector3D& x)
    {
        m_space.position    = x;
    }
    
    void    SimpleSpatial³::set_orientation(const Quaternion3D& Q)
    {
        m_space.orientation = Q;
    }
    
    void    SimpleSpatial³::set_scale(const Vector3D& v)
    {
        m_space.scale       = v;
    }

    Tensor44D       SimpleSpatial³::local2domain() const 
    {
        return m_space.local2parent();
    }
    
    Tensor44D       SimpleSpatial³::domain2local() const
    {
        return m_space.parent2local();
    }

    void SimpleSpatial³::init_info()
    {
        auto w = writer<SimpleSpatial³>();
        w.description("Simple Spatial in ³ dimensions");
    }
}
