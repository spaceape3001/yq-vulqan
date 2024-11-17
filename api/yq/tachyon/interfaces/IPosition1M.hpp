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
    class PPosition1M;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition1M {
    public:
        YQ_INTERFACE_DECLARE(IPosition1M, PPosition1M)
        
        //!  Basic position in the 1M space
        virtual Vector1M        position1m() const = 0;
        
        //!  Set position the position
        virtual void            position1m(set_t, const Vector1M&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position1m(move_t, const Vector1M&){}

        static void init_info();
    };
}
