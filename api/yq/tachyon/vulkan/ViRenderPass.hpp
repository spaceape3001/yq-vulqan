////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/render_pass.hpp>
#include <yq/core/Ref.hpp>
//#include <yq/tachyon/RenderPassInfo.hpp>
#include <vulkan/vulkan_core.h>
#include <system_error>

namespace yq::tachyon {
    class ViVisualizer;
    
    class ViRenderPass : public RefCount {
    public:
        #if 0
        ViRenderPass(ViVisualizer&, const RenderPass&);
        ViRenderPass(ViVisualizer&, const RenderPassInfo&);
        #endif

        ViRenderPass(ViVisualizer&, const VkRenderPassCreateInfo&);
        ViRenderPass(ViVisualizer&, VkFormat);
        ~ViRenderPass();

        VkRenderPass            render_pass() const { return m_renderPass; }
        bool                    valid() const;
        ViVisualizer&           visualizer() { return m_viz; }
        const ViVisualizer&     visualizer() const { return m_viz; }
        
    private:
        ViVisualizer&       m_viz;
        VkRenderPass        m_renderPass    = nullptr;

        std::error_code         _init(const VkRenderPassCreateInfo&);
        std::error_code         _init(VkFormat);
        void                    _kill();
        void                    _wipe();
    };
}
