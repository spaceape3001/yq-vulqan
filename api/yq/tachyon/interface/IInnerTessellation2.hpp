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
    class PInnerTessellation²;

    //! Interface for a single object inner_tessellation
    //! \note Inheritance is not permissible here
    class IInnerTessellation² {
    public:
        YQ_INTERFACE_DECLARE(IInnerTessellation², PInnerTessellation²)
        
        //!  Basic inner_tessellation in the 2D space
        virtual Vector2D    inner_tessellation() const = 0;
        
        //!  Set inner_tessellation the inner_tessellation
        virtual void        inner_tessellation(set_k, const Vector2D&){}

        virtual bool        inner_tessellation(disabled_k) const { return false; }
        virtual bool        inner_tessellation(settable_k) const { return false; }

        static void init_meta();
    };
}
