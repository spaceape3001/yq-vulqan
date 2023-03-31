////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(DataActivity, , 
            //! Make zero expectations, ie, gets ignored
            UNSURE  = 0,
        
            //! Data is shared between *ALL* things of same class
            COMMON,         // <- expect data to be transferred to GPU memory
            
            //! Data is fixed to this instance of the class, but wont change after creation
            STATIC,         // <- expect data to be transferred to GPU memory
            
            //! Data may (occsaionally) change with time
            DYNAMIC,
            
            //! Data is expected to ALWAYS change with time
            REFRESH
        )
    }
}

YQ_TYPE_DECLARE(yq::tachyon::DataActivity)
