////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Enum.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Mipmap mode
    */
    YQ_ENUM(MipmapMode, , 
        Nearest = 0,
        Linear = 1
    )
}

YQ_TYPE_DECLARE(yq::tachyon::MipmapMode)
