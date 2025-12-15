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
    class PInnerTessellation¹;

    //! Interface for a single object inner_tessellation
    //! \note Inheritance is not permissible here
    class IInnerTessellation¹ {
    public:
        YQ_INTERFACE_DECLARE(IInnerTessellation¹, PInnerTessellation¹)
        
        //!  Basic inner_tessellation in the 1D space
        virtual Vector1D    inner_tessellation() const = 0;
        
        //!  Set inner_tessellation the inner_tessellation
        virtual void        inner_tessellation(set_k, const Vector1D&){}

        virtual bool        inner_tessellation(disabled_k) const { return false; }
        virtual bool        inner_tessellation(settable_k) const { return false; }

        static void init_meta();
    };
}
