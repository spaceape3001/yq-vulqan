////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Spatial3.hpp>
#include <ya/interfaces/IOrientation3.hpp>
#include <ya/interfaces/IPosition3.hpp>
#include <ya/interfaces/IScale3.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class AddScale³;
    class AddScaleˣ;
    class AddScaleʸ;
    class AddScaleᶻ;
    class MoveBy³;
    class MoveByˣ;
    class MoveByʸ;
    class MoveByᶻ;
    class MultiplyScale;
    class MultiplyScale³;
    class MultiplyScaleˣ;
    class MultiplyScaleʸ;
    class MultiplyScaleᶻ;
    class PitchBy;
    class RollBy;
    class RotateBy³;
    class SetHeading;
    class SetOrientation³;
    class SetPitch;
    class SetPosition³;
    class SetPositionˣ;
    class SetPositionʸ;
    class SetPositionᶻ;
    class SetRoll;
    class SetScale³;
    class SetScaleˣ;
    class SetScaleʸ;
    class SetScaleᶻ;
    class YawBy;

    class SimpleSpatial³ : public Spatial³, private IPosition³, private IScale³, private IOrientation³ {
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

        //!  Basic position in the 3D space
        Vector3D    position() const override;
        
        //!  Set position the position
        void        position(set_k, const Vector3D&) override;
        
        void        position(set_k, x_k, double) override;
        void        position(set_k, y_k, double) override;
        void        position(set_k, z_k, double) override;
        
        //!  Move the position (ie set to position + delta)
        void        position(move_k, const Vector3D&Δ) override;

        void        position(move_k, x_k, double Δx) override;
        void        position(move_k, y_k, double Δy) override;
        void        position(move_k, z_k, double Δz) override;

        bool        position(disabled_k) const override { return false; }
        bool        position(settable_k) const override { return true; }
        bool        position(moveable_k) const override { return true; }

        Vector3D    scale() const override;
        
        void        scale(set_k, const Vector3D&) override;
        
        void        scale(set_k, x_k, double) override;
        void        scale(set_k, y_k, double) override;
        void        scale(set_k, z_k, double) override;
        
        void        scale(add_k, const Vector3D&Δ) override;
        void        scale(add_k, x_k, double Δx) override;
        void        scale(add_k, y_k, double Δy) override;
        void        scale(add_k, z_k, double Δz) override;

        void        scale(multiply_k, double) override;
        void        scale(multiply_k, const Vector3D&Δ) override;
        void        scale(multiply_k, x_k, double Δx) override;
        void        scale(multiply_k, y_k, double Δy) override;
        void        scale(multiply_k, z_k, double Δz) override;

        bool        scale(disabled_k) const override { return false; }
        bool        scale(settable_k) const override { return true; }
        bool        scale(addable_k) const override { return true; }
        bool        scale(multipliable_k) const override { return true; }

        static void init_info();
        
        
    protected:
        void on_add_scale³(const AddScale³&);
        void on_add_scaleˣ(const AddScaleˣ&);
        void on_add_scaleʸ(const AddScaleʸ&);
        void on_add_scaleᶻ(const AddScaleᶻ&);
        void on_move³(const MoveBy³&);
        void on_moveˣ(const MoveByˣ&);
        void on_moveʸ(const MoveByʸ&);
        void on_moveᶻ(const MoveByᶻ&);
        void on_multiply_scale(const MultiplyScale&);
        void on_multiply_scale³(const MultiplyScale³&);
        void on_multiply_scaleˣ(const MultiplyScaleˣ&);
        void on_multiply_scaleʸ(const MultiplyScaleʸ&);
        void on_multiply_scaleᶻ(const MultiplyScaleᶻ&);
        void on_pitch_by(const PitchBy&);
        void on_roll_by(const RollBy&);
        void on_rotate_by(const RotateBy³&);
        void on_set_heading(const SetHeading&);
        void on_set_orientation³(const SetOrientation³&);
        void on_set_pitch(const SetPitch&);
        void on_set_position³(const SetPosition³&);
        void on_set_positionˣ(const SetPositionˣ&);
        void on_set_positionʸ(const SetPositionʸ&);
        void on_set_positionᶻ(const SetPositionᶻ&);
        void on_set_roll(const SetRoll&);
        void on_set_scale³(const SetScale³&);
        void on_set_scaleˣ(const SetScaleˣ&);
        void on_set_scaleʸ(const SetScaleʸ&);
        void on_set_scaleᶻ(const SetScaleᶻ&);
        void on_yaw_by(const YawBy&);
        
        void        snap(Spatial³Snap&) const;

    private:
        Vector3D        m_position        = ZERO;
        Quaternion3D    m_orientation     = IDENTITY;
        Vector3D        m_scale           = ONE;
    };
}
