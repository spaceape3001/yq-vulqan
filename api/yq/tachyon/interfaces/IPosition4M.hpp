////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {
    class PPosition4M;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition4M {
    public:
        YQ_INTERFACE_DECLARE(IPosition4M, PPosition4M)
        
        //!  Basic position in the 4M space
        virtual Vector4M    position4m() const = 0;
        
        //!  Set position the position
        virtual void        position4m(set_t, const Vector4M&){}
        
        //virtual void        position4m(set_t, x_t, Meter){}
        //virtual void        position4m(set_t, y_t, Meter){}
        //virtual void        position4m(set_t, z_t, Meter){}
        //virtual void        position4m(set_t, w_t, Meter){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position4m(adjust_t, const Vector4M&){}

        //virtual void        position4m(adjust_t, x_t, Meter){}
        //virtual void        position4m(adjust_t, y_t, Meter){}
        //virtual void        position4m(adjust_t, z_t, Meter){}
        //virtual void        position4m(adjust_t, w_t, Meter){}

        virtual bool        position4m(disabled_t) const { return false; }
        virtual bool        position4m(settable_t) const { return false; }
        virtual bool        position4m(adjustable_t) const { return false; }

        static void init_info();
    };
}
