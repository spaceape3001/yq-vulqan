////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector2.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition2D;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition2D {
    public:
        YQ_INTERFACE_DECLARE(IPosition2D, PPosition2D)
        
        //!  Basic position in the 2D space
        virtual Vector2D        position2d() const = 0;
        
        //!  Set position the position
        virtual void            position2d(set_t, const Vector2D&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position2d(move_t, const Vector2D&){}

        static void init_info();
    };
}
