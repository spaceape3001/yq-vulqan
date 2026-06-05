////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/units.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition¹CM;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition¹CM {
    public:
        YQ_INTERFACE_DECLARE(IPosition¹CM, PPosition¹CM)
        
        //!  Basic position in the 1D space
        virtual Centimeter1D     position() const = 0;
        
        //!  Set position the position
        virtual void        position(set_k, const Centimeter1D&){}
        virtual void        position(set_k, x_k, Centimeter){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(add_k, const Centimeter1D&Δ){}
        virtual void        position(add_k, x_k, Centimeter Δx){}

        virtual void        position(multiply_k, double){}
        virtual void        position(multiply_k, const Vector1D&Δ){}
        virtual void        position(multiply_k, x_k, double Δx){}
        
        virtual bool        position(disabled_k) const { return false; }
        virtual bool        position(settable_k) const { return false; }
        virtual bool        position(addable_k) const { return false; }
        virtual bool        position(multipliable_k) const { return false; }

        static void init_meta();
    };
}
