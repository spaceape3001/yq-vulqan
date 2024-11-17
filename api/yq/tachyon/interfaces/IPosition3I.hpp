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
    class PPosition3I;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition3I {
    public:
        YQ_INTERFACE_DECLARE(IPosition3I, PPosition3I)
        
        //!  Basic position in the 3I space
        virtual Vector3I        position3i() const = 0;
        
        //!  Set position the position
        virtual void            position3i(set_t, const Vector3I&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position3i(move_t, const Vector3I&){}

        static void init_info();
    };
}
