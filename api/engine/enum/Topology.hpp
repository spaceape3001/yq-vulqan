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
        YQ_ENUM(Topology, , 
            PointList = 0,
            LineList = 1,
            LineStrip = 2,
            TriangleList = 3,
            TriangleStrip = 4,
            TriangleFan = 5,
            LineListWithAdjacency = 6,
            LineStripWithAdjacency = 7,
            TriangleListWithAdjacency = 8,
            TriangleStripWithAdjacency = 9,
            PatchList = 10
        )
    }
}
YQ_TYPE_DECLARE(yq::engine::Topology)
