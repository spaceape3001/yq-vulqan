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
    class PPosition2M;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition2M {
    public:
        YQ_INTERFACE_DECLARE(IPosition2M, PPosition2M)
        
        //!  Basic position in the 2M space
        virtual Vector2M        position2m() const = 0;
        
        //!  Set position the position
        virtual void            position2m(set_t, const Vector2M&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position2m(move_t, const Vector2M&){}

        static void init_info();
    };
}
