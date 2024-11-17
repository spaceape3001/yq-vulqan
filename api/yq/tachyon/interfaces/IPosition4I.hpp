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
    class PPosition4I;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition4I {
    public:
        YQ_INTERFACE_DECLARE(IPosition4I, PPosition4I)
        
        //!  Basic position in the 4I space
        virtual Vector4I        position4i() const = 0;
        
        //!  Set position the position
        virtual void            position4i(set_t, const Vector4I&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position4i(move_t, const Vector4I&){}

        static void init_info();
    };
}
