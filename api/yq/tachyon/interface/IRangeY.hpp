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
    class PRangeʸ;

    //! Interface for a single object y_range
    //! \note Inheritance is not permissible here
    class IRangeʸ {
    public:
        YQ_INTERFACE_DECLARE(IRangeʸ, PRangeʸ)
        
        //!  Basic y_range in the 4I space
        virtual RangeD  y_range() const = 0;
        
        virtual void    y_range(set_k, const RangeD&){}
        
        virtual bool    y_range(disabled_k) const { return false; }
        virtual bool    y_range(settable_k) const { return false; }
        virtual bool    y_range(addable_k) const { return false; }
        virtual bool    y_range(multipliable_k) const { return false; }

        static void init_meta();
    };
}
