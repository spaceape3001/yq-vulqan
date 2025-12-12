////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector1.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PCount¹;

    //! Interface for a single object count
    //! \note Inheritance is not permissible here
    class ICount¹ {
    public:
        YQ_INTERFACE_DECLARE(ICount¹, PCount¹)
        
        //!  Basic count in the 1D space
        virtual Vector1U    count() const = 0;
        
        //!  Set count the count
        virtual void        count(set_k, const Vector1U&){}
        virtual void        count(set_k, x_k, unsigned){}
        
        //!  Move the count (ie set to count + delta)
        virtual void        count(add_k, const Vector1U&Δ){}
        virtual void        count(add_k, x_k, unsigned Δx){}

        virtual void        count(multiply_k, unsigned){}
        virtual void        count(multiply_k, const Vector1U&Δ){}
        virtual void        count(multiply_k, x_k, unsigned Δx){}
        
        virtual bool        count(disabled_k) const { return false; }
        virtual bool        count(settable_k) const { return false; }
        virtual bool        count(addable_k) const { return false; }
        virtual bool        count(multipliable_k) const { return false; }

        static void init_meta();
    };
}
