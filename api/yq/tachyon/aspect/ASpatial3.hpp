////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/APosition3.hpp>
#include <yq/tachyon/aspect/AOrientation3.hpp>
#include <yq/tachyon/aspect/AScale3.hpp>

namespace yq::tachyon {

    class MoveBy³Command;
    class MoveByˣCommand;
    class MoveByʸCommand;
    class MoveByᶻCommand;

    /*! Moving *most* of simple spatial into here, for those objects that need a simple position/orientation.
    
        Thus, a Rendered³ could use this for relative to a 0,0,0 that a real spatial makes use of.  (Think like parts 
        to a car or something.)
    */
    class ASpatial³ : public virtual Tachyon::Helper, public APosition³, public AOrientation³, public AScale³ {
    public:
    
        // if you want to do it this way...
        struct Param {
            Vector3D        position    = ZERO;
            Quaternion3D    orientation = IDENTITY;
            Vector3D        scale       = ONE;
        };
    
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

    protected:
        ASpatial³();
        ASpatial³(const Param&);
        ASpatial³(const Vector3D& pos, const Quaternion3D& ori = IDENTITY, const Vector3D& scale = ONE);
        ~ASpatial³();

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);

    private:
        void    on_move³(const MoveBy³Command&);
        void    on_moveˣ(const MoveByˣCommand&);
        void    on_moveʸ(const MoveByʸCommand&);
        void    on_moveᶻ(const MoveByᶻCommand&);
    };
}
