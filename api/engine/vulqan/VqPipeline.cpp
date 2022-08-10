////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VqException.hpp"
#include <engine/Visualizer.hpp>
#include "VqLogging.hpp"
#include "VqPipeline.hpp"
#include "VqStructs.hpp"

#include <basic/Logging.hpp>
#include <engine/Viewer.hpp>
#include <engine/render/PipelineConfig.hpp>
#include <engine/render/Pipeline.hpp>
#include <engine/render/StdPushConstant.hpp>
#include <math/Size2.hpp>
#include <math/Rectangle2.hpp>

namespace yq {
    namespace engine {
        VqPipeline::VqPipeline(Visualizer& viz, const PipelineConfig& cfg)
        {
            m_device    = viz.m_device;
            try {
            
                std::vector<VkPipelineShaderStageCreateInfo>    stages;
                m_shaderMask        = 0;
                for(auto& s : cfg.shaders){
                    ViShaderCPtr    vs  = viz.shader(s);
                    if(!vs)
                        continue;
                        
                    VqPipelineShaderStageCreateInfo stage;
                    stage.stage     = vs->mask;
                    stage.pName     = "main";
                    stage.module    = vs->shader;
                    stages.push_back(stage);

                    m_shaderMask |= vs->mask;
                }
                
                VqPipelineVertexInputStateCreateInfo    vertexInfo;
                
                std::vector<VkVertexInputAttributeDescription>  attrs;
                std::vector<VkVertexInputBindingDescription>    vbos;
                std::vector<VkDescriptorSetLayoutBinding>       ubos;
                
                for(uint32_t i=0;i<cfg.vbos.size();++i){
                    auto& v = cfg.vbos[i];
                    VkVertexInputBindingDescription b;
                    b.binding   = i;
                    b.stride    = v.stride;
                    b.inputRate = (VkVertexInputRate) v.inputRate.value();
                    vbos.push_back(b);
                    
                    for(auto& va : v.attrs){
                        VkVertexInputAttributeDescription   a;
                        a.binding       = i;
                        a.location      = va.location;
                        a.offset        = va.offset;
                        a.format        = (VkFormat) va.format.value();
                        attrs.push_back(a);
                    }
                }

                if(!cfg.ubos.empty()){
                    for(uint32_t    i   = 0;i<cfg.ubos.size();++i){
                        auto& u = cfg.ubos[i];
                        VkDescriptorSetLayoutBinding a;
                        a.binding           = i;
                        a.descriptorCount   = u.count;
                        a.descriptorType    = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
                        if(u.stage)
                            a.stageFlags    = u.stage;
                        else
                            a.stageFlags    = m_shaderMask;
                        ubos.push_back(a);
                    }
                    VqDescriptorSetLayoutCreateInfo layoutInfo;
                    layoutInfo.bindingCount = ubos.size();
                    layoutInfo.pBindings    = ubos.data();
                    if(vkCreateDescriptorSetLayout(viz.m_device, &layoutInfo, nullptr, &m_descriptorSetLayout) != VK_SUCCESS)
                        throw VqException("Unable to create a descriptor set layout.");
                }
                    


                vertexInfo.vertexBindingDescriptionCount    = (uint32_t) vbos.size();
                vertexInfo.pVertexBindingDescriptions       = vbos.data();
                vertexInfo.vertexAttributeDescriptionCount  = (uint32_t) attrs.size();
                vertexInfo.pVertexAttributeDescriptions     = attrs.data();
                
                VqPipelineInputAssemblyStateCreateInfo  inputAssembly;
                inputAssembly.topology                  = (VkPrimitiveTopology) cfg.topology.value();
                inputAssembly.primitiveRestartEnable    = VK_FALSE;
                
                VkViewport viewport = viz.m_swapchain->def_viewport();

                VkRect2D scissor = viz.m_swapchain->def_scissor();
                
                VqPipelineViewportStateCreateInfo   viewportState{};
                viewportState.viewportCount = 1;
                viewportState.pViewports = &viewport;
                viewportState.scissorCount = 1;
                viewportState.pScissors = &scissor;
                
                VqPipelineRasterizationStateCreateInfo  rasterizer;
                rasterizer.depthClampEnable = VK_FALSE;
                rasterizer.rasterizerDiscardEnable = VK_FALSE;
                rasterizer.polygonMode = (VkPolygonMode) cfg.polymode.value();
                rasterizer.lineWidth = 1.0f;
                rasterizer.cullMode = (VkCullModeFlags) cfg.culling.value();
                rasterizer.frontFace = (VkFrontFace) cfg.front.value();
                rasterizer.depthBiasEnable = VK_FALSE;
                rasterizer.depthBiasConstantFactor = 0.0f; // Optional
                rasterizer.depthBiasClamp = 0.0f; // Optional
                rasterizer.depthBiasSlopeFactor = 0.0f; // Optional

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
                

                VkPushConstantRange push{};
                if(cfg.push.type != PushConfigType::None){
                    push.offset     = 0;
                    switch(cfg.push.type){
                    case PushConfigType::Full:
                    case PushConfigType::View:
                        push.size   = sizeof(StdPushConstant);
                        break;
                    case PushConfigType::Custom:
                        push.size   = cfg.push.size;
                        break;
                    default:
                        break;
                    }
                }
                
                VqPipelineLayoutCreateInfo pipelineLayoutInfo{};
                pipelineLayoutInfo.setLayoutCount = 0; // Optional
                pipelineLayoutInfo.pSetLayouts = nullptr; // Optional
                if(push.size != 0){
                    if(cfg.push.shaders)
                        push.stageFlags = cfg.push.shaders;
                    else
                        push.stageFlags = m_shaderMask;
                    pipelineLayoutInfo.pushConstantRangeCount = 1;
                    pipelineLayoutInfo.pPushConstantRanges = &push;
                } else {
                    pipelineLayoutInfo.pushConstantRangeCount = 0; // Optional
                    pipelineLayoutInfo.pPushConstantRanges = nullptr; // Optional
                }
                if(m_descriptorSetLayout){
                    pipelineLayoutInfo.setLayoutCount   = 1;
                    pipelineLayoutInfo.pSetLayouts      = &m_descriptorSetLayout;
                }


                if (vkCreatePipelineLayout(viz.m_device, &pipelineLayoutInfo, nullptr, &m_layout) != VK_SUCCESS) 
                    throw VqException("Failed to create pipeline layout!");

                VqGraphicsPipelineCreateInfo pipelineInfo;
                pipelineInfo.stageCount     = stages.size();
                if(pipelineInfo.stageCount)
                   pipelineInfo.pStages     = stages.data();
                
                pipelineInfo.pVertexInputState = &vertexInfo;
                pipelineInfo.pInputAssemblyState = &inputAssembly;
                pipelineInfo.pViewportState = &viewportState;
                pipelineInfo.pRasterizationState = &rasterizer;
                pipelineInfo.pMultisampleState = &multisampling;
                pipelineInfo.pDepthStencilState = nullptr; // Optional
                pipelineInfo.pColorBlendState = &colorBlending;
                pipelineInfo.pDynamicState = nullptr; // Optional   
                pipelineInfo.layout = m_layout;
                pipelineInfo.renderPass = viz.m_renderPass;
                pipelineInfo.subpass = 0;             
                pipelineInfo.basePipelineHandle = VK_NULL_HANDLE; // Optional
                pipelineInfo.basePipelineIndex = -1; // Optional        
                
                if(cfg.polymode == PolygonMode::Fill)
                    pipelineInfo.flags  = VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT;
                if (vkCreateGraphicsPipelines(viz.m_device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_pipeline) != VK_SUCCESS) 
                    throw VqException("Failed to create graphics pipeline!");
                
                    // if it's a fill polygon (typical), create a derivative wireframe pipeline
                if(cfg.polymode == PolygonMode::Fill){
                    pipelineInfo.flags  = VK_PIPELINE_CREATE_DERIVATIVE_BIT;
                    pipelineInfo.basePipelineHandle = m_pipeline;
                    pipelineInfo.basePipelineIndex  = -1;
                    rasterizer.polygonMode  = VK_POLYGON_MODE_LINE;
                    
                    if (vkCreateGraphicsPipelines(viz.m_device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_wireframe) != VK_SUCCESS)
                        throw VqException("Failed to create wireframe pipeline!");
                }
            }
            catch(VqException& ex)
            {
                vqCritical << ex.what();
                dtor();
                throw;      // rethrow it.
            }
        }

        
        VqPipeline::~VqPipeline()
        {
            dtor();
        }
        
        void    VqPipeline::dtor()
        {
            if(m_device){
                if(m_descriptorSetLayout){
                    vkDestroyDescriptorSetLayout(m_device, m_descriptorSetLayout, nullptr);
                    m_descriptorSetLayout   = nullptr;
                }
                if(m_wireframe){
                    vkDestroyPipeline(m_device, m_wireframe, nullptr);
                    m_wireframe = nullptr;
                }
                if(m_pipeline){
                    vkDestroyPipeline(m_device, m_pipeline, nullptr);
                    m_pipeline  = nullptr;
                }
                if(m_layout){
                    vkDestroyPipelineLayout(m_device, m_layout, nullptr);
                    m_layout    = nullptr;
                }
            }
        }

    }
}
