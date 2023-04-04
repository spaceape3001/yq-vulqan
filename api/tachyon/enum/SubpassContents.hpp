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
        YQ_ENUM(SubpassContents, ,
            Inline = 0,
            SecondaryCommandBuffers = 1
        )
    }
}
YQ_TYPE_DECLARE(yq::tachyon::SubpassContents)
