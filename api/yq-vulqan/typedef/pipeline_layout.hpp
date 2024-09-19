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
    class ViPipelineLayout;
    using ViPipelineLayoutPtr           = Ref<ViPipelineLayout>;
    using ViPipelineLayoutCPtr          = Ref<const ViPipelineLayout>;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViPipelineLayoutManager       = ViManager<ViPipelineLayout, Pipeline>;
    using ViPipelineLayoutManagerUPtr   = std::unique_ptr<ViPipelineLayoutManager>;
}
