////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>

namespace yq::tachyon {
    struct VertexDrawCall {
        uint32_t        vertex_count    = 0;
        uint32_t        instance_count  = 1;
        uint32_t        first_vertex    = 0;
        uint32_t        first_instance  = 0;
    };
    
    struct IndexDrawCall {
        uint32_t        index_count     = 0;
        uint32_t        instance_count  = 1;
        uint32_t        first_index     = 0;
        int32_t         vertex_offset   = 0;
        uint32_t        first_instance  = 0;
    };
}
