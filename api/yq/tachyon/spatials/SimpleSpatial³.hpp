////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial³.hpp>
#include <yq/tachyon/interfaces/IPosition³.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class MoveBy³;
    class MoveByˣ;
    class MoveByʸ;
    class MoveByᶻ;
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

    class SimpleSpatial³ : public Spatial³, private IPosition³ {
        YQ_TACHYON_DECLARE(SimpleSpatial³, Spatial³);
    public:
    
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


        static void init_info();
        
        void on_move³(const MoveBy³&);
        void on_moveˣ(const MoveByˣ&);
        void on_moveʸ(const MoveByʸ&);
        void on_moveᶻ(const MoveByᶻ&);
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

    protected:
        
        void        snap(Spatial³Snap&) const;

    private:
        Vector3D        m_position        = ZERO;
        Quaternion3D    m_orientation     = IDENTITY;
        Vector3D        m_scale           = ONE;
    };
}
