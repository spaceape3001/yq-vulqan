////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/BasicBuffer.hpp>
#include <tachyon/preamble.hpp>
#include <vector>
#include <vulkan/vulkan_core.hpp>

namespace yq::tachyon {

    /*! 
        A broken down render based on WHATEVER..
        This will occur once we're to some sort of tick-based task loop
    */
    struct ViRender {
        struct VB {
            VkBuffer        buffer  = nullptr;
            uint32_t        binding = 0;
        };
        
        struct IB {
            VkBuffer        buffer  = nullptr;
            uint32_t        count   = 0;
            uint32_t        type    = 0;
        };
        
        struct UB {
            VkBuffer        buffer  = nullptr;
        };
        
        struct TB {
            VkImage         image   = nullptr;
        };

        PushBuffer          push;
        
        std::vector<VB>     vbos;
        std::vector<IB>     ibos;
        std::vector<UB>     ubos;
        std::vector<TB>     texs;
        
        VkPipeline          pipeline    = nullptr;
        VkPipelineLayout    layout      = nullptr;
        uint64_t            id          = 0;

        uint32_t            shaders     = 0;
        uint32_t            vCount      = 0;
        uint32_t            iCount      = 0;
    };
}
