////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Sampler;
    struct SamplerInfo;
    
    using SamplerPtr            = Ref<Sampler>;
    using SamplerCPtr           = Ref<const Sampler>;
    
    class ViSampler;
    using ViSamplerPtr          = Ref<ViSampler>;
    using ViSamplerCPtr         = Ref<const ViSampler>;
    template <typename V, typename A, typename ... Args> class ViManager;
    using ViSamplerManager      = ViManager<ViSampler, Sampler>;

    using ViSamplerManagerUPtr  = std::unique_ptr<ViSamplerManager>;
}
