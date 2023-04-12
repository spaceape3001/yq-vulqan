////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(DataActivity, , 
        //! Make zero expectations, ie, gets ignored
        UNSURE  = 0,
    
        //! Data is shared between *ALL* things of same class
        COMMON,         // <- expect data to be transferred to GPU memory
        
        //! Data is fixed to this instance of the class, but wont change after creation
        FIXED,         // <- expect data to be transferred to GPU memory
        
        STATIC = FIXED,
        
        //! Data may (occsaionally) change with time
        //! Revision management recommended
        DYNAMIC,
        
        //! Data is expected to ALWAYS change with time
        //! Revision management might be useful for things not changing every tick.
        REFRESH
    )
}

YQ_TYPE_DECLARE(yq::tachyon::DataActivity)
