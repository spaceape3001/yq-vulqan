////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


/*
    Note, development of any engine in vulkan requires examples/guides.  
        
        1.  https://vulkan-tutorial.com
        2.  https://vkguide.dev
        3.  https://www.saschawillems.de
        
    While this is an independent creation, my own intepretation of the Vulkan,
    there may be similarities to the above.
*/

#include "Visualizer.hxx"
#include "Visualizer.hpp"

#include <yq-toolbox/errors.hpp>
#include <yq-toolbox/basic/AutoReset.hpp>
#include <yq-toolbox/basic/ErrorDB.hpp>
#include <yq-toolbox/container/BasicBuffer.hpp>
#include <yq-toolbox/container/initlist_utils.hpp>
#include <yq-toolbox/color/RGBA.hpp>

#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/image/Image.hpp>
#include <yq-vulqan/image/ImageViewInfo.hpp>
#include <yq-vulqan/memory/Buffer.hpp>
#include <yq-vulqan/pipeline/Pipeline.hpp>
#include <yq-vulqan/pipeline/PushData.hpp>
#include <yq-vulqan/render/Render3D.hpp>
#include <yq-vulqan/scene/Perspective.hpp>
#include <yq-vulqan/scene/Scene.hpp>
#include <yq-vulqan/shader/Shader.hpp>
#include <yq-vulqan/texture/Texture.hpp>
#include <yq-vulqan/viewer/ViewerCreateInfo.hpp>
#include <yq-vulqan/v/VqApp.hpp>
#include <yq-vulqan/v/VqUtils.hpp>
#include <yq-vulqan/viz/ViBuffer.hpp>
#include <yq-vulqan/viz/ViBufferObject.hpp>
#include <yq-vulqan/viz/ViContext.hpp>
#include <yq-vulqan/viz/ViImage.hpp>
#include <yq-vulqan/viz/ViManager.hpp>
#include <yq-vulqan/viz/ViQueueManager.hpp>
#include <yq-vulqan/viz/ViRendered.hpp>
#include <yq-vulqan/viz/ViSampler.hpp>
#include <yq-vulqan/viz/ViShader.hpp>
#include <yq-vulqan/viz/ViSwapchain.hpp>
#include <yq-vulqan/viz/ViTexture.hpp>



#include <GLFW/glfw3.h>

#define LOCK        tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, false);
#define WLOCK       tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, true);

namespace yq::tachyon {



    ////////////////////////////////////////////////////////////////////////////////
    //  ViFrame0
    ////////////////////////////////////////////////////////////////////////////////

    namespace {
        uint32_t    nextFrameId()
        {
            static std::atomic<uint32_t>    s_ret{0};
            return ++s_ret;
        }
    }

    ViFrame0::ViFrame0(Visualizer&viz) : m_viz(viz), m_id(nextFrameId())
    {
        try {
            _ctor();
        }
        catch(std::error_code ec)
        {
            _dtor();
            throw;
        }
    }
    
    ViFrame0::~ViFrame0()
    {
        _dtor();
    }

    void    ViFrame0::_ctor()
    {
        if(m_renderFinished)
            throw create_error<"Frame already initialized">();
            
        m_commandPool                   = m_viz.command_pool();
        VqCommandBufferAllocateInfo allocInfo;
        allocInfo.commandPool           = m_commandPool;
        allocInfo.level                 = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandBufferCount    = 1;
        if (vkAllocateCommandBuffers(m_viz.device(), &allocInfo, &m_commandBuffer) != VK_SUCCESS) 
            throw create_error<"Failed to allocate command buffers">();

        VqFenceCreateInfo   fci;
        fci.flags = VK_FENCE_CREATE_SIGNALED_BIT;
        if(vkCreateFence(m_viz.device(), &fci, nullptr,  &m_fence) != VK_SUCCESS)
            throw create_error<"Unable to create fence">();

        VqSemaphoreCreateInfo   info;
        if(vkCreateSemaphore(m_viz.device(), &info, nullptr, &m_imageAvailable) != VK_SUCCESS)
            throw create_error<"Unable to create semaphore!">();
        if(vkCreateSemaphore(m_viz.device(), &info, nullptr, &m_renderFinished) != VK_SUCCESS)
            throw create_error<"Unable to create semaphore!">();
            
        m_rendereds     = std::make_unique<ViRenderedManager>(m_viz, ViRenderedOptions{});
    }
    
    void                ViFrame0::_dtor()
    {
        m_rendereds         = {};

        if(m_commandBuffer && m_commandPool){
            vkFreeCommandBuffers(m_viz.device(), m_commandPool, 1, &m_commandBuffer);
            m_commandBuffer   = nullptr;
        }
        
        if(m_imageAvailable){
            vkDestroySemaphore(m_viz.device(), m_imageAvailable, nullptr);
            m_imageAvailable  = nullptr;
        }
        
        if(m_renderFinished){
            vkDestroySemaphore(m_viz.device(), m_renderFinished, nullptr);
            m_renderFinished  = nullptr;
        }
        
        if(m_fence){
            vkDestroyFence(m_viz.device(), m_fence, nullptr);
            m_fence   = nullptr;
        }
    }

