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
    class PRangeʷ;

    //! Interface for a single object w_range
    //! \note Inheritance is not permissible here
    class IRangeʷ {
    public:
        YQ_INTERFACE_DECLARE(IRangeʷ, PRangeʷ)
        
        //!  Basic w_range in the 4I space
        virtual RangeD  w_range() const = 0;
        
        virtual void    w_range(set_k, const RangeD&){}
        
        virtual bool    w_range(disabled_k) const { return false; }
        virtual bool    w_range(settable_k) const { return false; }

        static void init_meta();
    };
}
