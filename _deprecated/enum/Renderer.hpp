////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Flags.hpp>

namespace yq::tachyon {
    /*! \brief Renderer
    
        Hint to renderers
    */
    enum class Renderer : uint8_t {
        Vulkan  = 0,
        ImGui
    };
    
    //! Bitmask of renderers.
    using RendererFlags = Flags<Renderer,uint8_t>;
}

