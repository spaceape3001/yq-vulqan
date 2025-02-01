////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>

namespace yq::tachyon {
    
    enum class RType {
        None,
        Delegate,
        Tachyon
    };

    struct Recipe {
        RType      type     = RType::None;
        
        
    };
    
}
