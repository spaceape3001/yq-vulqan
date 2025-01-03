////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq::tachyon {
    class Shader;
    class ViShader;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViShaderManager       = ViManager<const ViShader, Shader>;

    using ViShaderManagerUPtr   = std::unique_ptr<ViShaderManager>;
}