    ViRenderedPtr      ViFrame0::create(const RenderedCPtr&obj)
    {
        if(!m_rendereds)
            return {};
        return m_rendereds -> create(obj);
        //return create(obj, *obj.pipeline());
    }
    
    //ViRenderedCPtr      ViFrame0::create(const RenderedCPtr& obj, const Pipeline& pipe)
    //{
        //if(m_rendereds){
            //m_rendereds -> create(obj, pipe);
        //}
    //}
    
    #if 0
    ViRendered0*         ViFrame0::create(const RenderedCPtr&obj, const PipelineCPtr& pipe)
    {
        {
            LOCK
            auto eq = m_rendereds.equal_range(obj.id());
            for(auto i = eq.first; i != eq.second; ++i){
                if(i->second->m_pipe.m_id == pipe.id())
                    return i->second;
            }
        }

        const ViPipeline0*   vp   = m_viz.create(pipe);
        if(!vp)
            return nullptr;
        
        ViRendered0* p   = new ViRendered0(m_viz, *vp, obj);
        ViRendered0* ret = nullptr;
        
        {
            WLOCK
            auto eq = m_rendereds.equal_range(obj.id());
            for(auto i = eq.first; i != eq.second; ++i){
                if(i->second->m_pipe.m_id == pipe.id()){
                    ret = i->second;
                    break;
                }
            }
            
            if(!ret){
                m_rendereds.insert({ obj.id(), p });
                return p;
            }
        }
        
        delete p;
        return ret;
    }
    
    const ViRendered0*   ViFrame0::lookup(const Rendered&ren, const Pipeline& pipe) const
    {
        {
            LOCK
            auto eq = m_rendereds.equal_range(ren.id());
            for(auto i = eq.first; i != eq.second; ++i){
                if(i->second->m_pipe.m_id == pipe.id())
                    return i->second;
            }
        }
        return nullptr;
    }
    #endif

    ////////////////////////////////////////////////////////////////////////////////
    //  ViPipeline0
    ////////////////////////////////////////////////////////////////////////////////
#if 0
    ViPipeline0::ViPipeline0(Visualizer&viz, const Pipeline&p) : m_viz(viz), m_id(p.id()), 
        m_config(p.config()), m_cfg(*m_config)
    {
    }
    
    ViPipeline0::~ViPipeline0()
    {
        _dtor();
    }
    
