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
    class RenderPass;
    
    using RenderPassPtr     = Ref<RenderPass>;
    using RenderPassCPtr    = Ref<const RenderPass>;
    
    class ViRenderPass;
    using ViRenderPassPtr   = Ref<ViRenderPass>;
    using ViRenderPassCPtr  = Ref<const ViRenderPass>;
}
