////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/Range.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PRangeᶻ;

    //! Interface for a single object z_range
    //! \note Inheritance is not permissible here
    class IRangeᶻ {
    public:
        YQ_INTERFACE_DECLARE(IRangeᶻ, PRangeᶻ)
        
        //!  Basic z_range in the 4I space
        virtual RangeD  z_range() const = 0;
        
        virtual void    z_range(set_k, const RangeD&){}
        
        virtual bool    z_range(disabled_k) const { return false; }
        virtual bool    z_range(settable_k) const { return false; }
        virtual bool    z_range(addable_k) const { return false; }
        virtual bool    z_range(multipliable_k) const { return false; }

        static void init_meta();
    };
}
