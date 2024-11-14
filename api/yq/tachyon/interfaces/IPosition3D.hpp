////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/vector/Vector3.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/PluginID.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    //! Interface for a single object position
    //! \note Inheritance is not permissible here
    class IPosition3D {
    public:
        //!  Basic position in the 3D space
        virtual Vector3D        position3d() const = 0;
        
        //!  Set position the position
        virtual void            position3d(set_t, const Vector3D&){}
        
        //!  Move the position (ie set to position + delta)
        virtual void            position3d(move_t, const Vector3D&){}

        static void init_info();
    };
}
YQ_INTERFACE_DECLARE(yq::tachyon::Position3D)
