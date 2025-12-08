////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/aspect/AOrientation3.hpp>
#include <yq/tachyon/aspect/APosition3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    //struct OrbitSpatial³Data;
    struct OrbitSpatial³Snap;
    
    class OrbitSpatial³ : public Spatial³, public APosition³  {
        YQ_TACHYON_SNAP(OrbitSpatial³Snap)
        YQ_TACHYON_DECLARE(OrbitSpatial³, Spatial³)
    public:
        OrbitSpatial³(const Param& p=Param());
        ~OrbitSpatial³();
        
        static void init_meta();
    
    private:
        Vector3D    m_origin    = ZERO;
        double      m_strength  = 10.;
        double      m_semiMajor = 10.;
        Radian      m_inclination;
        Radian      m_a
        Radian      m_angle     = 0.;
        Vector3D    m_position;
    };
}
