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
    class PScale²;

    //! Interface for a single object scale
    //! \note Inheritance is not permissible here
    class IScale² {
    public:
        YQ_INTERFACE_DECLARE(IScale², PScale²)
        
        virtual Vector2D    scale() const = 0;
        
        virtual void        scale(set_k, const Vector2D&){}
        
        virtual void        scale(set_k, x_k, double x){}
        virtual void        scale(set_k, y_k, double y){}
        
        virtual void        scale(add_k, const Vector2D&Δ){}
        virtual void        scale(add_k, x_k, double Δx){}
        virtual void        scale(add_k, y_k, double Δy){}

        virtual void        scale(multiply_k, double){}
        virtual void        scale(multiply_k, const Vector2D&Δ){}
        virtual void        scale(multiply_k, x_k, double Δx){}
        virtual void        scale(multiply_k, y_k, double Δy){}

        virtual bool        scale(disabled_k) const { return false; }
        virtual bool        scale(settable_k) const { return false; }
        virtual bool        scale(addable_k) const { return false; }
        virtual bool        scale(multipliable_k) const { return false; }

        static void init_meta();
    };
}
