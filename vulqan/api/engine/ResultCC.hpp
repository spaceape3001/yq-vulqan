////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/ByteArray.hpp>

namespace yq {

    namespace engine {
        //! Used for compiler results
        struct ResultCC {
        
            //! Output (if not into file)
            ByteArray   payload;
            
            //! Errors
            ByteArray   errors;
            
            //! Success?
            bool        good    = false;
        };
    }
}
