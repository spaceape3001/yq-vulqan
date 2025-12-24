////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/ViPipeline.hpp>
#include <yq/container/set_utils.hpp>
#include <yq/container/vector_utils.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/stream/Text.hpp>
#include <yq/trait/has_nan.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/VqUtils.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViLogging.hpp>
#include <yq/tachyon/vulkan/ViPipelineLayout.hpp>
#include <yq/tachyon/vulkan/ViRenderPass.hpp>
#include <yq/tachyon/vulkan/ViSwapchain.hpp>
#include <yq/tachyon/vulkan/VizBase.hpp>

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
    
    ViPipeline::ViPipeline(VizBase&viz, ViPipelineLayoutCPtr pLay, const ViPipelineOptions& opts) : m_viz(viz)
    {
        if(viz.device() && pLay && pLay->valid()){
            std::error_code ec = _init(pLay, opts);
            if(ec != std::error_code()){
                vizWarning << "ViPipeline(): Unable to initialize.  " << ec.message();
                _kill();
            }
        }
    }

    ViPipeline::ViPipeline(VizBase&viz, const Pipeline*pipe, const ViPipelineOptions& opts) : m_viz(viz)
    {
        if(viz.device() && pipe){
            std::error_code ec = _init(pipe, opts);
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
    
    std::error_code ViPipeline::_init(const Pipeline* pipe, const ViPipelineOptions& opts)
    {
        ViPipelineLayoutCPtr        pLay    = m_viz.device(REF).pipeline_layout_create(pipe);
        if(!pLay || !pLay->valid())
            return errors::pipeline_bad_layout();
        return _init( pLay, opts);
    }

    std::error_code ViPipeline::_init(ViPipelineLayoutCPtr pLay, const ViPipelineOptions& opts)
    {
        m_config = pLay->pipeline_config();
        if(!m_config)
            return errors::pipeline_bad_config();
        
        
        m_layout    = pLay;
        m_binding   = (VkPipelineBindPoint) m_config->binding().value();
        m_status    = {};
        m_id        = pLay -> id();
        
        VqGraphicsPipelineCreateInfo pipelineInfo;
        
        //  TODO... subpass support

        const auto&   shaders = pLay->shader_infos();
        if(!shaders.empty()){
            pipelineInfo.stageCount = (uint32_t) shaders.size();
            pipelineInfo.pStages    = shaders.data();
        }
        
        auto shader_mask    = pLay->shader_mask();
        
        static constexpr const VkShaderStageFlagBits kTessellation  = (VkShaderStageFlagBits)(VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT|VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT);
        
        
        pipelineInfo.pVertexInputState = &pLay->vertex_create_info();

        VqPipelineInputAssemblyStateCreateInfo inputAssembly;
        inputAssembly.topology                  = (VkPrimitiveTopology) m_config->topology().value();
        switch(opts.primitive_restart){
        case Tristate::No:
            inputAssembly.primitiveRestartEnable = VK_FALSE;
            break;
        case Tristate::Yes:
            inputAssembly.primitiveRestartEnable = VK_TRUE;
            break;
        case Tristate::Inherit:
            if(m_config->primitive_restart()){
                inputAssembly.primitiveRestartEnable = VK_TRUE;
            } else {
                inputAssembly.primitiveRestartEnable = VK_FALSE;
            }
            break;
        default:
            inputAssembly.primitiveRestartEnable = VK_FALSE;
            break;
        }
        
        VqPipelineTessellationStateCreateInfo  tessellation;
        if(shader_mask & kTessellation){
            if((shader_mask & kTessellation) != kTessellation)
                tachyonWarning << "Pipeline has one tessellation shader, but not the other, are you sure?";
            if(inputAssembly.topology != VK_PRIMITIVE_TOPOLOGY_PATCH_LIST)
                tachyonWarning << "Pipeline has tessellation shaders, but topoology IS NOT the required patch list";
            tessellation.patchControlPoints = m_config->patch_control_points();
            if(tessellation.patchControlPoints < 2)
                tachyonWarning << "Pipeline tessellation needs patch control points";
            pipelineInfo.pTessellationState = &tessellation;
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
            defViewport = m_viz.def_viewport();
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
        } else {
            defScissors = m_viz.def_scissor();
            viewportState.scissorCount  = 1;
            viewportState.pScissors     = &defScissors;
        }
        pipelineInfo.pViewportState = &viewportState;

        PolygonMode polyMode    = opts.polygon_mode;
        if(polyMode == PolygonMode::Auto)
            polyMode    = m_config->polygons();
        if(polyMode == PolygonMode::Auto)
            polyMode    = PolygonMode::Fill;
        #if 0
        if((polyMode   == PolygonMode::Fill) && (opts.wireframe == Tristate::YES) && m_config->wireframe_permitted()){
            m_status |= S::Wireframe;
        }
        #endif
        if(polyMode   == PolygonMode::Fill){
            m_status |= S::Wireframe;
        }

        float lineWidth = opts.line_width;
        if(is_nan(lineWidth))
            lineWidth   = m_config->line_width();

        VqPipelineRasterizationStateCreateInfo  rasterizer;
        rasterizer.polygonMode              = (VkPolygonMode) polyMode.value();
        rasterizer.depthClampEnable         = opts.depth_clamp ? VK_TRUE : VK_FALSE;
        rasterizer.rasterizerDiscardEnable  = opts.rasterizer_discard ? VK_TRUE : VK_FALSE;
        rasterizer.lineWidth                = lineWidth;
        rasterizer.cullMode                 = (VkCullModeFlags) m_config->culling().value();
        rasterizer.frontFace                = (VkFrontFace) m_config->front().value();
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

        switch(m_config->color_blending()){
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
        auto& ds    = m_layout->dynamic_states();
        pdynci.dynamicStateCount    = (uint32_t) ds.size();
        pdynci.pDynamicStates       = ds.data();
        pipelineInfo.pDynamicState  = &pdynci;

        pipelineInfo.pMultisampleState      = &multisampling;
        pipelineInfo.pDepthStencilState     = nullptr; // Optional
        pipelineInfo.layout                 = pLay->pipeline_layout();
        if(opts.render_pass){
            pipelineInfo.renderPass         = opts.render_pass;
        } else {
            pipelineInfo.renderPass         = m_viz.vk_render_pass();
        }
        pipelineInfo.subpass                = 0;
        pipelineInfo.basePipelineHandle     = VK_NULL_HANDLE; // Optional
        pipelineInfo.basePipelineIndex      = -1; // Optional        
        
        if(m_status(S::Wireframe)){
            pipelineInfo.flags  = VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT;
        }
        
        VkResult res  = vkCreateGraphicsPipelines(m_viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_pipeline);
        if(res != VK_SUCCESS){
            vizWarning << "ViPipeline: Pipeline create failed.  VkResult " << (int32_t) res;
            return errors::pipeline_cant_create();
        }
            
        pipelineInfo.flags  = VK_PIPELINE_CREATE_DERIVATIVE_BIT;
        
        if(m_status(S::Wireframe)){
            pipelineInfo.basePipelineHandle = m_pipeline;
            pipelineInfo.basePipelineIndex  = -1;
            rasterizer.polygonMode  = VK_POLYGON_MODE_LINE;
            
            res  = vkCreateGraphicsPipelines(m_viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_wireframe);
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

            ColorBlend   colorBlending   = i.second.define->colorBlend ? *(i.second.define->colorBlend) : m_config->color_blending();
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
                rasterizer.cullMode                 = (VkCullModeFlags) m_config->culling().value();
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
                rasterizer.frontFace                = (VkFrontFace) m_config->front().value();
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

    

            VkResult res  = vkCreateGraphicsPipelines(m_viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &me.pipeline);
            if(res != VK_SUCCESS){
                vizWarning << "ViPipeline: Pipeline create failed.  VkResult " << (int32_t) res;
                return errors::pipeline_cant_create();
            }
            
            if(rasterizer.polygonMode == VK_POLYGON_MODE_FILL){
               rasterizer.polygonMode =  VK_POLYGON_MODE_LINE;
               res  = vkCreateGraphicsPipelines(m_viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &me.wireframe);
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
        if(m_viz.device()){
            for(auto& i : m_variations){
                if(i.second.wireframe)
                    vkDestroyPipeline(m_viz.device(), i.second.wireframe, nullptr);
                if(i.second.pipeline)
                    vkDestroyPipeline(m_viz.device(), i.second.pipeline, nullptr);
            }
            m_variations.clear();
        }
    
        if(m_viz.device() && m_wireframe){
            vkDestroyPipeline(m_viz.device(), m_wireframe, nullptr);
        }
        if(m_viz.device() && m_pipeline){
            vkDestroyPipeline(m_viz.device(), m_pipeline, nullptr);
        }
        
        m_status    = {};
        m_pipeline  = nullptr;
        m_wireframe = nullptr;
        m_layout    = {};
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
        return m_viz.device() && m_layout && m_pipeline && (m_wireframe || !m_status(S::Wireframe));
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
