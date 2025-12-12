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
    class PCount³;

    //! Interface for a single object count
    //! \note Inheritance is not permissible here
    class ICount³ {
    public:
        YQ_INTERFACE_DECLARE(ICount³, PCount³)
        
        //!  Basic count in the 3D space
        virtual Vector3U    count() const = 0;
        
        //!  Set count the count
        virtual void        count(set_k, const Vector3U&){}
        
        virtual void        count(set_k, x_k, unsigned){}
        virtual void        count(set_k, y_k, unsigned){}
        virtual void        count(set_k, z_k, unsigned){}
        
        //!  Move the count (ie set to count + delta)
        virtual void        count(add_k, const Vector3U&Δ){}
        virtual void        count(add_k, x_k, unsigned Δx){}
        virtual void        count(add_k, y_k, unsigned Δy){}
        virtual void        count(add_k, z_k, unsigned Δz){}

        virtual void        count(multiply_k, unsigned){}
        virtual void        count(multiply_k, const Vector3U&Δ){}
        virtual void        count(multiply_k, x_k, unsigned Δx){}
        virtual void        count(multiply_k, y_k, unsigned Δy){}
        virtual void        count(multiply_k, z_k, unsigned Δz){}

        virtual bool        count(disabled_k) const { return false; }
        virtual bool        count(settable_k) const { return false; }
        virtual bool        count(addable_k) const { return false; }
        virtual bool        count(multipliable_k) const { return false; }

        static void init_meta();
    };
}
