////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Spatial3.hpp>
#include <ya/aspects/APosition3.hpp>
#include <ya/aspects/AScale3.hpp>
#include <ya/interfaces/IOrientation3.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class PitchBy;
    class RollBy;
    class RotateBy³;
    class SetHeading;
    class SetOrientation³;
    class SetPitch;
    class SetRoll;
    class YawBy;

    class SimpleSpatial³ : public Spatial³, private APosition³, private AScale³, private IOrientation³ {
        YQ_TACHYON_DECLARE(SimpleSpatial³, Spatial³);
    public:
    
        /*
            NOTE:  Scale doesn't really belong in spatials... will move it (belongs in rendereds, for sure)
        */
    
        struct Param : public Spatial³::Param {
            Vector3D        position        = NAN;
            Quaternion3D    orientation     = NAN;
            Vector3D        scale           = NAN;
            
            Param(){}
        };
    
        SimpleSpatial³(const Param&p = Param());
        ~SimpleSpatial³();
        
        void    move_by(const Vector3D&);
        void    rotate_by(const Quaternion3D&);
        void    rotate_by(const unit::Radian3D&);
        void    inflate_by(const Vector3D&);

        void    set_position(const Vector3D&);
        void    set_orientation(const Quaternion3D&);
        void    set_scale(const Vector3D&);
        
        using APosition³::position;
        using AScale³::scale;

        Quaternion3D    orientation() const override;
        bool            orientation(disabled_k) const override { return false; }
        bool            orientation(settable_k) const override { return true; }
        bool            orientation(rotatable_k) const override { return true; }
        
        void            orientation(set_k, const Quaternion3D&) override;
        void            orientation(set_k, hpr_k, Radian, Radian, Radian) override;
        void            orientation(set_k, heading_k, Radian) override;
        void            orientation(set_k, pitch_k, Radian) override;
        void            orientation(set_k, roll_k, Radian) override;
        
        void            orientation(rotate_k, const Quaternion3D&) override;
        void            orientation(rotate_k, const unit::Radian3D&) override;
        
        void            orientation(rotate_k, pitch_k, Radian) override;
        void            orientation(rotate_k, roll_k, Radian) override;
        void            orientation(rotate_k, yaw_k, Radian) override;

        static void init_info();
        
        
    protected:
        void        snap(Spatial³Snap&) const;

    private:
    
        void on_pitch_by(const PitchBy&);
        void on_roll_by(const RollBy&);
        void on_rotate_by(const RotateBy³&);
        void on_set_heading(const SetHeading&);
        void on_set_orientation³(const SetOrientation³&);
        void on_set_pitch(const SetPitch&);
        void on_set_roll(const SetRoll&);
        void on_yaw_by(const YawBy&);
        
        using Tachyon::mark;
        using Tachyon::send;
        
        Quaternion3D    m_orientation     = IDENTITY;
    };
}
