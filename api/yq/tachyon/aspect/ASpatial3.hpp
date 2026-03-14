////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/APosition3D.hpp>
#include <yq/tachyon/aspect/AOrientation3D.hpp>
#include <yq/tachyon/aspect/AScale3D.hpp>

namespace yq::tachyon {

    class MoveBy³DCommand;
    class MoveByˣDCommand;
    class MoveByʸDCommand;
    class MoveByᶻDCommand;

    /*! Moving *most* of simple spatial into here, for those objects that need a simple position/orientation.
    
        Thus, a Rendered³ could use this for relative to a 0,0,0 that a real spatial makes use of.  (Think like parts 
        to a car or something.)
    */
    class ASpatial³ : public virtual Tachyon::Helper, public APosition³D, public AOrientation³D, public AScale³D {
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
        
        using APosition³D::position;
        using AScale³D::scale;
        using AOrientation³D::orientation;

    protected:
        ASpatial³();
        ASpatial³(const Param&);
        ASpatial³(const Vector3D& pos, const Quaternion3D& ori = IDENTITY, const Vector3D& scale = ONE);
        ~ASpatial³();

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);

    private:
        void    on_move³(const MoveBy³DCommand&);
        void    on_moveˣ(const MoveByˣDCommand&);
        void    on_moveʸ(const MoveByʸDCommand&);
        void    on_moveᶻ(const MoveByᶻDCommand&);
    };
}
