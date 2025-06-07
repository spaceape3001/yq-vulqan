////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Spatial2.hpp>
#include <tachyon/aspect/AOrientation2.hpp>
#include <tachyon/aspect/APosition2.hpp>
#include <tachyon/aspect/AScale2.hpp>
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
    
    class MoveBy²Command;
    class MoveByˣCommand;
    class MoveByʸCommand;

    class SimpleSpatial² : public Spatial², public APosition², public AScale², public AOrientation² {
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
        
        using APosition²::position;
        using AScale²::scale;
        using AOrientation²::orientation;

        static void init_info();
        
    protected:
        void        snap(Spatial²Snap&) const;
        
        void    on_move²(const MoveBy²Command&);
        void    on_moveˣ(const MoveByˣCommand&);
        void    on_moveʸ(const MoveByʸCommand&);

    private:
        
        using Tachyon::mark;
        using Tachyon::send;
    };
}
