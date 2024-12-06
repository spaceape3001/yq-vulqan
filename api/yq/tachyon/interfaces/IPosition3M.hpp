////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    class PPosition3M;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition3M {
    public:
        YQ_INTERFACE_DECLARE(IPosition3M, PPosition3M)
        
        //!  Basic position in the 3M space
        virtual Vector3M    position3m() const = 0;
        
        //!  Set position the position
        virtual void        position3m(set_t, const Vector3M&){}
        
        //virtual void        position3m(set_t, x_t, Meter){}
        //virtual void        position3m(set_t, y_t, Meter){}
        //virtual void        position3m(set_t, z_t, Meter){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position3m(adjust_t, const Vector3M&){}

        //virtual void        position3m(adjust_t, x_t, Meter){}
        //virtual void        position3m(adjust_t, y_t, Meter){}
        //virtual void        position3m(adjust_t, z_t, Meter){}

        virtual bool        position3m(disabled_t) const { return false; }
        virtual bool        position3m(settable_t) const { return false; }
        virtual bool        position3m(adjustable_t) const { return false; }

        static void init_info();
    };
}
