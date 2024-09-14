////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/render_pass.hpp>
#include <yq-toolbox/basic/Ref.hpp>
//#include <yq-vulqan/pass/RenderPassInfo.hpp>
#include <vulkan/vulkan_core.h>
#include <system_error>

namespace yq::tachyon {
    class ViVisualizer;
    
    class ViRenderPass : public RefCount {
    public:
        ViRenderPass();
        
        #if 0
        ViRenderPass(ViVisualizer&, const RenderPass&);
        ViRenderPass(ViVisualizer&, const RenderPassInfo&);
        #endif

        ViRenderPass(ViVisualizer&, const VkRenderPassCreateInfo&);
        
        ViRenderPass(ViVisualizer&, VkFormat);
        ~ViRenderPass();

        bool                    consistent() const;
        VkRenderPass            render_pass() const { return m_renderPass; }
        bool                    valid() const;
        ViVisualizer*           visualizer() const { return m_viz; }
        
        #if 0
        std::error_code         init(ViVisualizer&, const RenderPass&);
        std::error_code         init(ViVisualizer&, const RenderPassInfo&);
        #endif

        std::error_code         init(ViVisualizer&, const VkRenderPassCreateInfo&);
        
        std::error_code         init(ViVisualizer&, VkFormat);

        void                    kill();
    private:
        ViVisualizer*       m_viz           = nullptr;
        VkRenderPass        m_renderPass    = nullptr;

        std::error_code         _init(ViVisualizer&, const VkRenderPassCreateInfo&);

        #if 0
        std::error_code         _init(ViVisualizer&, const RenderPass&);
        std::error_code         _init(ViVisualizer&, const RenderPassInfo&);
        #endif
        
        std::error_code         _init(ViVisualizer&, VkFormat);
        void                    _kill();
        void                    _wipe();
    };
}
