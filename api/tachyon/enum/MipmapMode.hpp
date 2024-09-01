////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Mipmap mode
    */
    YQ_ENUM(MipmapMode, , 
        Nearest = 0,
        Linear = 1
    )
}

YQ_TYPE_DECLARE(yq::tachyon::MipmapMode)
