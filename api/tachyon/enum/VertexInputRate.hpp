////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(VertexInputRate, , 
            Vertex = 0,
            Instance = 1
        )
    }
}
YQ_TYPE_DECLARE(yq::tachyon::VertexInputRate)
