////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector2.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition²;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition² {
    public:
        YQ_INTERFACE_DECLARE(IPosition², PPosition²)
        
        //!  Basic position in the 2D space
        virtual Vector2D    position() const = 0;
        
        //!  Set position the position
        virtual void        position(set_k, const Vector2D&){}
        
        virtual void        position(set_k, x_k, double x){}
        virtual void        position(set_k, y_k, double y){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(add_k, const Vector2D&Δ){}
        virtual void        position(add_k, x_k, double Δx){}
        virtual void        position(add_k, y_k, double Δy){}

        virtual void        position(multiply_k, double){}
        virtual void        position(multiply_k, const Vector2D&Δ){}
        virtual void        position(multiply_k, x_k, double Δx){}
        virtual void        position(multiply_k, y_k, double Δy){}

        virtual bool        position(disabled_k) const { return false; }
        virtual bool        position(settable_k) const { return false; }
        virtual bool        position(addable_k) const { return false; }
        virtual bool        position(multipliable_k) const { return false; }

        static void init_meta();
    };
}
