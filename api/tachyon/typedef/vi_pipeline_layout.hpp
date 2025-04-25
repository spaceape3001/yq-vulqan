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
    class ViPipelineLayout;
    using ViPipelineLayoutPtr           = Ref<ViPipelineLayout>;
    using ViPipelineLayoutCPtr          = Ref<const ViPipelineLayout>;
}
