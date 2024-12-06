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
        virtual void        position3d(set_t, const Vector3D&){}
        
        //virtual void        position3d(set_t, x_t, double){}
        //virtual void        position3d(set_t, y_t, double){}
        //virtual void        position3d(set_t, z_t, double){}
        
        //!  Move the position (ie set to position + delta)
        virtual void        position3d(adjust_t, const Vector3D&){}

        //virtual void        position3d(adjust_t, x_t, double){}
        //virtual void        position3d(adjust_t, y_t, double){}
        //virtual void        position3d(adjust_t, z_t, double){}

        virtual bool        position3d(disabled_t) const { return false; }
        virtual bool        position3d(settable_t) const { return false; }
        virtual bool        position3d(adjustable_t) const { return false; }

        static void init_info();
    };
}
