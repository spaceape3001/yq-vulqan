////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    
    /*! \brief Comparison operator
    
        This is the comparison operator enumeration (used by vulkan).
    *//*
        From this table... easy to see the bit pattern
        
        never           000
        less            001
        equal           010
        less_equal      011
        greater         100
        not equal       101
        greater equal   110
        always          111
        
        (ie, the comparison on the GPU comes to three status bits, 
            and this is the match/no-match state)
    */
    YQ_ENUM(CompareOp, , 
        //! Always fail
        Never           = 0,
        
        //! Less than
        Less            = 1,
        
        //! Equality
        Equal           = 2,
        
        //! Less Or equal
        LessOrEqual     = 3,
        
        //! Greater
        Greater         = 4,
        
        //! Not equal
        NotEqual        = 5,
        
        //! Greater or equal
        GreaterOrEqual  = 6,
        
        //! Always
        Always          = 7
    )
}
YQ_TYPE_DECLARE(yq::tachyon::CompareOp)
