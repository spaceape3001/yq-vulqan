////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/ByteArray.hpp>
#include <system_error>

namespace yq {

    namespace tachyon {
        //! Used for compiler results
        struct ResultCC {
        
            //! Output (if not into file)
            ByteArray       payload;
            
            #ifdef error
            #undef error
            #endif
            
            //! Errors
            ByteArray       error;
            
            //! Success?
            std::error_code ec;
        };
    }
}
