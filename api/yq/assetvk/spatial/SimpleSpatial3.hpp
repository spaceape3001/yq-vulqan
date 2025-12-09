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
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class PitchByCommand;
    class RollByCommand;
    class RotateBy³Command;
    class SetHeadingCommand;
    class SetOrientation³Command;
    class SetPitchCommand;
    class SetRollCommand;
    class YawByCommand;
    
    class MoveBy³Command;
    class MoveByˣCommand;
    class MoveByʸCommand;
    class MoveByᶻCommand;

    /*! \brief Simple 3D Spatial
    
        This is a simple 3D spatial that has a position, scale, & orientation.
        
        \note The resulting coordinate system is north-east-down!
    */
    class SimpleSpatial³ : public Spatial³, public APosition³, public AScale³, public AOrientation³ {
        YQ_TACHYON_DECLARE(SimpleSpatial³, Spatial³);
    public:
    
        /*
            NOTE:  Scale doesn't really belong in spatials... will move it (belongs in rendereds, for sure)
        */
    
        struct Param : public Spatial³::Param {
            Param(){}
        };
    
        SimpleSpatial³(const Vector3D& pos = NAN, const Quaternion3D& ori = NAN, const Vector3D& scale = NAN, const Param& p=Param());
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

        static void init_meta();
        
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
