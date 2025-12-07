////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CircularSpatial3.hpp"
#include "CircularSpatial3Data.hpp"
#include <yq/math/trigonometry.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/Spatial3MetaWriter.hpp>
#include <yq/trait/numbers.hpp>
#include <yq/vector/Quaternion3.hpp>

#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::CircularSpatial³)

namespace yq::tachyon {
    void CircularSpatial³::init_meta()
    {
        auto w = writer<CircularSpatial³>();
        w.property("origin", &CircularSpatial³::m_origin).tag(kTag_Save);
        w.property("rotor", &CircularSpatial³::m_rotor).tag(kTag_Save);
        w.property("radius", &CircularSpatial³::m_radius).tag(kTag_Save);
        w.property("period", &CircularSpatial³::m_period).tag(kTag_Save);
        w.property("angle0", &CircularSpatial³::m_angle0).tag(kTag_Save);
        w.interface<IPosition³>();
    }


    CircularSpatial³::CircularSpatial³() : CircularSpatial³(Param())
    {
    }

    CircularSpatial³::CircularSpatial³(const Param& p) : Spatial³(p), 
        m_angle0(p.angle0),
        m_locked(p.locked),
        m_origin(p.origin), 
        m_period(p.period),
        m_radius(p.radius),
        m_rotor(p.rotor)
    {
    }
    
    CircularSpatial³::~CircularSpatial³()
    {
    }
    

    Vector3D CircularSpatial³::position() const
    {
        return m_position;
    }
    
    void CircularSpatial³::snap(CircularSpatial³Snap& sn) const
    {
        Spatial³::snap(sn);
        
        sn.origin   = m_origin;
        sn.period   = m_period;
        sn.radius   = m_radius;
        sn.angle    = m_angle;
        sn.angle0   = m_angle0;
        sn.locked   = m_locked;
        sn.rotor    = m_rotor;
        
        sn.local2domain = Tensor44D(
            m_R.xx, m_R.xy, m_R.xz, m_position.x,
            m_R.yx, m_R.yy, m_R.yz, m_position.y,
            m_R.zx, m_R.zy, m_R.zz, m_position.z,
            0., 0., 0., 1.
        );
        
        Vector3D    pInv    = m_position * m_R;
        
        sn.domain2local = Tensor44D(
            m_R.xx, m_R.yx, m_R.zx, -pInv.x,
            m_R.xy, m_R.yy, m_R.zy, -pInv.y,
            m_R.xz, m_R.yz, m_R.zz, -pInv.z,
            0., 0., 0., 1.
        );
    }

    Execution CircularSpatial³::tick(const Context& u)
    {
        m_angle = m_angle0 + Radian(two_pi) * u.time / m_period;
        if(m_locked){
            Quaternion3D    Q(CLOCKWISE, Z, m_angle);
            m_R = tensor(m_rotor * Q);
        } else {
            m_R = tensor(m_rotor);
        }
        
        m_position  = m_origin + m_rotor*Vector3D(m_radius*cos(m_angle), m_radius*sin(m_angle), 0.);
        mark();
        return Spatial³::tick(u);
    }
}

