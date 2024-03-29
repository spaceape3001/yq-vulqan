////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! \brief Tristate enumeration
    
        This tristate allows for overriding or taking the prevailing option
    */
    YQ_ENUM(Tristate, ,
        
        //! Default is a "maybe", which means inherit and/or optional
        MAYBE       = 1,
        
        //! Assert a NO on this state, override the inheritance
        NO          = 0,
        
        //! Assert a YES on this state, override the inheritance
        YES         = 2,
        
        //! Synonym for "maybe"
        INHERIT     = MAYBE,

        //! Synonym for "maybe"
        OPTIONAL    = MAYBE
    );
}

YQ_TYPE_DECLARE(yq::tachyon::Tristate)
