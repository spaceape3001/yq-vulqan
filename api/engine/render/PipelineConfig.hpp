////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <optional>
#include <vector>
#include <engine/preamble.hpp>

#include <tachyon/enum/CullMode.hpp>
#include <tachyon/enum/DataFormat.hpp>
#include <tachyon/enum/FrontFace.hpp>
#include <tachyon/enum/PolygonMode.hpp>
#include <tachyon/enum/Topology.hpp>
#include <tachyon/enum/VertexInputRate.hpp>

namespace yq {
    namespace engine {

        struct VBOAttr {
            tachyon::DataFormat      format;
            uint32_t        location    = UINT32_MAX;
            uint32_t        offset      = 0;
        };

        struct VBOConfig {
            std::vector<VBOAttr>    attrs;
            uint32_t                stride      = 0;
            uint32_t                shaders     = 0;    //  shader mask
            tachyon::VertexInputRate         inputRate;
        };
        
        struct UBOConfig {
            uint32_t            count   = 1;
            uint32_t            stage   = 0;
        };
        
        struct PushConfig {
            size_t          size    = 0;
            PushConfigType  type    = PushConfigType::None;
            uint32_t        shaders = 0;            // shader mask (0 implies shaders)
        };
        
        struct PipelineConfig {
            std::vector<ShaderSpec>     shaders;
            std::vector<VBOConfig>      vbos;
            std::vector<UBOConfig>      ubos;
            tachyon::Topology                    topology    = tachyon::Topology::TriangleList;
            tachyon::PolygonMode                 polymode    = tachyon::PolygonMode::Fill;
            tachyon::FrontFace                   front       = tachyon::FrontFace::CounterClockwise;
            tachyon::CullMode                    culling     = tachyon::CullMode::Back;
            PushConfig                  push        = {};
            
            PipelineConfig();
            ~PipelineConfig();
        };
    }
}
