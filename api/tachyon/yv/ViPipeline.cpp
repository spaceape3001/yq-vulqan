////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViPipeline.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/stream/Text.hpp>
#include <yq/trait/has_nan.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yv/VqStructs.hpp>
#include <yv/VqUtils.hpp>
#include <yv/ViLogging.hpp>
#include <yv/ViPipelineLayout.hpp>
#include <yv/ViRenderPass.hpp>
#include <yv/ViSwapchain.hpp>
#include <yv/ViVisualizer.hpp>

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
        if(!pLay || !pLay->valid())
            return errors::pipeline_bad_layout();
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
        
        //  TODO... subpass support

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
        #if 0
        if((polyMode   == PolygonMode::Fill) && (opts.wireframe == Tristate::YES) && cfg->wireframe_permitted()){
            m_status |= S::Wireframe;
        }
        #endif
        if(polyMode   == PolygonMode::Fill){
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

        static const VkPipelineColorBlendAttachmentState    colorBlendAttachment_disabled = {
            .blendEnable                = VK_FALSE,
            .srcColorBlendFactor        = VK_BLEND_FACTOR_ONE,
            .dstColorBlendFactor        = VK_BLEND_FACTOR_ZERO,
            .colorBlendOp               = VK_BLEND_OP_ADD,
            .srcAlphaBlendFactor        = VK_BLEND_FACTOR_ONE,
            .dstAlphaBlendFactor        = VK_BLEND_FACTOR_ZERO,
            .alphaBlendOp               = VK_BLEND_OP_ADD,
            .colorWriteMask             = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT
        };

        static const VkPipelineColorBlendStateCreateInfo    colorBlend_disabled = {
            .sType                      = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
            .pNext                      = nullptr,
            .flags                      = 0,
            .logicOpEnable              = VK_FALSE,
            .logicOp                    = VK_LOGIC_OP_COPY,
            .attachmentCount            = 1,
            .pAttachments               = &colorBlendAttachment_disabled,
            .blendConstants             = { 0., 0., 0., 0. }
        };
        
        static const VkPipelineColorBlendAttachmentState    colorBlendAttachment_additive = {
            .blendEnable                = VK_TRUE,
            .srcColorBlendFactor        = VK_BLEND_FACTOR_SRC_ALPHA,
            .dstColorBlendFactor        = VK_BLEND_FACTOR_ONE,
            .colorBlendOp               = VK_BLEND_OP_ADD,
            .srcAlphaBlendFactor        = VK_BLEND_FACTOR_ONE,
            .dstAlphaBlendFactor        = VK_BLEND_FACTOR_ZERO,
            .alphaBlendOp               = VK_BLEND_OP_ADD,
            .colorWriteMask             = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT
        };

        static const VkPipelineColorBlendStateCreateInfo    colorBlend_additive = {
            .sType                      = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
            .pNext                      = nullptr,
            .flags                      = 0,
            .logicOpEnable              = VK_FALSE,
            .logicOp                    = VK_LOGIC_OP_COPY,
            .attachmentCount            = 1,
            .pAttachments               = &colorBlendAttachment_additive,
            .blendConstants             = { 0., 0., 0., 0. }
        };

        static const VkPipelineColorBlendAttachmentState    colorBlendAttachment_alphaBlend = {
            .blendEnable                = VK_TRUE,
            .srcColorBlendFactor        = VK_BLEND_FACTOR_SRC_ALPHA,
            .dstColorBlendFactor        = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
            .colorBlendOp               = VK_BLEND_OP_ADD,
            .srcAlphaBlendFactor        = VK_BLEND_FACTOR_ONE,
            .dstAlphaBlendFactor        = VK_BLEND_FACTOR_ZERO,
            .alphaBlendOp               = VK_BLEND_OP_ADD,
            .colorWriteMask             = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT
        };

        static const VkPipelineColorBlendStateCreateInfo    colorBlend_alphaBlend = {
            .sType                      = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
            .pNext                      = nullptr,
            .flags                      = 0,
            .logicOpEnable              = VK_FALSE,
            .logicOp                    = VK_LOGIC_OP_COPY,
            .attachmentCount            = 1,
            .pAttachments               = &colorBlendAttachment_alphaBlend,
            .blendConstants             = { 0., 0., 0., 0. }
        };

        switch(cfg->color_blending()){
        case ColorBlend::Additive:
            pipelineInfo.pColorBlendState   = &colorBlend_additive;
            break;
        case ColorBlend::AlphaBlend:
            pipelineInfo.pColorBlendState   = &colorBlend_alphaBlend;
            break;
        case ColorBlend::Disabled:
        default:
            pipelineInfo.pColorBlendState   = &colorBlend_disabled;
            break;
        }

        VqPipelineDynamicStateCreateInfo pdynci;
        std::vector<VkDynamicState> dynamicStates = m_layout->dynamic_states();
        dynamicStates.push_back(VK_DYNAMIC_STATE_VIEWPORT);
        
        pdynci.dynamicStateCount    = (uint32_t) dynamicStates.size();
        pdynci.pDynamicStates       = dynamicStates.data();
        pipelineInfo.pDynamicState  = &pdynci;

        pipelineInfo.pMultisampleState      = &multisampling;
        pipelineInfo.pDepthStencilState     = nullptr; // Optional
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
            
        pipelineInfo.flags  = VK_PIPELINE_CREATE_DERIVATIVE_BIT;
        
        if(m_status(S::Wireframe)){
            pipelineInfo.basePipelineHandle = m_pipeline;
            pipelineInfo.basePipelineIndex  = -1;
            rasterizer.polygonMode  = VK_POLYGON_MODE_LINE;
            
            res  = vkCreateGraphicsPipelines(viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_wireframe);
            if(res != VK_SUCCESS){
                vizWarning << "ViPipeline: Pipeline create (for wireframe) failed.  VkResult " << (int32_t) res;
                return errors::pipeline_cant_create();
            }
        }
        
        for(auto& i : m_layout->m_variations){
            auto& me = m_variations[i.first];
            pipelineInfo.basePipelineHandle = m_pipeline;
            if(!i.second.shaders.empty()){
                pipelineInfo.stageCount = (uint32_t) i.second.shaderInfo.size();
                pipelineInfo.pStages    = i.second.shaderInfo.data();
            }

            ColorBlend   colorBlending   = i.second.define->colorBlend ? *(i.second.define->colorBlend) : cfg->color_blending();
            switch(colorBlending){
            case ColorBlend::Additive:
                pipelineInfo.pColorBlendState   = &colorBlend_additive;
                break;
            case ColorBlend::AlphaBlend:
                pipelineInfo.pColorBlendState   = &colorBlend_alphaBlend;
                break;
            case ColorBlend::Disabled:
            default:
                pipelineInfo.pColorBlendState   = &colorBlend_disabled;
                break;
            }
            
            if(i.second.define->cullMode){
                rasterizer.cullMode                 = (VkCullModeFlags) (*(i.second.define->cullMode)).value();
            } else {
                rasterizer.cullMode                 = (VkCullModeFlags) cfg->culling().value();
            }

            if(i.second.define->lineWidth){
                rasterizer.lineWidth                = *(i.second.define->lineWidth);
            } else if(i.second.define->lineWidthMultiplier){
                rasterizer.lineWidth                = lineWidth * *(i.second.define->lineWidthMultiplier);
            } else {
                rasterizer.lineWidth                = lineWidth;
            }
            
            if(i.second.define->frontFace){
                rasterizer.frontFace                = (VkFrontFace) (*(i.second.define->frontFace)).value();
            } else {
                rasterizer.frontFace                = (VkFrontFace) cfg->front().value();
            }

            if(i.second.define->polygonMode){
                PolygonMode pm  = *(i.second.define->polygonMode);
                if(pm == PolygonMode::Auto){
                    rasterizer.polygonMode          = (VkPolygonMode) polyMode.value();
                } else {
                    rasterizer.polygonMode          = (VkPolygonMode) pm.value();
                }
            } else {
                rasterizer.polygonMode              = (VkPolygonMode) polyMode.value();
            }

            VkResult res  = vkCreateGraphicsPipelines(viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &me.pipeline);
            if(res != VK_SUCCESS){
                vizWarning << "ViPipeline: Pipeline create failed.  VkResult " << (int32_t) res;
                return errors::pipeline_cant_create();
            }
            
            if(rasterizer.polygonMode == VK_POLYGON_MODE_FILL){
               rasterizer.polygonMode =  VK_POLYGON_MODE_LINE;
               res  = vkCreateGraphicsPipelines(viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &me.wireframe);
                if(res != VK_SUCCESS){
                    vizWarning << "ViPipeline: Pipeline create failed.  VkResult " << (int32_t) res;
                    return errors::pipeline_cant_create();
                }
            }
        }
        
        
        return {};
    }
    
    void            ViPipeline::_kill()
    {
        if(m_viz && m_viz->device()){
            for(auto& i : m_variations){
                if(i.second.wireframe)
                    vkDestroyPipeline(m_viz->device(), i.second.wireframe, nullptr);
                if(i.second.pipeline)
                    vkDestroyPipeline(m_viz->device(), i.second.pipeline, nullptr);
            }
            m_variations.clear();
        }
    
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

    VkPipeline          ViPipeline::pipeline(Pipeline::Variation v) const
    {
        if(v == Pipeline::Variation::Default)
            return m_pipeline;
        if(v == Pipeline::Variation::Invalid)
            return nullptr;
        auto i = m_variations.find(v);
        if(i != m_variations.end())
            return i->second.pipeline;
        return nullptr;
    }

    void ViPipeline::report(Stream& out, const ViPipelineReportOptions& options) const
    {
        out << "Report for ViPipeline[" << hex(this) << "] " << options.message << "\n";
        out << "    VkPipeline (graphics):      [" << hex(m_pipeline) << "]\n";
        out << "    VkPipeline (wireframe):     [" << hex(m_wireframe) << "]\n";
        out << "    Bind Point:                 " << to_string_view(m_binding) << '\n';
        
        for(auto& i : m_variations){
            out << "    VkPipeline (graphics):      [" << hex(i.second.pipeline) << "] {" << (int) i.first << "}\n";
            out << "    VkPipeline (wireframe):     [" << hex(i.second.wireframe) << "] {" << (int) i.first << "}\n";
        }
        
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

    void            ViPipeline::report(const char* cat, LogPriority pri, const ViPipelineReportOptions& options) const
    {
        std::string     text;
        {
        
            stream::Text  out(text);
            report(out, options);
        }
        log_category(cat).getStream(log4cpp_priority(pri)) << text;
    }

    bool            ViPipeline::valid() const
    {
        return m_viz && m_viz->device() && m_layout && m_pipeline && (m_wireframe || !m_status(S::Wireframe));
    }

    VkPipeline          ViPipeline::wireframe(Pipeline::Variation v) const
    {
        if(v == Pipeline::Variation::Default)
            return m_wireframe;
        if(v == Pipeline::Variation::Invalid)
            return nullptr;
        auto i = m_variations.find(v);
        if(i != m_variations.end())
            return i->second.wireframe;
        return nullptr;
    }
}
