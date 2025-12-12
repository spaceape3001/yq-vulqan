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
    class PCount²;

    //! Interface for a single object count
    //! \note Inheritance is not permissible here
    class ICount² {
    public:
        YQ_INTERFACE_DECLARE(ICount², PCount²)
        
        //!  Basic count in the 2D space
        virtual Vector2U    count() const = 0;
        
        //!  Set count the count
        virtual void        count(set_k, const Vector2U&){}
        
        virtual void        count(set_k, x_k, unsigned x){}
        virtual void        count(set_k, y_k, unsigned y){}
        
        //!  Move the count (ie set to count + delta)
        virtual void        count(add_k, const Vector2U&Δ){}
        virtual void        count(add_k, x_k, unsigned Δx){}
        virtual void        count(add_k, y_k, unsigned Δy){}

        virtual void        count(multiply_k, unsigned){}
        virtual void        count(multiply_k, const Vector2U&Δ){}
        virtual void        count(multiply_k, x_k, unsigned Δx){}
        virtual void        count(multiply_k, y_k, unsigned Δy){}

        virtual bool        count(disabled_k) const { return false; }
        virtual bool        count(settable_k) const { return false; }
        virtual bool        count(addable_k) const { return false; }
        virtual bool        count(multipliable_k) const { return false; }

        static void init_meta();
    };
}
