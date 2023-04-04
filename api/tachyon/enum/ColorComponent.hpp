////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/Flag.hpp>
#include <meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(ColorComponent, , 
            Red     = 0,
            Green   = 1,
            Blue    = 2,
            Alpha   = 3
        )
        
        using ColorComponentFlags   = Flag<ColorComponent>;
    }
}

YQ_TYPE_DECLARE(yq::tachyon::ColorComponent)
YQ_TYPE_DECLARE(yq::tachyon::ColorComponentFlags)
