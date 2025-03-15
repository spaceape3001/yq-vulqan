////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector4.hpp>
#include <yt/keywords.hpp>
#include <yt/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition⁴;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition⁴ {
    public:
        YQ_INTERFACE_DECLARE(IPosition⁴, PPosition⁴)
        
        //!  Basic position in the 4D space
        virtual Vector4D    position() const = 0;
        
        //!  Set position the position
        virtual void        position(set_k, const Vector4D&){}
        
        virtual void        position(set_k, x_k, double){}
        virtual void        position(set_k, y_k, double){}
        virtual void        position(set_k, z_k, double){}
        virtual void        position(set_k, w_k, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(add_k, const Vector4D&Δ){}
        virtual void        position(add_k, x_k, double Δx){}
        virtual void        position(add_k, y_k, double Δy){}
        virtual void        position(add_k, z_k, double Δz){}
        virtual void        position(add_k, w_k, double Δz){}

        virtual void        position(multiply_k, double){}
        virtual void        position(multiply_k, const Vector4D&Δ){}
        virtual void        position(multiply_k, x_k, double Δx){}
        virtual void        position(multiply_k, y_k, double Δy){}
        virtual void        position(multiply_k, z_k, double Δz){}
        virtual void        position(multiply_k, w_k, double Δz){}

        virtual bool        position(disabled_k) const { return false; }
        virtual bool        position(settable_k) const { return false; }
        virtual bool        position(addable_k) const { return false; }
        virtual bool        position(multipliable_k) const { return false; }

        static void init_info();
    };
}
