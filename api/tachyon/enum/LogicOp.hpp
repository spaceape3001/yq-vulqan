////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Logical operation
    
        Logical operation, as submitted to vulkan.
    */
    YQ_ENUM(LogicOp, , 
        Clear           = 0,
        And             = 1,
        AndReverse      = 2,
        Copy            = 3,
        AndInverted     = 4,
        NoOp            = 5,
        Xor             = 6,
        Or              = 7,
        Nor             = 8,
        Equivalent      = 9,
        Invert          = 10,
        OrReverse       = 11,
        CopyInverted    = 12,
        OrInverted      = 13,
        Nand            = 14,
        Set             = 15
    )
}
YQ_TYPE_DECLARE(yq::tachyon::LogicOp)
