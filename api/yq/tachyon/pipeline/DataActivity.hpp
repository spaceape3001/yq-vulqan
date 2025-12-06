////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {

    /*! \brief Data Activity
    
        This enumeration is the expected activity of something on the pipeline.  
        This can lead to better optimizations.
    */

    YQ_ENUM(DataActivity, , 
        //! Make zero expectations, ie, gets ignored
        UNSURE  = 0,
    
        //! Externally supplied (it'll be provided...)
        EXTERNAL,
    
        //! Data is shared between *ALL* things of same class (and/or scene) but may change frame to frame
        COMMON,   // <- expect data to be transferred to GPU memory

        //! Data is staticly common (won't change frame to frame)
        STATIC,
        
        //! Data is fixed to this instance of the class, but wont change after creation
        FIXED,    // <- expect data to be transferred to GPU memory
        
        //! Data may (occsaionally) change with time
        //! Revision management recommended
        DYNAMIC,
        
        //! Common data that's expected to ALWAYS change with time
        SHARED,
        
        //! Data is expected to ALWAYS change with time
        //! Revision management might be useful for things not changing every tick.
        REFRESH
    )
}

YQ_TYPE_DECLARE(yq::tachyon::DataActivity)
