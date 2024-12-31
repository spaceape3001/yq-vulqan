////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/scene/Spatial3.hpp>
#include <yq/tachyon/interfaces/IPosition3.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class MoveBy3;
    class MoveByX;
    class MoveByY;
    class MoveByZ;
    class PitchBy;
    class RollBy;
    class SetOrientation3;
    class SetPosition3;
    class SetPositionX;
    class SetPositionY;
    class SetPositionZ;
    class SetScale3;
    class SetScaleX;
    class SetScaleY;
    class SetScaleZ;
    class YawBy;

    class SimpleSpatial³ : public Spatial³, private IPosition3 {
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
        
        void on_move3(const MoveBy3&);
        void on_moveX(const MoveByX&);
        void on_moveY(const MoveByY&);
        void on_moveZ(const MoveByZ&);
        void on_pitch_by(const PitchBy&);
        void on_roll_by(const RollBy&);
        void on_set_orientation3(const SetOrientation3&);
        void on_set_position3(const SetPosition3&);
        void on_set_positionX(const SetPositionX&);
        void on_set_positionY(const SetPositionY&);
        void on_set_positionZ(const SetPositionZ&);
        void on_set_scale3(const SetScale3&);
        void on_set_scaleX(const SetScaleX&);
        void on_set_scaleY(const SetScaleY&);
        void on_set_scaleZ(const SetScaleZ&);
        void on_yaw_by(const YawBy&);

    protected:
        
        void        snap(Spatial³Snap&) const;

    private:
        Vector3D        m_position        = ZERO;
        Quaternion3D    m_orientation     = IDENTITY;
        Vector3D        m_scale           = ONE;
    };
}