    std::error_code         ViPipeline0::_ctor()
    {
        try {
            std::vector<VkPipelineShaderStageCreateInfo>    stages;
            m_shaders           = 0;
            for(auto& s : m_cfg.shaders){
                Ref<const Shader>   sh  = Shader::decode(s);
                if(!sh)
                    continue;
                
                ViShaderCPtr    xvs = m_viz.shader_create(*sh);
                if(!xvs)
                    continue;
                if(!xvs->valid())
                    continue;
                
                VqPipelineShaderStageCreateInfo stage;
                stage.stage     = xvs->mask();
                stage.pName     = "main";
                stage.module    = xvs->shader_module();
                stages.push_back(stage);

                m_shaders      |= xvs->mask();
            }
        
            VqPipelineVertexInputStateCreateInfo    vertexInfo;
            VqPipelineLayoutCreateInfo              pipelineLayoutInfo;
            
            std::vector<VkVertexInputAttributeDescription>  attrs;
            std::vector<VkVertexInputBindingDescription>    vbos;
            std::vector<VkDescriptorSetLayoutBinding>       desc;
            
            for(uint32_t i=0;i<m_cfg.vbos.size();++i){
                auto& v = m_cfg.vbos[i];
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

            size_t  ds2 = m_cfg.ubos.size() + m_cfg.texs.size();

            if(ds2){
                for(uint32_t    i   = 0;i<m_cfg.ubos.size();++i){
                    auto& u = m_cfg.ubos[i];
                    VkDescriptorSetLayoutBinding a{};
                    a.binding           = i;
                    a.descriptorCount   = 1;
                    a.descriptorType    = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
                    if(u.shaders){
                        a.stageFlags    = u.shaders;
                    } else
                        a.stageFlags    = m_shaders;
                    desc.push_back(a);
                }
                
                uint32_t        tbase   = m_cfg.ubos.size();
                
                for(uint32_t  i=0;i<m_cfg.texs.size();++i){
                    auto& u = m_cfg.texs[i];
                    VkDescriptorSetLayoutBinding a{};
                    a.binding           = i+tbase;
                    a.descriptorCount   = 1;
                    a.descriptorType    = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
                    if(u.shaders){
                        a.stageFlags    = u.shaders;
                    } else
                        a.stageFlags    = m_shaders;
                    desc.push_back(a);
                }
                
                VqDescriptorSetLayoutCreateInfo layoutInfo;
                layoutInfo.bindingCount = desc.size();
                layoutInfo.pBindings    = desc.data();
                if(vkCreateDescriptorSetLayout(m_viz.device(), &layoutInfo, nullptr, &m_descriptors) != VK_SUCCESS)
                    throw create_error<"Unable to create a descriptor set layout">();
                pipelineLayoutInfo.setLayoutCount   = 1;
                pipelineLayoutInfo.pSetLayouts      = &m_descriptors;
            }
                
            vertexInfo.vertexBindingDescriptionCount    = (uint32_t) vbos.size();
            vertexInfo.pVertexBindingDescriptions       = vbos.data();
            vertexInfo.vertexAttributeDescriptionCount  = (uint32_t) attrs.size();
            vertexInfo.pVertexAttributeDescriptions     = attrs.data();
            
            VkPushConstantRange push{};
            if(m_cfg.push.type != PushConfigType::None){
                push.offset     = 0;
                switch(m_cfg.push.type){
                case PushConfigType::Full:
                case PushConfigType::View:
                    push.size   = sizeof(StdPushData);
                    break;
                case PushConfigType::Custom:
                    push.size   = m_cfg.push.size;
                    break;
                default:
                    break;
                }
            }
            
            pipelineLayoutInfo.setLayoutCount = 0; // Optional
            pipelineLayoutInfo.pSetLayouts = nullptr; // Optional
            if(push.size != 0){
                if(m_cfg.push.shaders)
                    push.stageFlags = m_cfg.push.shaders;
                else
                    push.stageFlags = m_shaders;
                pipelineLayoutInfo.pushConstantRangeCount = 1;
                pipelineLayoutInfo.pPushConstantRanges = &push;
            } else {
                pipelineLayoutInfo.pushConstantRangeCount = 0; // Optional
                pipelineLayoutInfo.pPushConstantRanges = nullptr; // Optional
            }
            if(m_descriptors){
                pipelineLayoutInfo.setLayoutCount   = 1;
                pipelineLayoutInfo.pSetLayouts      = &m_descriptors;
            }

            if (vkCreatePipelineLayout(m_viz.device(), &pipelineLayoutInfo, nullptr, &m_layout) != VK_SUCCESS) 
                throw create_error<"Failed to create pipeline layout">();

            VqGraphicsPipelineCreateInfo pipelineInfo;
            pipelineInfo.stageCount     = stages.size();
            if(pipelineInfo.stageCount)
               pipelineInfo.pStages     = stages.data();

            VqPipelineInputAssemblyStateCreateInfo  inputAssembly;
            inputAssembly.topology                  = (VkPrimitiveTopology) m_cfg.topology.value();
            inputAssembly.primitiveRestartEnable    = VK_FALSE;
            

            VkViewport viewport = m_viz.swapchain_def_viewport();

            VkRect2D scissor = m_viz.swapchain_def_scissor();
            
            VqPipelineViewportStateCreateInfo   viewportState{};
            viewportState.viewportCount = 1;
            viewportState.pViewports = &viewport;
            viewportState.scissorCount = 1;
            viewportState.pScissors = &scissor;
            
            VqPipelineRasterizationStateCreateInfo  rasterizer;
            rasterizer.depthClampEnable = VK_FALSE;
            rasterizer.rasterizerDiscardEnable = VK_FALSE;
            rasterizer.polygonMode = (VkPolygonMode) m_cfg.polymode.value();
            rasterizer.lineWidth = 1.0f;
            rasterizer.cullMode = (VkCullModeFlags) m_cfg.culling.value();
            rasterizer.frontFace = (VkFrontFace) m_cfg.front.value();
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
            
                        
            pipelineInfo.pVertexInputState      = &vertexInfo;
            pipelineInfo.pInputAssemblyState    = &inputAssembly;
            pipelineInfo.pViewportState         = &viewportState;
            pipelineInfo.pRasterizationState    = &rasterizer;
            pipelineInfo.pMultisampleState      = &multisampling;
            pipelineInfo.pDepthStencilState     = nullptr; // Optional
            pipelineInfo.pColorBlendState       = &colorBlending;
            pipelineInfo.pDynamicState          = nullptr; // Optional   
            pipelineInfo.layout                 = m_layout;
            pipelineInfo.renderPass             = m_viz.render_pass();
            pipelineInfo.subpass                = 0;             
            pipelineInfo.basePipelineHandle     = VK_NULL_HANDLE; // Optional
            pipelineInfo.basePipelineIndex      = -1; // Optional        
            
            if(m_cfg.polymode == PolygonMode::Fill)
                pipelineInfo.flags  = VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT;
            if (vkCreateGraphicsPipelines(m_viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_pipeline) != VK_SUCCESS) 
                throw create_error<"Failed to create graphics pipeline!">();
            
                // if it's a fill polygon (typical), create a derivative wireframe pipeline
            if(m_cfg.polymode == PolygonMode::Fill){
                pipelineInfo.flags  = VK_PIPELINE_CREATE_DERIVATIVE_BIT;
                pipelineInfo.basePipelineHandle = m_pipeline;
                pipelineInfo.basePipelineIndex  = -1;
                rasterizer.polygonMode  = VK_POLYGON_MODE_LINE;
                
                if (vkCreateGraphicsPipelines(m_viz.device(), VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_wireframe) != VK_SUCCESS)
                    throw create_error<"Failed to create wireframe pipeline!">();
            }
            
            m_binding       = (VkPipelineBindPoint) m_cfg.binding.value();
            
            
            if(!m_cfg.vbos.empty()){
                for(auto& vb : m_cfg.vbos){
                    ViBufferObject        bo;
                    bo.update(m_viz, vb, nullptr);
                    m_vbos.push_back(bo);
                }
            }
            
            if(!m_cfg.ibos.empty()){
                for(auto & ib : m_cfg.ibos){
                    ViBufferObject        bo;
                    bo.update(m_viz, ib, nullptr);
                    m_ibos.push_back(bo);
                }
            }

            if(!m_cfg.ubos.empty()){
                for(auto & ub : m_cfg.ubos){
                    ViBufferObject        bo;
                    bo.update(m_viz, ub, nullptr);
                    m_ubos.push_back(bo);
                }
            }
            
            if(!m_cfg.texs.empty()){
                for(auto& tb : m_cfg.texs){
                    ViTO        to;
                    to.update(m_viz, tb, nullptr);
                    m_texs.push_back(to);
                }
            }
                
            return std::error_code();
        }
        catch(std::error_code ec)
        {
            _dtor();
            return ec;
        }
    }
    
    void                    ViPipeline0::_dtor()
    {
        if(m_descriptors){
            vkDestroyDescriptorSetLayout(m_viz.device(), m_descriptors, nullptr);
            m_descriptors   = nullptr;
        }
        if(m_wireframe){
            vkDestroyPipeline(m_viz.device(), m_wireframe, nullptr);
            m_wireframe = nullptr;
        }
        if(m_pipeline){
            vkDestroyPipeline(m_viz.device(), m_pipeline, nullptr);
            m_pipeline  = nullptr;
        }
        if(m_layout){
            vkDestroyPipelineLayout(m_viz.device(), m_layout, nullptr);
            m_layout    = nullptr;
        }
    }
#endif

    ////////////////////////////////////////////////////////////////////////////////
    //  ViRendered0
    ////////////////////////////////////////////////////////////////////////////////
#if 0
    ViRendered0::ViRendered0(Visualizer&_viz, const ViPipeline0& _pipe, const Rendered& _obj) : m_viz(_viz), m_pipe(_pipe), m_object(_obj)
    {
        _ctor();
    }
    
    ViRendered0::~ViRendered0()
    {
        _dtor();
    }

    std::error_code     ViRendered0::_ctor()
    {
        size_t i;
        size_t  ds = 0;
        auto& vc    = m_pipe.m_cfg.vbos;
        if(!vc.empty()){
            m_vbos.resize(vc.size());
            for(i=0;i<m_vbos.size();++i){
                m_vbos[i] = m_pipe.m_vbos[i];
                m_vbos[i].update(m_viz, vc[i], &m_object);
            }
        }
            
        auto& ic    = m_pipe.m_cfg.ibos;
        if(!ic.empty()){
            m_ibos.resize(ic.size());
            for(i=0;i<m_ibos.size();++i){
                m_ibos[i] = m_pipe.m_ibos[i];
                m_ibos[i].update(m_viz, ic[i], &m_object);
            }
        }
        
        auto& uc    = m_pipe.m_cfg.ubos;
        if(!uc.empty()){
            m_ubos.resize(uc.size());
            for(i=0;i<m_ubos.size();++i){
                m_ubos[i] = m_pipe.m_ubos[i];
                m_ubos[i].update(m_viz, uc[i], &m_object);
            }
            
            ds += uc.size();
        }
        
        auto& tc    = m_pipe.m_cfg.texs;
        if(!tc.empty()){
            m_texs.resize(tc.size());
            for(i=0;i<m_texs.size();++i){
                m_texs[i] = m_pipe.m_texs[i];
                m_texs[i].update(m_viz, tc[i], &m_object);
            }
            
            ds += tc.size();
        }
        
        
        if(ds){
            //std::vector<VkDescriptorSetLayout>      layouts(ds, m_pipe.m_descriptors);    // TODO efficiency is to push this into ViPipeline0
            VqDescriptorSetAllocateInfo allocInfo;
            allocInfo.descriptorPool        = m_viz.descriptor_pool();
            allocInfo.descriptorSetCount    = ds;
            allocInfo.pSetLayouts           = &m_pipe.m_descriptors;
            m_descriptors.resize(ds, nullptr);
            if(vkAllocateDescriptorSets(m_viz.device(), &allocInfo, m_descriptors.data()) != VK_SUCCESS){
                yInfo() << "Unable to allocate descriptor sets!";
            }
            
            for(i=0;i<m_ubos.size();++i)
                _ubo(i);
            for(i=0;i<m_texs.size();++i)
                _tex(i);
        }
        return std::error_code();
    }
    
    void                ViRendered0::_dtor()
    {
    }

    void    ViRendered0::_ubo(size_t i)
    {
        VkDescriptorBufferInfo  bufferInfo;
        bufferInfo.buffer                   = m_ubos[i].buffer;
        bufferInfo.offset                   = 0;
        bufferInfo.range                    = VK_WHOLE_SIZE;

        VqWriteDescriptorSet    descriptorWrite;
        descriptorWrite.dstSet              = m_descriptors[i];
        descriptorWrite.dstBinding          = i;
        descriptorWrite.dstArrayElement     = 0;
        descriptorWrite.descriptorType      = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrite.descriptorCount     = 1;
        descriptorWrite.pBufferInfo         = &bufferInfo;
        
        vkUpdateDescriptorSets(m_viz.device(), 1, &descriptorWrite, 0, nullptr);
    }

    void    ViRendered0::_tex(size_t i)
    {
        VkDescriptorImageInfo   imageInfo{};
        imageInfo.imageLayout   = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        imageInfo.imageView     = m_texs[i].view;
        imageInfo.sampler       = m_texs[i].sampler;
    
        VqWriteDescriptorSet    descriptorWrite;
        descriptorWrite.dstSet              = m_descriptors[i+m_ubos.size()];
        descriptorWrite.dstBinding          = i;
        descriptorWrite.dstArrayElement     = 0;
        descriptorWrite.descriptorType      = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        descriptorWrite.descriptorCount     = 1;
        descriptorWrite.pImageInfo          = &imageInfo;
        
        vkUpdateDescriptorSets(m_viz.device(), 1, &descriptorWrite, 0, nullptr);
    }

    void                ViRendered0::descriptors(ViContext& u)
    {
        size_t i;
        for(i=0;i<m_ubos.size();++i){
            m_ubos[i].update(m_viz, m_pipe.m_cfg.ubos[i], &m_object);
            _ubo(i);
        }
        for(i=0;i<m_texs.size();++i){
            m_texs[i].update(m_viz, m_pipe.m_cfg.texs[i], &m_object);
            _tex(i);
        }
    }
 
    void                ViRendered0::update(ViContext& u)
    {
        size_t i;

        auto& vc    = m_pipe.m_cfg.vbos;
        for(i=0;i<m_vbos.size();++i)
            m_vbos[i].update(m_viz, vc[i], &m_object);
            
        auto& ic    = m_pipe.m_cfg.ibos;
        for(i=0;i<m_ibos.size();++i)
            m_ibos[i].update(m_viz, ic[i], &m_object);


        const Render3D* r3      = (m_pipe.m_cfg.push.type == PushConfigType::Full) ? dynamic_cast<const Render3D*>(&m_object) : nullptr;
        StdPushData*    push    = (r3 || (m_pipe.m_cfg.push.type == PushConfigType::View)) ? m_push.create_single<StdPushData>() : nullptr;
        if(push)
            push->time       = u.utime();
            
        switch(m_pipe.m_cfg.push.type){
        case PushConfigType::Full:
            if(r3){
                push->matrix    = u.world2eye * r3->model2world();
                break;
            }
            [[fallthrough]];
        case PushConfigType::View:
            push->matrix = u.world2eye;
            break;
        case PushConfigType::Custom:
            if(m_pipe.m_cfg.push.fetch){
                m_push.clear();
                m_pipe.m_cfg.push.fetch(&m_object, m_push);
            }
            break;
        case PushConfigType::None:
        default:
            break;
        }
    }

    void                ViRendered0::record(ViContext&u)
    {
        const auto&         cfg     = m_pipe.m_cfg;
        if(cfg.binding != PipelineBinding::Graphics)     // filter out non-graphics (for now)
            return ;

            //  =================================================
            //      SET THE PIPELINE
        Tristate        wireframe   = (u.wireframe() == Tristate::INHERIT) ? m_object.wireframe() : u.wireframe();
        VkPipeline      vkpipe      = (wireframe == Tristate::YES) ? m_pipe.m_wireframe : m_pipe.m_pipeline;
        if(vkpipe && (vkpipe != u.m_pipeline)){
            vkCmdBindPipeline(u.command(), VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipe);
            u.m_pipeline    = vkpipe;
            u.m_layout      = m_pipe.m_layout;
        }

            //  =================================================
            //      PUSH THE CONSTANTS

        if(!m_push.empty()){
            vkCmdPushConstants(u.command(), m_pipe.m_layout, m_pipe.m_shaders, 0, m_push.size(), m_push.data() );
        }
        
        if(!m_descriptors.empty()){
            vkCmdBindDescriptorSets(u.command(), VK_PIPELINE_BIND_POINT_GRAPHICS, u.m_layout, 0, m_descriptors.size(), m_descriptors.data(), 0, nullptr);
        }
        
        //  =================================================
        //      UNIFORM BUFFERS
        
            // TODO
        
        //  =================================================
        //      TEXTURES

            // TODO

        //  =================================================
        //      VERTEX BUFFERS

        uint32_t    vmax    = 0;
        uint32_t    VN      = cfg.vbos.size();
        if(VN){
            for(uint32_t i=0;i<VN;++i){
                VkDeviceSize    zero{};
                vmax    = std::max(vmax, m_vbos[i].count);
                vkCmdBindVertexBuffers(u.command(), i,  1, &m_vbos[i].buffer, &zero);
            }
        }
        
        //  =================================================
        //      INDEX BUFFERS & DRAWING

        uint32_t    VI      = cfg.ibos.size();
        if(VI){
            for(uint32_t i=0;i<VI;++i){
                vkCmdBindIndexBuffer(u.command(), m_ibos[i].buffer, 0, (VkIndexType)(cfg.ibos[i].type.value()));
                vkCmdDrawIndexed(u.command(), m_ibos[i].count, 1, 0, 0, 0);  // possible point of speedup in future
            }
        } else {
            vkCmdDraw(u.command(), vmax, 1, 0, 0);
        }
    }

#endif

    ////////////////////////////////////////////////////////////////////////////////
    //  ViThread0
    ////////////////////////////////////////////////////////////////////////////////
    
    ViThread0::ViThread0(Visualizer&viz) : m_viz(viz)
    {
        try {
            _ctor();
        }
        catch(std::error_code ec)
        {
            _dtor();
            throw;
        }
    }
    
    ViThread0::~ViThread0()
    {
        _dtor();
    }
    
    void    ViThread0::_ctor()
    {
        uint32_t      dcount  = m_viz.descriptor_count();
        VkDescriptorPoolSize descriptorPoolSizes[] =
        {
            { VK_DESCRIPTOR_TYPE_SAMPLER, dcount },
            { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, dcount },
            { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, dcount },
            { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, dcount },
            { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, dcount },
            { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, dcount },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, dcount },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, dcount },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, dcount },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, dcount },
            { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, dcount }
        };
        
        size_t  cntDPS  = sizeof(descriptorPoolSizes)/sizeof(VkDescriptorPoolSize);
        
        VqDescriptorPoolCreateInfo descriptorPoolInfo;
        //descriptorPoolInfo.flags         = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT | VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT;
        descriptorPoolInfo.flags         = VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT;
        descriptorPoolInfo.maxSets       = dcount * cntDPS;
        descriptorPoolInfo.poolSizeCount = (uint32_t) cntDPS;
        descriptorPoolInfo.pPoolSizes    = descriptorPoolSizes;
        if(vkCreateDescriptorPool(m_viz.device(), &descriptorPoolInfo, nullptr, &m_descriptors) != VK_SUCCESS)
            throw create_error<"Unable to allocate the descriptor pool">();

        VqCommandPoolCreateInfo poolInfo;
        poolInfo.flags                  = m_viz.command_pool_create_flags();
        
        if(m_viz.graphic_queue_valid()){
            poolInfo.queueFamilyIndex   = m_viz.graphic_queue_family();
            if (vkCreateCommandPool(m_viz.device(), &poolInfo, nullptr, &m_graphics) != VK_SUCCESS) 
                throw create_error<"Failed to create a graphic command pool">();
        }
        if(m_viz.compute_queue_valid()){
            poolInfo.queueFamilyIndex   = m_viz.compute_queue_family();
            if (vkCreateCommandPool(m_viz.device(), &poolInfo, nullptr, &m_compute) != VK_SUCCESS) 
                throw create_error<"Failed to create a compute command pool">();
        }
    }
    
    void    ViThread0::_dtor()
    {
        if(m_descriptors){
            vkDestroyDescriptorPool(m_viz.device(), m_descriptors, nullptr);
            m_descriptors = nullptr;
        }
        if(m_graphics){
            vkDestroyCommandPool(m_viz.device(), m_graphics, nullptr);
            m_graphics = nullptr;
        }
        if(m_compute){
            vkDestroyCommandPool(m_viz.device(), m_compute, nullptr);
            m_compute = nullptr;
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////////
    //  VISUALIZER
    ////////////////////////////////////////////////////////////////////////////////

    Visualizer::Visualizer() 
    {
        m_cmdPoolCreateFlags    = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT; //  | VK_COMMAND_POOL_CREATE_PROTECTED_BIT;
    }
    
    Visualizer::~Visualizer()
    {
        kill_visualizer();
    }
    
    

    std::error_code             Visualizer::_ctor(const ViewerCreateInfo&vci, GLFWwindow*w)
    {
        std::error_code ec;
    
        InitData   iData(vci);
    
        ec  = _0_app_window_initialize(w);
        if(ec != std::error_code())
            return ec;
        
        ec  = _1_gpu_select_initialize(iData);
        if(ec != std::error_code())
            return ec;

        ec = _2_surface_initialize(iData);
        if(ec != std::error_code())
            return ec;
       
        iData.extensions    = vci.extensions;
        iData.extensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

            //  And we need to create them... so request
        ec = _3_queues_create(iData);
        if(ec != std::error_code())
            return ec;
                
        ec = _4_device_init(iData);
        if(ec != std::error_code())
            return ec;

        _3_queues_fetch();

        ec = _5_allocator_init(iData);
        if(ec != std::error_code())
            return ec;

        ec  = _6_manager_init();
        if(ec != std::error_code())
            return ec;

        ec = _7_render_pass_create();
        if(ec != std::error_code())
            return ec;
        
        ec = _8_swapchain_create();
        if(ec != std::error_code())
            return ec;
            
        ec = _9_pipeline_manager_create();
        if(ec != std::error_code())
            return ec;

        //  ================================
        //  GETTING THE QUEUES


        //  ================================
        //  ALLOCATOR


        //  ================================
        //  DESCRIPTOR COUNTS

        m_descriptorCount   = std::max(MIN_DESCRIPTOR_COUNT, vci.descriptors);

        m_thread            = std::make_unique<ViThread0>(*this);




        m_frames.reserve(vci.frames_in_flight);
        for(size_t i=0;i<vci.frames_in_flight;++i)
            m_frames.push_back(std::make_unique<ViFrame0>(*this));
            
        return std::error_code();
    }
    
    void                        Visualizer::_dtor()
    {
        m_frames.clear();
        
        m_thread        = {};
    
        //  Generally in reverse order of initialization

        _9_pipeline_manager_kill();
        _8_swapchain_kill();
        _7_render_pass_kill();
        _6_manager_kill();
        _5_allocator_kill();
        _4_device_kill();
        _3_queues_kill();
        _2_surface_kill();
        _1_gpu_select_kill();
        _0_app_window_kill();
    }

    std::error_code             Visualizer::init_visualizer(const ViewerCreateInfo& vci, GLFWwindow* w)
    {
        if(m_init)
            return std::error_code();
            
        std::error_code ec  = _ctor(vci, w);
        if(ec){
            _dtor();
            return ec;
        }
         
        m_init      = true;
        return std::error_code();

    }
    
    void                        Visualizer::kill_visualizer()
    {
        if(!m_init)
            return ;
        _dtor();
        m_init  = false;
    }


    ////////////////////////////////////////////////////////////////////////////////
    //  GETTERS/INFORMATION


    VkCommandBuffer Visualizer::command_buffer() const
    {
        return current_frame0().m_commandBuffer;
    }

    VkCommandPool   Visualizer::command_pool() const
    {
        return m_thread->m_graphics;
    }


    ViFrame0&            Visualizer::current_frame0()
    {
        return *(m_frames[m_tick % m_frames.size()]);
    }
    
    const ViFrame0&      Visualizer::current_frame0() const
    {
        return const_cast<Visualizer*>(this)->current_frame0();
    }

    VkDescriptorPool    Visualizer::descriptor_pool() const
    {
        return m_thread->m_descriptors;
    }

    
    ViFrame0&            Visualizer::frame0(int32_t i)
    {
        uint64_t    tick    = (uint64_t)((int64_t) m_tick + i);
        return *(m_frames[tick % m_frames.size() ]);
    }
    
    const ViFrame0&      Visualizer::frame0(int32_t i) const
    {
        return const_cast<Visualizer*>(this)->frame0(i);
    }

    ViFrame0&            Visualizer::next_frame0()
    {
        return *(m_frames[(m_tick+1) % m_frames.size()]);
    }
    
    const ViFrame0&      Visualizer::next_frame0() const
    {
        return const_cast<Visualizer*>(this)->next_frame0();
    }


    ////////////////////////////////////////////////////////////////////////////////
    //  RENDERING

    std::error_code     Visualizer::_record(ViContext& u, uint32_t imageIndex, DrawFunction use)
    {
        VqCommandBufferBeginInfo beginInfo;
        beginInfo.flags = 0; // Optional
        beginInfo.pInheritanceInfo = nullptr; // Optional

        if (vkBeginCommandBuffer(u.command_buffer, &beginInfo) != VK_SUCCESS)
            return create_error<"Failed to begin recording command buffer">();

        VqRenderPassBeginInfo renderPassInfo;
        renderPassInfo.renderPass = render_pass();
        renderPassInfo.framebuffer = m_swapchain->framebuffer(imageIndex);
        renderPassInfo.renderArea.offset = {0, 0};
        renderPassInfo.renderArea.extent = m_swapchain->extents();

        renderPassInfo.clearValueCount = 1;
        VkClearValue                cv  = m_clearValue;
        renderPassInfo.pClearValues = &cv;
        vkCmdBeginRenderPass(u.command_buffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

        std::error_code     ret;
        try {
            if(use){
                use(u);
            } else
                record(u);
        }
        catch(std::error_code ec) {
            ret = ec;
        }
            
        vkCmdEndRenderPass(u.command_buffer);
        if (vkEndCommandBuffer(u.command_buffer) != VK_SUCCESS)
            return create_error<"Failed to record command buffer">();
        return ret;
    }

    std::error_code     Visualizer::draw(ViContext& u, DrawFunction use)
    {
        static constexpr const uint64_t     kMaxWait = 100'000'000ULL;
    
        if(!m_swapchain){
            vizCritical << "Visualizer::draw ... attempting to draw on a swapchain WITHOUT a swapchain";
            return errors::swapchain_uninitialized();
        }
        
        auto    r1 = auto_reset(u.viz, this);
        ViFrame0&    f   = current_frame0();
        auto    r2  = auto_reset(u.command_buffer, f.m_commandBuffer);
        auto    r3  = auto_reset(u.frame0, &f);

        VkResult        res = VK_SUCCESS;
        
        res = vkWaitForFences(m_device, 1, &f.m_fence, VK_TRUE, kMaxWait);   // 100ms is 10Hz
        if(res == VK_TIMEOUT)
            return create_error<"Fence timeout">();

        bool    rebuildFlag = m_rebuildSwap.exchange(false);
        if(rebuildFlag){
            _rebuild_swapchain();
            return std::error_code();
        }

        uint32_t imageIndex = 0;
        res    = vkAcquireNextImageKHR(m_device, m_swapchain->swapchain(), kMaxWait, f.m_imageAvailable, VK_NULL_HANDLE, &imageIndex);
        
        switch(res){
        case VK_TIMEOUT:
            return create_error<"Acquire image timeout">();
        case VK_ERROR_OUT_OF_DATE_KHR:
        case VK_SUBOPTIMAL_KHR:
            _rebuild_swapchain();
            return std::error_code();
        case VK_SUCCESS:
            break;
        case VK_ERROR_OUT_OF_HOST_MEMORY:
            return create_error<"Out of host memory">();
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:
            return create_error<"Out of device memory">();
        case VK_ERROR_DEVICE_LOST:
            return create_error<"Device lost">();
        case VK_ERROR_SURFACE_LOST_KHR:
            return create_error<"Surface lost">();
        case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
            return create_error<"Full screen exclusive mode lost">();
        default:
            return create_error<"Unexpected error">();
        }
        
        prerecord(u);

        vkResetFences(m_device, 1, &f.m_fence);
        vkResetCommandBuffer(u.command_buffer, 0);
        
    
        std::error_code ec = _record(u, imageIndex, use);
        if(ec)
            return ec;
        
        VqSubmitInfo submitInfo;

        VkSemaphore waitSemaphores[] = { f.m_imageAvailable };
        VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
        submitInfo.waitSemaphoreCount = 1;
        submitInfo.pWaitSemaphores      = waitSemaphores;
        submitInfo.pWaitDstStageMask    = waitStages;
        submitInfo.commandBufferCount   = 1;
        submitInfo.pCommandBuffers      = &f.m_commandBuffer;

        VkSemaphore signalSemaphores[]  = {f.m_renderFinished};
        submitInfo.signalSemaphoreCount = 1;
        submitInfo.pSignalSemaphores    = signalSemaphores;

        if (vkQueueSubmit(m_graphicsQueue->queue(0), 1, &submitInfo, f.m_fence) != VK_SUCCESS) 
            return create_error<"Failed to submit draw command buffer">();
            
        VqPresentInfoKHR presentInfo;

        VkSwapchainKHR      swapchains[] = { m_swapchain -> swapchain() };

        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = signalSemaphores;
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = swapchains;
        presentInfo.pImageIndices = &imageIndex;
        presentInfo.pResults = nullptr; // Optional
        vkQueuePresentKHR(m_presentQueue->queue(0), &presentInfo);
        
        ++m_tick;
        return std::error_code();
    }

    void    Visualizer::_draw(ViContext&u, const RenderedCPtr&r, Tristate w)
    {
        //const auto&         cfg     = p.config();
        //if(cfg->binding != PipelineBinding::Graphics)     // filter out non-graphics (for now)
            //return ;
        
        u.wireframe       = w;
            
        // TODO ... reduce this down to a single pipeline lookup.... (as the next one is implicit)
        
        //  FOR NOW....
        
        ViRenderedPtr       thing = current_frame0().create(r);
        if(!thing)
            return;
        thing -> update(u);
        thing -> record(u);
    }

    void    Visualizer::draw_object(ViContext&u, const RenderedCPtr&r, Tristate w)
    {
        if(!r)
            return ;
        _draw(u, r, w);
    }

    void    Visualizer::draw_scene(ViContext& u, const Scene&sc, const Perspective& p)
    {
        if(u.viz != this) //  fast reject
            return ;
        if(!p.camera)
            return ;
            
        auto r1 = auto_reset(u.time, sc.utime);
        
        Camera::Params      cparams;
        if(p.screen){
            cparams.screen = *p.screen;
        } else {
            int         w, h;
            glfwGetFramebufferSize(m_window, &w, &h);
            cparams.screen  = Size2D((double) w, (double) h);
        }
        
        auto r2 = auto_reset(u.world2eye, p.camera->world2screen(cparams));
        
        for(auto& r : sc.things){
            if(!r)
                continue;
            draw_object(u, r, p.wireframe);
        }
    }

    void               Visualizer::update(ViContext&u, const Scene&sc)
    {
        if(u.frame0){
            for(auto& r : sc.things){
                const Pipeline*pipe    = r->pipeline();
                if(!pipe)
                    continue;
                    
                ViRenderedPtr  rr  = u.frame0 -> create(r);
                if(!rr)
                    continue;
                rr -> update(u);
                rr -> descriptors();
            }
        }
    }
}
