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
    class POuterTessellation³;

    //! Interface for a single object outer_tessellation
    //! \note Inheritance is not permissible here
    class IOuterTessellation³ {
    public:
        YQ_INTERFACE_DECLARE(IOuterTessellation³, POuterTessellation³)
        
        //!  Basic outer_tessellation in the 3D space
        virtual Vector3D    outer_tessellation() const = 0;
        
        //!  Set outer_tessellation the outer_tessellation
        virtual void        outer_tessellation(set_k, const Vector3D&){}

        virtual bool        outer_tessellation(disabled_k) const { return false; }
        virtual bool        outer_tessellation(settable_k) const { return false; }

        static void init_meta();
    };
}
