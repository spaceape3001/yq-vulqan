////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/meta/InfoBinder.hpp>

namespace yq {
    namespace engine {
        YQ_ENUM(SubpassContents, ,
            Inline = 0,
            SecondaryCommandBuffers = 1
        )
    }
}
YQ_TYPE_DECLARE(yq::engine::SubpassContents)
