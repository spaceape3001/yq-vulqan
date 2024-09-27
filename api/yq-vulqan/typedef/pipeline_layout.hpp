////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>
#include <yq-vulqan/typedef/pipeline.hpp>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class ViPipelineLayout;
    using ViPipelineLayoutPtr           = Ref<ViPipelineLayout>;
    using ViPipelineLayoutCPtr          = Ref<const ViPipelineLayout>;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViPipelineLayoutManager       = ViManager<const ViPipelineLayout, PipelineCPtr>;
    using ViPipelineLayoutManagerUPtr   = std::unique_ptr<ViPipelineLayoutManager>;
}
