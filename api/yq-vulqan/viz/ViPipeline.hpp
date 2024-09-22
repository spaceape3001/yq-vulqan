////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Flags.hpp>
#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/trait/numbers.hpp>
#include <yq-vulqan/basic/Tristate.hpp>
#include <yq-vulqan/pipeline/CullMode.hpp>
#include <yq-vulqan/pipeline/PolygonMode.hpp>
#include <yq-vulqan/typedef/pipeline.hpp>
#include <yq-vulqan/typedef/pipeline_layout.hpp>
#include <yq-vulqan/typedef/render_pass.hpp>
#include <yq-vulqan/typedef/swapchain.hpp>
#include <optional>
#include <vulkan/vulkan_core.h>


namespace yq::tachyon {
    class ViVisualizer;

    struct ViPipelineOptions {
        //! Culling mode
        CullMode                    cull_mode           = CullMode::Auto;
    
        //! Rasterization line width (nan takes it from the pipeline configuration)
        float                       line_width          = NaNf;
        
        //! If specified, overrides the configuratoin
        PolygonMode                 polygon_mode        = PolygonMode::Auto;
        
        //! Our scissors.  If specified, overrides the swapchain's default
        VkRect2D                    scissor             = {};
        
        //! All our scissors.  If specified, overrides scissor and swapchain's default
        std::span<const VkRect2D>   scissors            = {};
        
        //! The swapchain in use
        ViSwapchainCPtr             swapchain;
        
        //! Restart the primitives?  See VkPipelineInputAssemblyStateCreateInfo documentation for details
        Tristate                    primitive_restart   = Tristate::Inherit;

        //! The renderpass to use
        VkRenderPass                render_pass         = nullptr;

        //! Our viewport.  If specified, overrides the swapchain's default
        VkViewport                  viewport            = {};
        
        //! All our viewports.  If specified, overrides viewport and swapchain's default
        std::span<const VkViewport> viewports           = {};
        
        //! Set to allow for wireframing
        Tristate                    wireframe           = Tristate::Inherit;
        
        bool                        depth_clamp         = false;
        bool                        rasterizer_discard   = false;
    };

    class ViPipeline : public RefCount {
    public:
    
        ViPipeline();
        ViPipeline(ViVisualizer&, ViPipelineLayoutCPtr, const ViPipelineOptions& opts={});
        ViPipeline(ViVisualizer&, const Pipeline&, const ViPipelineOptions& opts={});
        ~ViPipeline();
        
        std::error_code     init(ViVisualizer&, ViPipelineLayoutCPtr, const ViPipelineOptions& opts={});
        std::error_code     init(ViVisualizer&, const Pipeline&, const ViPipelineOptions& opts={});
        void                kill();

        VkPipelineBindPoint bind_point() const { return m_binding; }
        bool                consistent() const;
        VkPipeline          pipeline() const { return m_pipeline; }
        bool                valid() const;
        VkPipeline          wireframe_pipeline() const { return m_wireframe; }
    
    private:
        std::error_code _init(ViVisualizer&, ViPipelineLayoutCPtr, const ViPipelineOptions& opts);
        std::error_code _init(ViVisualizer&, const Pipeline&, const ViPipelineOptions& opts);
        void            _kill();
        
        enum class S : uint8_t {
            Wireframe   = 0
        };
        
        ViVisualizer*           m_viz           = nullptr;
        ViPipelineLayoutCPtr    m_layout;
        VkPipeline              m_pipeline      = nullptr;
        VkPipeline              m_wireframe     = nullptr;
        VkPipelineBindPoint     m_binding       = VK_PIPELINE_BIND_POINT_GRAPHICS;
        Flags<S>                m_status        = {};
        
        ViPipeline(const ViPipeline&) = delete;
        ViPipeline(ViPipeline&&) = delete;
        ViPipeline& operator=(const ViPipeline&) = delete;
        ViPipeline& operator=(ViPipeline&&) = delete;
    };
}
