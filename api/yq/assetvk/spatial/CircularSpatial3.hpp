////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/interface/IPosition3.hpp>
#include <yq/tensor/Tensor33.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    //struct CircularSpatial³Data;
    struct CircularSpatial³Snap;
    
    #ifdef NAN
        #undef NAN
    #endif
    
    class CircularSpatial³ : public Spatial³, public IPosition³ {
        YQ_TACHYON_SNAP(CircularSpatial³Snap)
        YQ_TACHYON_DECLARE(CircularSpatial³, Spatial³)
    public:
    
        struct Param : public Spatial³::Param {
            Radian          angle0      = 0._rad;   //!< Starting angle
            bool            locked      = false;
            Vector3D        origin      = ZERO;
            Second          period      = 10._s;
            double          radius      = 5.;
            Quaternion3D    rotor       = IDENTITY;
        };
    
        CircularSpatial³();
        CircularSpatial³(const Param& p);
        ~CircularSpatial³();
        
        static void init_meta();
        
        virtual bool position(disabled_k) const { return false; }
        virtual bool position(settable_k) const { return false; }
        virtual Vector3D position() const;

    protected:
        Execution tick(const Context&) override;
    
    private:
    
        void        snap(CircularSpatial³Snap&) const;
    
        Radian              m_angle0;
        Radian              m_angle;
        bool                m_locked;
        Vector3D            m_origin;
        Second              m_period;
        Vector3D            m_position  = NAN;
        double              m_radius;
        Quaternion3D        m_rotor     = IDENTITY;
        Tensor33D           m_R         = IDENTITY;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::CircularSpatial³)

