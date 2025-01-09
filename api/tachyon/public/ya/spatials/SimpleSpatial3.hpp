////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Spatial3.hpp>
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
    class SetOrientation³;
    class SetPosition³;
    class SetPositionˣ;
    class SetPositionʸ;
    class SetPositionᶻ;
    class SetScale³;
    class SetScaleˣ;
    class SetScaleʸ;
    class SetScaleᶻ;
    class YawBy;

    class SimpleSpatial³ : public Spatial³, private IPosition³, private IScale³ {
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


        //!  Basic position in the 3D space
        virtual Vector3D    position() const override;
        
        //!  Set position the position
        virtual void        position(set_k, const Vector3D&) override;
        
        virtual void        position(set_k, x_k, double) override;
        virtual void        position(set_k, y_k, double) override;
        virtual void        position(set_k, z_k, double) override;
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(move_k, const Vector3D&Δ) override;

        virtual void        position(move_k, x_k, double Δx) override;
        virtual void        position(move_k, y_k, double Δy) override;
        virtual void        position(move_k, z_k, double Δz) override;

        virtual bool        position(disabled_k) const override { return false; }
        virtual bool        position(settable_k) const override { return true; }
        virtual bool        position(moveable_k) const override { return true; }

        virtual Vector3D    scale() const override;
        
        virtual void        scale(set_k, const Vector3D&) override;
        
        virtual void        scale(set_k, x_k, double) override;
        virtual void        scale(set_k, y_k, double) override;
        virtual void        scale(set_k, z_k, double) override;
        
        virtual void        scale(add_k, const Vector3D&Δ) override;
        virtual void        scale(add_k, x_k, double Δx) override;
        virtual void        scale(add_k, y_k, double Δy) override;
        virtual void        scale(add_k, z_k, double Δz) override;

        virtual void        scale(multiply_k, const Vector3D&Δ) override;
        virtual void        scale(multiply_k, x_k, double Δx) override;
        virtual void        scale(multiply_k, y_k, double Δy) override;
        virtual void        scale(multiply_k, z_k, double Δz) override;

        virtual bool        scale(disabled_k) const { return false; }
        virtual bool        scale(settable_k) const { return true; }
        virtual bool        scale(addable_k) const { return true; }
        virtual bool        scale(multipliable_k) const { return true; }

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
        void on_set_orientation³(const SetOrientation³&);
        void on_set_position³(const SetPosition³&);
        void on_set_positionˣ(const SetPositionˣ&);
        void on_set_positionʸ(const SetPositionʸ&);
        void on_set_positionᶻ(const SetPositionᶻ&);
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
