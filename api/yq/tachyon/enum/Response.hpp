////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! Response Codes
    
        (Result is already taken in the toolbox.)
        
        Zero        is success
        Positive    is delays
        Negatives   is failure/rejection
        
    */
    YQ_ENUM(Response, ,
        //! Success
        QaPla           = 0,
        Accepted        = QaPla,
        Success         = QaPla,
        
        //! Generic failure
        Failed          = -1,
        
        //! General rejection
        Rejected        = -2,
        
        //! Similar request received
        Duplicate       = -3,
        
        //! It's attached to something
        NotUnattached   = -4,
        
        //! Sent us a null pointer
        NullPointer     = -5,
        
        // Busy/Processing
        Busy            = 1,
        Processing      = Busy,
    );
}
YQ_TYPE_DECLARE(yq::tachyon::Response)
