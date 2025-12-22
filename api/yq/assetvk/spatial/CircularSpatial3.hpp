////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/aspect/AOrientation3.hpp>
#include <yq/tachyon/aspect/APosition3.hpp>
#include <yq/tachyon/aspect/AScale3.hpp>
#include <yq/tensor/Tensor33.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    //struct CircularSpatial³Data;
    struct CircularSpatial³Snap;
    class Circular³LockCommand;
    class Circular³PeriodCommand;
    class Circular³RadiusCommand;
    
    #ifdef NAN
        #undef NAN
    #endif
    
    class CircularSpatial³ : public Spatial³, public APosition³, public AScale³, public AOrientation³ {
        YQ_TACHYON_SNAP(CircularSpatial³Snap)
        YQ_TACHYON_DECLARE(CircularSpatial³, Spatial³)
    public:
    
        // note, revision, position is now the origin....
        // and orientation covers the rotor
    
        struct Param : public Spatial³::Param, public APosition³::Param, public AScale³::Param, public AOrientation³::Param {
            Radian          angle0      = 0._rad;   //!< Starting angle
            bool            locked      = false;
            Second          period      = 10._s;
            double          radius      = 5.;
        };
    
        CircularSpatial³();
        CircularSpatial³(const Param& p);
        ~CircularSpatial³();
        
        static void init_meta();
        
        virtual Vector3D position() const;

    protected:
        Execution tick(const Context&) override;
    
    private:
    
        using Spatial³::mark;
        using Spatial³::send;
    
        void    on_lock_command(const Circular³LockCommand&);
        void    on_period_command(const Circular³PeriodCommand&);
        void    on_radius_command(const Circular³RadiusCommand&);
    
        void        snap(CircularSpatial³Snap&) const;
    
        Radian              m_angle0;
        Radian              m_angle;
        bool                m_locked;   // TODO: replace with gimbal mode (maybe delegate time???)
        Second              m_period;
        double              m_radius;

        // computed.... 
        Vector3D            m_local     = NAN;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::CircularSpatial³)

