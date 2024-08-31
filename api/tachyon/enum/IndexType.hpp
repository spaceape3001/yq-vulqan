////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Index type
    
        Data type code for the index buffer object 
    */
    YQ_ENUM(IndexType, ,
        none    = 1000165000,
        uint16  = 0,
        uint32  = 1,
        uint8   = 1000265000
    )
}
YQ_TYPE_DECLARE(yq::tachyon::IndexType)
