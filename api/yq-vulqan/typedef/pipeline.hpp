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
    using PipelinePtr     = Ref<Pipeline>;
    using PipelineCPtr    = Ref<const Pipeline>;
    
    struct PipelineConfig;
    using SharedPipelineConfig    = std::shared_ptr<const PipelineConfig>;
    
    class ViPipeline;
    using ViPipelinePtr       = Ref<ViPipeline>;
    using ViPipelineCPtr      = Ref<const ViPipeline>;
}
