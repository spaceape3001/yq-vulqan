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
        virtual void        position4i(set_k, const Vector4I&){}
        
        //virtual void        position4i(set_k, x_k, int){}
        //virtual void        position4i(set_k, y_k, int){}
        //virtual void        position4i(set_k, z_k, int){}
        //virtual void        position4i(set_k, w_k, int){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position4i(adjust_k, const Vector4I&){}

        //virtual void        position4i(adjust_k, x_k, int){}
        //virtual void        position4i(adjust_k, y_k, int){}
        //virtual void        position4i(adjust_k, z_k, int){}
        //virtual void        position4i(adjust_k, w_k, int){}

        virtual bool        position4i(disabled_k) const { return false; }
        virtual bool        position4i(settable_k) const { return false; }
        virtual bool        position4i(adjustable_k) const { return false; }

        static void init_info();
    };
}
