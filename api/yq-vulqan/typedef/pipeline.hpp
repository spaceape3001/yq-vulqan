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
    using PipelinePtr           = Ref<Pipeline>;
    using PipelineCPtr          = Ref<const Pipeline>;
    
    struct PipelineConfig;
    using SharedPipelineConfig  = std::shared_ptr<const PipelineConfig>;
    
    struct ViPipelineOptions;

    class ViPipeline;
    using ViPipelinePtr         = Ref<ViPipeline>;
    using ViPipelineCPtr        = Ref<const ViPipeline>;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViPipelineManager     = ViManager<const ViPipeline, PipelineCPtr, ViPipelineOptions>;
    using ViPipelineManagerUPtr = std::unique_ptr<ViPipelineManager>;
    using ViPipelineManagerSPtr = std::shared_ptr<ViPipelineManager>;
}
