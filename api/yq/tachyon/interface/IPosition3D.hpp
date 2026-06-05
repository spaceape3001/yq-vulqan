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
    class PPosition³D;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition³D {
    public:
        YQ_INTERFACE_DECLARE(IPosition³D, PPosition³D)
        
        //!  Basic position in the 3D space
        virtual Vector3D    position() const = 0;

        Centimeter3D        position(centimeter_k) const;
        Foot3D              position(foot_k) const;
        Inch3D              position(inch_k) const;
        Kilometer3D         position(kilometer_k) const;
        Meter3D             position(meter_k) const;
        
        //!  Set position the position
        virtual void        position(set_k, const Vector3D&){}
        
        virtual void        position(set_k, x_k, double){}
        virtual void        position(set_k, y_k, double){}
        virtual void        position(set_k, z_k, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(add_k, const Vector3D&Δ){}
        virtual void        position(add_k, x_k, double Δx){}
        virtual void        position(add_k, y_k, double Δy){}
        virtual void        position(add_k, z_k, double Δz){}

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
