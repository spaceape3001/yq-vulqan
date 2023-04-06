////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <optional>
#include <vector>
#include <tachyon/preamble.hpp>

#include <tachyon/enum/CullMode.hpp>
#include <tachyon/enum/DataFormat.hpp>
#include <tachyon/enum/FrontFace.hpp>
#include <tachyon/enum/PipelineBinding.hpp>
#include <tachyon/enum/PolygonMode.hpp>
#include <tachyon/enum/PushConfigType.hpp>
#include <tachyon/enum/Topology.hpp>
#include <tachyon/enum/VertexInputRate.hpp>

namespace yq {
    namespace tachyon {
        struct VBOAttr {
            DataFormat      format;
            uint32_t        location    = UINT32_MAX;
            uint32_t        offset      = 0;
        };

        struct VBOConfig {
            std::vector<VBOAttr>    attrs;
            uint32_t                stride      = 0;
            uint32_t                shaders     = 0;    //  shader mask
            VertexInputRate         inputRate;
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
            Topology                    topology    = Topology::TriangleList;
            PolygonMode                 polymode    = PolygonMode::Fill;
            FrontFace                   front       = FrontFace::CounterClockwise;
            CullMode                    culling     = CullMode::Back;
            PushConfig                  push        = {};
            PipelineBinding             binding     = PipelineBinding::Graphics;
            
            PipelineConfig();
            ~PipelineConfig();
        };
    }
}
