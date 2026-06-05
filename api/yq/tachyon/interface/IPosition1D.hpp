////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector1.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/unit/declare.hpp>

namespace yq::tachyon {
    class PPosition¹D;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition¹D {
    public:
        YQ_INTERFACE_DECLARE(IPosition¹D, PPosition¹D)
        
        //!  Basic position in the 1D space
        virtual Vector1D    position() const = 0;
        
        Centimeter1D        position(centimeter_k) const;
        Foot1D              position(foot_k) const;
        Inch1D              position(inch_k) const;
        Kilometer1D         position(kilometer_k) const;
        Meter1D             position(meter_k) const;
        
        //!  Set position the position
        virtual void        position(set_k, const Vector1D&){}
        virtual void        position(set_k, x_k, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(add_k, const Vector1D&Δ){}
        virtual void        position(add_k, x_k, double Δx){}

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
