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
    class ViSampler;
    using ViSamplerPtr          = Ref<ViSampler>;
    using ViSamplerCPtr         = Ref<const ViSampler>;
}