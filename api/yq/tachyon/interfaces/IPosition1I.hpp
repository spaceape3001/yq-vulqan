////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector1.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition1I;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition1I {
    public:
        YQ_INTERFACE_DECLARE(IPosition1I, PPosition1I)
        
        //!  Basic position in the 1I space
        virtual Vector1I        position1i() const = 0;
        
        //!  Set position the position
        virtual void            position1i(set_t, const Vector1I&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position1i(move_t, const Vector1I&){}

        static void init_info();
    };
}
