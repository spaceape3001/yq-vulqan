////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Mipmap mode
    */
    YQ_ENUM(MipmapMode, , 
        Nearest = 0,
        Linear = 1
    )
}

YQ_TYPE_DECLARE(yq::tachyon::MipmapMode)
