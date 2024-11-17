////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector4.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition4M;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition4M {
    public:
        YQ_INTERFACE_DECLARE(IPosition4M, PPosition4M)
        
        //!  Basic position in the 4M space
        virtual Vector4M        position4m() const = 0;
        
        //!  Set position the position
        virtual void            position4m(set_t, const Vector4M&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position4m(move_t, const Vector4M&){}

        static void init_info();
    };
}
