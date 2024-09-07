////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Enum.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>

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