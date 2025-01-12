////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/IOrientation3.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    class PitchBy;
    class RollBy;
    class RotateBy³;
    class SetHeading;
    class SetOrientation³;
    class SetPitch;
    class SetRoll;
    class YawBy;

    class AOrientation³ : public IOrientation³, private Tachyon::Helper {
    public:
    
        //!  Basic orientation in the 3D space
        Quaternion3D    orientation() const override { return m_orientation; }

        double          orientation(w_k) const { return m_orientation.x; }
        double          orientation(x_k) const { return m_orientation.x; }
        double          orientation(y_k) const { return m_orientation.y; }
        double          orientation(z_k) const { return m_orientation.z; }
        
        //!  Set orientation the orientation (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    orientation(set_k, const Quaternion3D&) override;

        void            orientation(set_k, hpr_k, Radian, Radian, Radian) override;
        void            orientation(set_k, heading_k, Radian) override;
        void            orientation(set_k, pitch_k, Radian) override;
        void            orientation(set_k, roll_k, Radian) override;
        
        void            orientation(rotate_k, const Quaternion3D&) override;
        void            orientation(rotate_k, const unit::Radian3D&) override;
        
        void            orientation(rotate_k, pitch_k, Radian) override;
        void            orientation(rotate_k, roll_k, Radian) override;
        void            orientation(rotate_k, yaw_k, Radian) override;
        
        virtual bool    orientation(disabled_k) const override { return false; }
        virtual bool    orientation(settable_k) const override { return true; }
        virtual bool    orientation(rotatable_k) const override { return true; }

        const Quaternion3D& orientation(ref_k) const { return m_orientation; }

    protected:
        
        Quaternion3D    m_orientation = IDENTITY;

        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AOrientation³();
        virtual ~AOrientation³();
        
        void        orientation(emit_k);

    private:
        void on_pitch_by(const PitchBy&);
        void on_roll_by(const RollBy&);
        void on_rotate_by(const RotateBy³&);
        void on_set_heading(const SetHeading&);
        void on_set_orientation³(const SetOrientation³&);
        void on_set_pitch(const SetPitch&);
        void on_set_roll(const SetRoll&);
        void on_yaw_by(const YawBy&);
    };
}
