////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector1.hpp>
#include <tachyon/keywords.hpp>
#include <tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PScale¹;

    //! Interface for a single object scale
    //! \note Inheritance is not permissible here
    class IScale¹ {
    public:
        YQ_INTERFACE_DECLARE(IScale¹, PScale¹)
        
        virtual Vector1D    scale() const = 0;
        
        virtual void        scale(set_k, const Vector1D&){}
        virtual void        scale(set_k, x_k, double){}
        
        virtual void        scale(add_k, const Vector1D&Δ){}
        virtual void        scale(add_k, x_k, double Δx){}

        virtual void        scale(multiply_k, double){}
        virtual void        scale(multiply_k, const Vector1D&Δ){}
        virtual void        scale(multiply_k, x_k, double Δx){}

        virtual bool        scale(disabled_k) const { return false; }
        virtual bool        scale(settable_k) const { return false; }
        virtual bool        scale(addable_k) const { return false; }
        virtual bool        scale(multipliable_k) const { return false; }

        static void init_meta();
    };
}
