////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleSpatial³.hpp"
#include <yq/tachyon/api/Spatial³InfoWriter.hpp>
#include <yq/tensor/Tensor44.hxx>
#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleSpatial³)

namespace yq::tachyon {
    SimpleSpatial³::SimpleSpatial³(const Param&p) : Spatial³(p)
    {
        m_position    = p.position;
        m_orientation = p.orientation;
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
        //   TODO (the matrices)
    }

    void SimpleSpatial³::init_info()
    {
        auto w = writer<SimpleSpatial³>();
        w.interface<IPosition³>();
        w.description("Simple Spatial in ³ dimensions");
    }
}
