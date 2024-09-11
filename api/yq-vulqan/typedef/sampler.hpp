////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Sampler;
    struct SamplerInfo;
    
    using SamplerPtr = Ref<Sampler>;
    using SamplerCPtr = Ref<const Sampler>;
    
    class ViSampler;
    using ViSamplerPtr    = Ref<ViSampler>;
    using ViSamplerCPtr   = Ref<const ViSampler>;
}
