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
    class PPosition3D;

    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition3D {
    public:
        YQ_INTERFACE_DECLARE(IPosition3D, PPosition3D)
        
        //!  Basic position in the 3D space
        virtual Vector3D    position3d() const = 0;
        
        //!  Set position the position
        virtual void        position3d(set_k, const Vector3D&){}
        
        //virtual void        position3d(set_k, x_k, double){}
        //virtual void        position3d(set_k, y_k, double){}
        //virtual void        position3d(set_k, z_k, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position3d(adjust_k, const Vector3D&){}

        //virtual void        position3d(adjust_k, x_k, double){}
        //virtual void        position3d(adjust_k, y_k, double){}
        //virtual void        position3d(adjust_k, z_k, double){}

        virtual bool        position3d(disabled_k) const { return false; }
        virtual bool        position3d(settable_k) const { return false; }
        virtual bool        position3d(adjustable_k) const { return false; }

        static void init_info();
    };
}
