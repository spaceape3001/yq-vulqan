////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq::tachyon {
    class Sampler;
    class ViSampler;
    template <typename V, typename A, typename ... Args> class ViManager2;
    using ViSamplerManager      = ViManager2<const ViSampler, Sampler>;

    using ViSamplerManagerUPtr  = std::unique_ptr<ViSamplerManager>;
}
