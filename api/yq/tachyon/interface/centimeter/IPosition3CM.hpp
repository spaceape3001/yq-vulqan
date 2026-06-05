////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/units.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition³CM;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition³CM {
    public:
        YQ_INTERFACE_DECLARE(IPosition³CM, PPosition³CM)
        
        //!  Basic position in the 3D space
        virtual Centimeter3D     position() const = 0;
        
        //!  Set position the position
        virtual void        position(set_k, const Centimeter3D&){}
        
        virtual void        position(set_k, x_k, Centimeter){}
        virtual void        position(set_k, y_k, Centimeter){}
        virtual void        position(set_k, z_k, Centimeter){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(add_k, const Centimeter3D&Δ){}
        virtual void        position(add_k, x_k, Centimeter Δx){}
        virtual void        position(add_k, y_k, Centimeter Δy){}
        virtual void        position(add_k, z_k, Centimeter Δz){}

        virtual void        position(multiply_k, double){}
        virtual void        position(multiply_k, const Vector3D&Δ){}
        virtual void        position(multiply_k, x_k, double Δx){}
        virtual void        position(multiply_k, y_k, double Δy){}
        virtual void        position(multiply_k, z_k, double Δz){}

        virtual bool        position(disabled_k) const { return false; }
        virtual bool        position(settable_k) const { return false; }
        virtual bool        position(addable_k) const { return false; }
        virtual bool        position(multipliable_k) const { return false; }

        static void init_meta();
    };
}
