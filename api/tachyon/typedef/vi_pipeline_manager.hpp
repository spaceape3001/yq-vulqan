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
    class ViPipeline;
    class ViPipelineLayout;
    
    struct ViPipelineOptions;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViPipelineManager     = ViManager<const ViPipeline, const Pipeline*, ViPipelineOptions>;
    using ViPipelineManagerUPtr = std::unique_ptr<ViPipelineManager>;
    using ViPipelineManagerSPtr = std::shared_ptr<ViPipelineManager>;

    template <typename V, typename A, typename ... Args> class ViManager2;
    using ViPipelineLayoutManager       = ViManager2<const ViPipelineLayout, const Pipeline*>;
    using ViPipelineLayoutManagerUPtr   = std::unique_ptr<ViPipelineLayoutManager>;
}
