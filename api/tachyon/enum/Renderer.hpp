////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Flags.hpp>

namespace yq {
    namespace tachyon {
        enum class Renderer : uint8_t {
            Vulkan  = 0,
            ImGui
        };
        
        using RendererFlags = Flags<Renderer,uint8_t>;
    }
}

