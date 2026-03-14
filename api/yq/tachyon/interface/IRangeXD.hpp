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
    class PRangeˣD;

    //! Interface for a single object x_range
    //! \note Inheritance is not permissible here
    class IRangeˣD {
    public:
        YQ_INTERFACE_DECLARE(IRangeˣD, PRangeˣD)
        
        //!  Basic x_range in the 4I space
        virtual RangeD  x_range() const = 0;
        
        virtual void    x_range(set_k, const RangeD&){}
        
        virtual bool    x_range(disabled_k) const { return false; }
        virtual bool    x_range(settable_k) const { return false; }
        virtual bool    x_range(addable_k) const { return false; }
        virtual bool    x_range(multipliable_k) const { return false; }

        static void init_meta();
    };
}
