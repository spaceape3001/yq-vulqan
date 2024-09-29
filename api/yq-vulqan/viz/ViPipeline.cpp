////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViPipeline.hpp"
#include <yq-toolbox/io/StreamOps.hpp>
#include <yq-toolbox/trait/has_nan.hpp>
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/v/VqUtils.hpp>
#include <yq-vulqan/viz/ViLogging.hpp>
#include <yq-vulqan/viz/ViPipelineLayout.hpp>
#include <yq-vulqan/viz/ViRenderPass.hpp>
#include <yq-vulqan/viz/ViSwapchain.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using pipeline_bad_state        = error_db::entry<"Pipeline is in a bad state">;
        using pipeline_existing         = error_db::entry<"Pipeline has already been created">;
        using pipeline_bad_config       = error_db::entry<"Pipeline has a bad configuration">;
        using pipeline_bad_layout       = error_db::entry<"Pipeline has a bad layout">;
        using pipeline_bad_swapchain    = error_db::entry<"Swapchain not provided to pipeline">;
        using pipeline_cant_create      = error_db::entry<"Unable to create the graphics pipeline">;
        using pipeline_null_pipeline    = error_db::entry<"Pipeline provided is NULL">;
    }
    
    ViPipeline::ViPipeline()
    {
    }
    
    ViPipeline::ViPipeline(ViVisualizer&viz, ViPipelineLayoutCPtr pLay, const ViPipelineOptions& opts)
    {
        if(viz.device() && pLay && pLay->valid()){
            std::error_code ec = _init(viz, pLay, opts);
            if(ec != std::error_code()){
                vizWarning << "ViPipeline(): Unable to initialize.  " << ec.message();
                _kill();
            }
        }
    }

    ViPipeline::ViPipeline(ViVisualizer&viz, const Pipeline*pipe, const ViPipelineOptions& opts)
    {
        if(viz.device() && pipe){
            std::error_code ec = _init(viz, pipe, opts);
            if(ec != std::error_code()){
                vizWarning << "ViPipeline(): Unable to initialize.  " << ec.message();
                _kill();
            }
        }
    }
    
    ViPipeline::~ViPipeline()
    {
        _kill();
    }
    
    std::error_code ViPipeline::_init(ViVisualizer&viz, const Pipeline* pipe, const ViPipelineOptions& opts)
    {
        ViPipelineLayoutCPtr        pLay    = viz.pipeline_layout_create(pipe);
        if(!pLay || !pLay->valid()){
            return errors::pipeline_bad_layout();
        }
        return _init(viz, pLay, opts);
    }

    std::error_code ViPipeline::_init(ViVisualizer&viz, ViPipelineLayoutCPtr pLay, const ViPipelineOptions& opts)
    {
        const Pipeline*    cfg = pLay->pipeline_config();
        if(!cfg){
            return errors::pipeline_bad_config();
        }
        
        m_viz       = &viz;
        m_layout    = pLay;
        m_binding   = (VkPipelineBindPoint) cfg->binding().value();
        m_status    = {};
        
        VqGraphicsPipelineCreateInfo pipelineInfo;

        const auto&   shaders = pLay->shader_infos();
        if(!shaders.empty()){
            pipelineInfo.stageCount = (uint32_t) shaders.size();
            pipelineInfo.pStages    = shaders.data();
        }
        
        pipelineInfo.pVertexInputState = &pLay->vertex_create_info();

        VqPipelineInputAssemblyStateCreateInfo inputAssembly;
        inputAssembly.topology                  = (VkPrimitiveTopology) cfg->topology().value();
        switch(opts.primitive_restart){
        case Tristate::No:
            inputAssembly.primitiveRestartEnable = VK_FALSE;
            break;
        case Tristate::Yes:
            inputAssembly.primitiveRestartEnable = VK_TRUE;
            break;
        case Tristate::Inherit:
            if(cfg->primitive_restart()){
                inputAssembly.primitiveRestartEnable = VK_TRUE;
            } else {
                inputAssembly.primitiveRestartEnable = VK_FALSE;
            }
            break;
        default:
            inputAssembly.primitiveRestartEnable = VK_FALSE;
            break;
        }
        
        pipelineInfo.pInputAssemblyState    = &inputAssembly;
        
        VqPipelineViewportStateCreateInfo   viewportState{};
        VkViewport                          defViewport{};
        if(!opts.viewports.empty()){
            viewportState.viewportCount = (uint32_t) opts.viewports.size();
            viewportState.pViewports    = opts.viewports.data();
        } else if(opts.viewport != VkViewport{}){
            viewportState.viewportCount = 1;
            viewportState.pViewports    = &opts.viewport;
        } else {
            if(!opts.swapchain){
                return errors::pipeline_bad_swapchain();
            }
            defViewport = opts.swapchain->def_viewport();
            viewportState.viewportCount = 1;
            viewportState.pViewports    = &defViewport;
        }

        VkRect2D                            defScissors{};
        if(!opts.scissors.empty()){
            viewportState.scissorCount  = (uint32_t) opts.scissors.size();
            viewportState.pScissors     = opts.scissors.data();
        } else if(opts.scissor != VkRect2D{}){
            viewportState.scissorCount  = 1;
            viewportState.pScissors     = &opts.scissor;
        } else if(opts.swapchain){
            if(!opts.swapchain->valid())
                return errors::pipeline_bad_swapchain();
            defScissors = opts.swapchain -> def_scissor();
            viewportState.scissorCount  = 1;
            viewportState.pScissors     = &defScissors;
        } else {
            defScissors = m_viz -> swapchain_def_scissor();
            viewportState.scissorCount  = 1;
            viewportState.pScissors     = &defScissors;
        }
        pipelineInfo.pViewportState = &viewportState;

        PolygonMode polyMode    = opts.polygon_mode;
        if(polyMode == PolygonMode::Auto)
            polyMode    = cfg->polygons();
        if(polyMode == PolygonMode::Auto)
            polyMode    = PolygonMode::Fill;
        if((polyMode   == PolygonMode::Fill) && (opts.wireframe == Tristate::YES) && cfg->wireframe_permitted()){
            m_status |= S::Wireframe;
        }

        float lineWidth = opts.line_width;
        if(is_nan(lineWidth))
            lineWidth   = cfg->line_width();

        VqPipelineRasterizationStateCreateInfo  rasterizer;
        rasterizer.polygonMode              = (VkPolygonMode) polyMode.value();
        rasterizer.depthClampEnable         = opts.depth_clamp ? VK_TRUE : VK_FALSE;
        rasterizer.rasterizerDiscardEnable  = opts.rasterizer_discard ? VK_TRUE : VK_FALSE;
        rasterizer.lineWidth                = lineWidth;
        rasterizer.cullMode                 = (VkCullModeFlags) cfg->culling().value();
        rasterizer.frontFace                = (VkFrontFace) cfg->front().value();
        rasterizer.depthBiasEnable          = VK_FALSE;
        rasterizer.depthBiasConstantFactor  = 0.0f; // Optional
        rasterizer.depthBiasClamp           = 0.0f; // Optional
        rasterizer.depthBiasSlopeFactor     = 0.0f; // Optional
        pipelineInfo.pRasterizationState    = &rasterizer;

        VqPipelineMultisampleStateCreateInfo multisampling;
        multisampling.sampleShadingEnable = VK_FALSE;
        multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
        multisampling.minSampleShading = 1.0f; // Optional
        multisampling.pSampleMask = nullptr; // Optional
        multisampling.alphaToCoverageEnable = VK_FALSE; // Optional
        multisampling.alphaToOneEnable = VK_FALSE; // Optional

        VkPipelineColorBlendAttachmentState colorBlendAttachment{};
        colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
        colorBlendAttachment.blendEnable = VK_FALSE;
        colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
        colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
        colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD; // Optional
        colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
        colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
        colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD; // Optional
        
        VqPipelineColorBlendStateCreateInfo colorBlending;
        colorBlending.logicOpEnable = VK_FALSE;
        colorBlending.logicOp = VK_LOGIC_OP_COPY; // Optional
        colorBlending.attachmentCount = 1;
        colorBlending.pAttachments = &colorBlendAttachment;
        colorBlending.blendConstants[0] = 0.0f; // Optional
        colorBlending.blendConstants[1] = 0.0f; // Optional
        colorBlending.blendConstants[2] = 0.0f; // Optional
        colorBlending.blendConstants[3] = 0.0f; // Optional
        
        VqPipelineDynamicStateCreateInfo pdynci;
        const auto& dynamicStates = m_layout->dynamic_states();
        if(!dynamicStates.empty()){
            pdynci.dynamicStateCount    = (uint32_t) dynamicStates.size();
            pdynci.pDynamicStates       = dynamicStates.data();
            pipelineInfo.pDynamicState  = &pdynci;
        } else {
            pipelineInfo.pDynamicState  = nullptr; // Optional   
        }

        pipelineInfo.pMultisampleState      = &multisampling;
        pipelineInfo.pDepthStencilState     = nullptr; // Optional
        pipelineInfo.pColorBlendState       = &colorBlending;
        pipelineInfo.layout                 = pLay->pipeline_layout();
        if(opts.render_pass){
            pipelineInfo.renderPass         = opts.render_pass;
        } else {
            pipelineInfo.renderPass         = viz.render_pass();
        }
        pipelineInfo.subpass                = 0;
        pipelineInfo.basePipelineHandle     = VK_NULL_HANDLE; // Optional
        pipelineInfo.basePipelineIndex      = -1; // Optional        
        
        if(m_status(S::Wireframe)){
            pipelineInfo.flags  = VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT;
        }
        
        VkResult res  = vkCreateGraphicsPipelines(viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_pipeline);
        if(res != VK_SUCCESS){
            vizWarning << "ViPipeline: Pipeline create failed.  VkResult " << (int32_t) res;
            return errors::pipeline_cant_create();
        }
            
        if(m_status(S::Wireframe)){
            pipelineInfo.flags  = VK_PIPELINE_CREATE_DERIVATIVE_BIT;
            pipelineInfo.basePipelineHandle = m_pipeline;
            pipelineInfo.basePipelineIndex  = -1;
            rasterizer.polygonMode  = VK_POLYGON_MODE_LINE;
            
            res  = vkCreateGraphicsPipelines(viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_pipeline);
            if(res != VK_SUCCESS){
                vizWarning << "ViPipeline: Pipeline create (for wireframe) failed.  VkResult " << (int32_t) res;
                return errors::pipeline_cant_create();
            }
        }
        
        return {};
    }
    
    void            ViPipeline::_kill()
    {
        if(m_viz && m_viz->device() && m_wireframe){
            vkDestroyPipeline(m_viz->device(), m_wireframe, nullptr);
        }
        if(m_viz && m_viz->device() && m_pipeline){
            vkDestroyPipeline(m_viz->device(), m_pipeline, nullptr);
        }
        
        m_status    = {};
        m_pipeline  = nullptr;
        m_wireframe = nullptr;
        m_layout    = {};
        m_viz       = nullptr;
    }

    bool            ViPipeline::consistent() const
    {
        return m_viz ? (m_viz->device() && m_layout && m_pipeline && (m_wireframe || !m_status(S::Wireframe))) :
            (!m_layout && !m_pipeline && !m_wireframe);
    }
    
    std::error_code ViPipeline::init(ViVisualizer&viz, ViPipelineLayoutCPtr pLay, const ViPipelineOptions& opts)
    {
        if(m_viz){
            if(!consistent()){
                return errors::pipeline_bad_state();
            }
            
            return errors::pipeline_existing();
        }
        
        std::error_code ec  = _init(viz, pLay, opts);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }

    std::error_code     ViPipeline::init(ViVisualizer&viz, const Pipeline*pipe, const ViPipelineOptions& opts)
    {
        if(m_viz){
            if(!consistent()){
                return errors::pipeline_bad_state();
            }
            
            return errors::pipeline_existing();
        }
        if(!pipe){
            return errors::pipeline_null_pipeline();
        }
        
        std::error_code ec  = _init(viz, pipe, opts);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }
    
    void            ViPipeline::kill()
    {
        _kill();
    }

    ViPipelineLayoutCPtr    ViPipeline::layout() const
    {
        return m_layout;
    }

    void ViPipeline::report(Stream& out, const ViPipelineReportOptions& options) const
    {
        out << "Report for ViPipeline[" << hex(this) << "] " << options.message << "\n";
        out << "    VkPipeline (graphics):      [" << hex(m_pipeline) << "]\n";
        out << "    VkPipeline (wireframe):     [" << hex(m_wireframe) << "]\n";
        out << "    Bind Point:                 " << to_string_view(m_binding) << '\n';
        
        if(!m_layout){
            out << "    Pipeline Layout:        [ missing ]\n";
        } else {
            out << "    ViPipelineLayout:           [" << hex(m_layout.ptr()) << "]\n";
            out << "    VkPipelineLayout:           [" << hex(m_layout->pipeline_layout()) << "]\n";
        }


        if(m_layout && options.layout){
            m_layout -> report(out, { .message = "For Pipeline" });
        }
    }

    bool            ViPipeline::valid() const
    {
        return m_viz && m_viz->device() && m_layout && m_pipeline && (m_wireframe || !m_status(S::Wireframe));
    }
}
