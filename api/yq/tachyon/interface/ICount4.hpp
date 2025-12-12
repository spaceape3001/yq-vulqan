////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector4.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PCount⁴;

    //! Interface for a single object count
    //! \note Inheritance is not permissible here
    class ICount⁴ {
    public:
        YQ_INTERFACE_DECLARE(ICount⁴, PCount⁴)
        
        //!  Basic count in the 4D space
        virtual Vector4U    count() const = 0;
        
        //!  Set count the count
        virtual void        count(set_k, const Vector4U&){}
        
        virtual void        count(set_k, x_k, unsigned){}
        virtual void        count(set_k, y_k, unsigned){}
        virtual void        count(set_k, z_k, unsigned){}
        virtual void        count(set_k, w_k, unsigned){}
        
        //!  Move the count (ie set to count + delta)
        virtual void        count(add_k, const Vector4U&Δ){}
        virtual void        count(add_k, x_k, unsigned Δx){}
        virtual void        count(add_k, y_k, unsigned Δy){}
        virtual void        count(add_k, z_k, unsigned Δz){}
        virtual void        count(add_k, w_k, unsigned Δz){}

        virtual void        count(multiply_k, unsigned){}
        virtual void        count(multiply_k, const Vector4U&Δ){}
        virtual void        count(multiply_k, x_k, unsigned Δx){}
        virtual void        count(multiply_k, y_k, unsigned Δy){}
        virtual void        count(multiply_k, z_k, unsigned Δz){}
        virtual void        count(multiply_k, w_k, unsigned Δz){}

        virtual bool        count(disabled_k) const { return false; }
        virtual bool        count(settable_k) const { return false; }
        virtual bool        count(addable_k) const { return false; }
        virtual bool        count(multipliable_k) const { return false; }

        static void init_meta();
    };
}
