////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector3.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition3M;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition3M {
    public:
        YQ_INTERFACE_DECLARE(IPosition3M, PPosition3M)
        
        //!  Basic position in the 3M space
        virtual Vector3M        position3m() const = 0;
        
        //!  Set position the position
        virtual void            position3m(set_t, const Vector3M&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position3m(move_t, const Vector3M&){}

        static void init_info();
    };
}
