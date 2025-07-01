////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector3.hpp>
#include <tachyon/keywords.hpp>
#include <tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PScale³;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IScale³ {
    public:
        YQ_INTERFACE_DECLARE(IScale³, PScale³)
        
        virtual Vector3D    scale() const = 0;
        
        virtual void        scale(set_k, const Vector3D&){}
        virtual void        scale(set_k, x_k, double){}
        virtual void        scale(set_k, y_k, double){}
        virtual void        scale(set_k, z_k, double){}
        
        virtual void        scale(add_k, const Vector3D&Δ){}
        virtual void        scale(add_k, x_k, double Δx){}
        virtual void        scale(add_k, y_k, double Δy){}
        virtual void        scale(add_k, z_k, double Δz){}

        virtual void        scale(multiply_k, double){}
        virtual void        scale(multiply_k, const Vector3D&Δ){}
        virtual void        scale(multiply_k, x_k, double Δx){}
        virtual void        scale(multiply_k, y_k, double Δy){}
        virtual void        scale(multiply_k, z_k, double Δz){}

        virtual bool        scale(disabled_k) const { return false; }
        virtual bool        scale(settable_k) const { return false; }
        virtual bool        scale(addable_k) const { return false; }
        virtual bool        scale(multipliable_k) const { return false; }

        static void init_meta();
    };
}
