////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial2.hpp>
#include <yq/tachyon/aspect/AOrientation2.hpp>
#include <yq/tachyon/aspect/APosition2D.hpp>
#include <yq/tachyon/aspect/AScale2D.hpp>
#include <yq/vector/Spinor2.hpp>
#include <yq/vector/Vector2.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class RotateBy²Command;
    class SetHeadingCommand;
    class SetOrientation²Command;
    class YawByCommand;
    
    class MoveBy²DCommand;
    class MoveByˣDCommand;
    class MoveByʸDCommand;

    class SimpleSpatial² : public Spatial², public APosition²D, public AScale²D, public AOrientation² {
        YQ_TACHYON_DECLARE(SimpleSpatial², Spatial²);
    public:
    
        /*
            NOTE:  Scale doesn't really belong in spatials... will move it (belongs in rendereds, for sure)
        */
    
        struct Param : public Spatial²::Param {
            Vector2D    position        = NAN;
            Spinor2D    orientation     = NAN;
            Vector2D    scale           = NAN;
            
            Param(){}
        };
    
        SimpleSpatial²(const Param&p = Param());
        ~SimpleSpatial²();
        
        void    move_by(const Vector2D&);
        void    rotate_by(const Spinor2D&);
        void    rotate_by(Radian);
        void    inflate_by(const Vector2D&);

        void    set_position(const Vector2D&);
        void    set_orientation(const Spinor2D&);
        void    set_scale(const Vector2D&);
        
        using APosition²D::position;
        using AScale²D::scale;
        using AOrientation²::orientation;

        static void init_meta();
        
    protected:
        void        snap(Spatial²Snap&) const;
        
        void    on_move²(const MoveBy²DCommand&);
        void    on_moveˣ(const MoveByˣDCommand&);
        void    on_moveʸ(const MoveByʸDCommand&);

    private:
        
        using Tachyon::mark;
        using Tachyon::send;
    };
}
