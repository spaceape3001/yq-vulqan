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
        virtual Vector3I    position3i() const = 0;
        
        //!  Set position the position
        virtual void        position3i(set_k, const Vector3I&){}
        
        //virtual void        position3i(set_k, x_k, int){}
        //virtual void        position3i(set_k, y_k, int){}
        //virtual void        position3i(set_k, z_k, int){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position3i(adjust_k, const Vector3I&){}

        //virtual void        position3i(adjust_k, x_k, int){}
        //virtual void        position3i(adjust_k, y_k, int){}
        //virtual void        position3i(adjust_k, z_k, int){}

        virtual bool        position3i(disabled_k) const { return false; }
        virtual bool        position3i(settable_k) const { return false; }
        virtual bool        position3i(adjustable_k) const { return false; }

        static void init_info();
    };
}
