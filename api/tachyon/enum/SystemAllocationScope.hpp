////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(SystemAllocationScope, ,
            Command = 0,
            Object = 1,
            Cache = 2,
            Device = 3,
            Instance = 4
        )
    }
}
YQ_TYPE_DECLARE(yq::tachyon::SystemAllocationScope)
