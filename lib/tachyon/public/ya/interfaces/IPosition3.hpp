////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector3.hpp>
#include <yt/keywords.hpp>
#include <yt/api/Interface.hpp>

namespace yq::tachyon {
    class PPosition³;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition³ {
    public:
        YQ_INTERFACE_DECLARE(IPosition³, PPosition³)
        
        //!  Basic position in the 3D space
        virtual Vector3D    position() const = 0;
        
        //!  Set position the position
        virtual void        position(set_k, const Vector3D&){}
        
        virtual void        position(set_k, x_k, double){}
        virtual void        position(set_k, y_k, double){}
        virtual void        position(set_k, z_k, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(move_k, const Vector3D&Δ){}

        virtual void        position(move_k, x_k, double Δx){}
        virtual void        position(move_k, y_k, double Δy){}
        virtual void        position(move_k, z_k, double Δz){}

        virtual bool        position(disabled_k) const { return false; }
        virtual bool        position(settable_k) const { return false; }
        virtual bool        position(moveable_k) const { return false; }

        static void init_info();
    };
}
