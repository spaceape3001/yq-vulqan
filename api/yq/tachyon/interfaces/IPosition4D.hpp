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
    class PPosition4D;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition4D {
    public:
        YQ_INTERFACE_DECLARE(IPosition4D, PPosition4D)
        
        //!  Basic position in the 4D space
        virtual Vector4D    position4d() const = 0;
        
        //!  Set position the position
        virtual void        position4d(set_t, const Vector4D&){}
        
        //virtual void        position4d(set_t, x_t, double){}
        //virtual void        position4d(set_t, y_t, double){}
        //virtual void        position4d(set_t, z_t, double){}
        //virtual void        position4d(set_t, w_t, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position4d(adjust_t, const Vector4D&){}

        //virtual void        position4d(adjust_t, x_t, double){}
        //virtual void        position4d(adjust_t, y_t, double){}
        //virtual void        position4d(adjust_t, z_t, double){}
        //virtual void        position4d(adjust_t, w_t, double){}

        virtual bool        position4d(disabled_t) const { return false; }
        virtual bool        position4d(settable_t) const { return false; }
        virtual bool        position4d(adjustable_t) const { return false; }

        static void init_info();
    };
}