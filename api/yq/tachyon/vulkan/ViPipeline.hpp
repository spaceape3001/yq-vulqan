////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/LogPriority.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/tachyon/pipeline/CullMode.hpp>
#include <yq/tachyon/pipeline/PolygonMode.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>
#include <yq/tachyon/typedef/vi_pipeline.hpp>
#include <yq/tachyon/typedef/vi_pipeline_layout.hpp>
#include <yq/tachyon/typedef/vi_render_pass.hpp>
#include <yq/tachyon/typedef/vi_swapchain.hpp>
#include <yq/trait/numbers.hpp>

#include <optional>
#include <span>
#include <vulkan/vulkan_core.h>

namespace yq {
    class Stream;
}

namespace yq::tachyon {
    class VizBase;

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
        //ViSwapchainCPtr             swapchain;
        
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
    
    struct ViPipelineReportOptions {
        std::string_view        message;
        bool                    layout      = true;
    };
    
    class Pipeline;

    class ViPipeline : public RefCount {
    public:
    
        ViPipeline(VizBase&, ViPipelineLayoutCPtr, const ViPipelineOptions& options={});
        ViPipeline(VizBase&, const Pipeline*, const ViPipelineOptions& options={});
        ~ViPipeline();
        
        uint64_t            id() const { return m_id; }

        VkPipelineBindPoint bind_point() const { return m_binding; }
        VkPipeline          pipeline() const { return m_pipeline; }
        bool                valid() const;
        VkPipeline          wireframe() const { return m_wireframe; }
        VkPipeline          wireframe_pipeline() const { return m_wireframe; }
        
        ViPipelineLayoutCPtr    layout() const;
        
        void                report(Stream&, const ViPipelineReportOptions& options={}) const;
        void                report(const char* cat="viz", LogPriority pri=LogPriority::Info, const ViPipelineReportOptions& options={}) const;

        VkPipeline          pipeline(Pipeline::Variation) const;
        VkPipeline          wireframe(Pipeline::Variation) const;

        const Pipeline* config () const { return m_config; }
    
    private:
        std::error_code _init(ViPipelineLayoutCPtr, const ViPipelineOptions& options);
        std::error_code _init(const Pipeline*, const ViPipelineOptions& options);
        void            _kill();
        
        enum class S : uint8_t {
            Wireframe   = 0
        };
        
        struct V {
            VkPipeline      pipeline    = nullptr;
            VkPipeline      wireframe   = nullptr;
        };
        
        using VMap  = std::map<Pipeline::Variation, V>;
        
        VizBase&                m_viz;
        VMap                    m_variations;
        ViPipelineLayoutCPtr    m_layout;
        VkPipeline              m_pipeline      = nullptr;
        VkPipeline              m_wireframe     = nullptr;
        VkPipelineBindPoint     m_binding       = VK_PIPELINE_BIND_POINT_GRAPHICS;
        Flags<S>                m_status        = {};
        uint64_t                m_id            = 0;
        const Pipeline*         m_config        = nullptr;
        
        ViPipeline(const ViPipeline&) = delete;
        ViPipeline(ViPipeline&&) = delete;
        ViPipeline& operator=(const ViPipeline&) = delete;
        ViPipeline& operator=(ViPipeline&&) = delete;
    };
}
