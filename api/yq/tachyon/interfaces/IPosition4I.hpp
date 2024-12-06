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
        virtual Vector4I    position4i() const = 0;
        
        //!  Set position the position
        virtual void        position4i(set_t, const Vector4I&){}
        
        //virtual void        position4i(set_t, x_t, int){}
        //virtual void        position4i(set_t, y_t, int){}
        //virtual void        position4i(set_t, z_t, int){}
        //virtual void        position4i(set_t, w_t, int){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position4i(adjust_t, const Vector4I&){}

        //virtual void        position4i(adjust_t, x_t, int){}
        //virtual void        position4i(adjust_t, y_t, int){}
        //virtual void        position4i(adjust_t, z_t, int){}
        //virtual void        position4i(adjust_t, w_t, int){}

        virtual bool        position4i(disabled_t) const { return false; }
        virtual bool        position4i(settable_t) const { return false; }
        virtual bool        position4i(adjustable_t) const { return false; }

        static void init_info();
    };
}
