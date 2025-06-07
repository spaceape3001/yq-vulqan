////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Spatial3.hpp>
#include <tachyon/aspect/AOrientation3.hpp>
#include <tachyon/aspect/APosition3.hpp>
#include <tachyon/aspect/AScale3.hpp>
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
    
    class MoveBy³Command;
    class MoveByˣCommand;
    class MoveByʸCommand;
    class MoveByᶻCommand;

    class SimpleSpatial³ : public Spatial³, public APosition³, public AScale³, public AOrientation³ {
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
        using AOrientation³::orientation;

        static void init_info();
        
    protected:
        void        snap(Spatial³Snap&) const;
        
        void    on_move³(const MoveBy³Command&);
        void    on_moveˣ(const MoveByˣCommand&);
        void    on_moveʸ(const MoveByʸCommand&);
        void    on_moveᶻ(const MoveByᶻCommand&);

    private:
        
        using Tachyon::mark;
        using Tachyon::send;
    };
}
