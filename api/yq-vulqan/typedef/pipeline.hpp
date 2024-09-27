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
    class Pipeline;
    
    struct ViPipelineOptions;

    class ViPipeline;
    using ViPipelinePtr         = Ref<ViPipeline>;
    using ViPipelineCPtr        = Ref<const ViPipeline>;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViPipelineManager     = ViManager<const ViPipeline, const Pipeline*, ViPipelineOptions>;
    using ViPipelineManagerUPtr = std::unique_ptr<ViPipelineManager>;
    using ViPipelineManagerSPtr = std::shared_ptr<ViPipelineManager>;
}
