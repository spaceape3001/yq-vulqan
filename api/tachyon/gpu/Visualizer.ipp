////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/VqApp.hpp>

#include <basic/ErrorDB.hpp>
#include <math/color/RGBA.hpp>
//#include <tachyon/errors.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/Shader.hpp>
#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/gpu/VqUtils.hpp>

#include <GLFW/glfw3.h>

namespace yq {

    namespace tachyon {

        VkRect2D  ViSwapchain::def_scissor() const
        {
            VkRect2D    ret{};
            ret.offset  = { 0, 0 };
            ret.extent  = extents;
            return ret;
        }
        
        VkViewport  ViSwapchain::def_viewport() const
        {
            VkViewport  ret{};
            ret.x = 0.0f;
            ret.y = 0.0f;
            ret.width = (float) extents.width;
            ret.height = (float) extents.height;
            ret.minDepth = 0.0f;
            ret.maxDepth = 1.0f;
            return ret;
        }
        
        uint32_t  ViSwapchain::width() const 
        { 
            return extents.width; 
        }
        
        uint32_t  ViSwapchain::height() const 
        { 
            return extents.height; 
        }


        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        Visualizer::Visualizer() 
        {
        }
        
        Visualizer::~Visualizer()
        {
            kill_visualizer();
        }
        
        namespace {
            std::vector<float>      make_weights(const ViQueueSpec& qs, uint32_t mincnt=0)
            { 
                if(const std::vector<float>*p = std::get_if<std::vector<float>>(&qs)){
                    if((!p->empty()) && (p->size() >= (size_t) mincnt))
                        return *p;
                }
                uint32_t    cnt = mincnt;
                if(const uint32_t* p = std::get_if<uint32_t>(&qs))
                    cnt = std::max(cnt, *p);
                if(const bool* p = std::get_if<bool>(&qs)){
                    if(*p)
                        cnt = std::max<uint32_t>(cnt, 1);
                }
                if(cnt){
                    std::vector<float> ret;
                    ret.resize(cnt, 1.);
                    return ret;
                }
                return std::vector<float>();
            }
        }

        std::error_code             Visualizer::_ctor(const ViewerCreateInfo&vci,GLFWwindow*w)
        {
            std::error_code ec;
        
            m_app       = VqApp::vk_app();
            if(!m_app)
                return create_error<"No application available">();

            m_window    = w;
            if(!w)
                return create_error<"No window provided">();
                
            m_instance    = m_app -> vulkan();
            if(!m_instance)
                return create_error<"Vulkan unavailable">();

            //  ================================
            //  SELECT GPU (ie, physical device)

            m_physical                    = vci.device;
            if(!m_physical){
                m_physical  = vqFirstDevice();
                if(!m_physical)
                    return create_error<"No GPU/Physical device provided or detected">();
            }
            
            vkGetPhysicalDeviceProperties(m_physical, &m_deviceInfo);
            vkGetPhysicalDeviceMemoryProperties(m_physical, &m_memoryInfo);
           
            //  ================================
            //  GLFW "SURFACE"

            if(glfwCreateWindowSurface(m_instance, m_window, nullptr, &m_surface) != VK_SUCCESS)
                return create_error<"No window surface available">();
                
            for(auto pm : vqGetPhysicalDeviceSurfacePresentModesKHR(m_physical, m_surface))
                m_presentModes.insert((PresentMode::enum_t) pm);
            m_surfaceFormats        = vqGetPhysicalDeviceSurfaceFormatsKHR(m_physical, m_surface);
            
            // right now, cheating on format & color space
            m_surfaceFormat         = VK_FORMAT_B8G8R8A8_SRGB;
            m_surfaceColorSpace     = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;

            //  ================================
            //  LOGICAL DEVICE CREATION
            //
            //  Buckle up, this is a long one

                // list extensions, augmenting with swap chain
                
            std::vector<const char*>    devExtensions = vci.extensions;
            devExtensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

                //  Query the GPU for valid queue families
            auto queueInfos         = vqFindQueueFamilies(m_physical, m_surface);
            
                //  And we need to create them... so request
            std::vector<VkDeviceQueueCreateInfo> qci;
            
                //  graphic is required....
            std::vector<float>  graphicWeights  = make_weights(vci.graphic, 1);
            if(!queueInfos.graphics.has_value()){
                return create_error<"No graphic queue capability">();
            } else {
                m_graphic.family        = queueInfos.graphics.value();
                VqDeviceQueueCreateInfo info;
                info.queueFamilyIndex   = m_graphic.family;
                info.queueCount         = (uint32_t) graphicWeights.size();
                info.pQueuePriorities   = graphicWeights.data();
                qci.push_back(info);
            }
            
                //  present is required....
            std::vector<float>  presentWeights  = make_weights(vci.present, 1);
            if(!queueInfos.present.has_value()){
                return create_error<"No present queue capability">();
            } else {
                m_present.family        = queueInfos.present.value();
                VqDeviceQueueCreateInfo info;
                info.queueFamilyIndex   = m_present.family;
                info.queueCount         = (uint32_t) presentWeights.size();
                info.pQueuePriorities   = presentWeights.data();
                qci.push_back(info);
            }
            
                //  Determine if compute is requested, create the request
            std::vector<float>  computeWeights  = make_weights(vci.compute, 0);
            if(!computeWeights.empty()){
                if(!queueInfos.compute.has_value()){
                    return create_error<"No compute queue capability">();
                } else {
                    m_compute.family        = queueInfos.compute.value();
                    VqDeviceQueueCreateInfo info;
                    info.queueFamilyIndex   = m_compute.family;
                    info.queueCount         = (uint32_t) computeWeights.size();
                    info.pQueuePriorities   = computeWeights.data();
                    qci.push_back(info);
                }
            }

                //  Determine if video decoding is requested, create the request
            std::vector<float>  videoDecWeights = make_weights(vci.video_decode, 0);
            if(!videoDecWeights.empty()){
                if(!queueInfos.videoDecode.has_value()){
                    return create_error<"No video decode queue capability">();
                } else {
                    m_videoDecode.family    = queueInfos.videoDecode.value();
                    VqDeviceQueueCreateInfo info;
                    info.queueFamilyIndex   = m_videoDecode.family;
                    info.queueCount         = (uint32_t) videoDecWeights.size();
                    info.pQueuePriorities   = videoDecWeights.data();
                    qci.push_back(info);
                }
            }
            
                //  Determine if video encoding is requested, create the request
            std::vector<float>  videoEncWeights = make_weights(vci.video_encode, 0);
            if(!videoEncWeights.empty()){
                if(!queueInfos.videoEncode.has_value()){
                    return create_error<"No video encode queue capability">();
                } else {
                    m_videoEncode.family    = queueInfos.videoEncode.value();
                    VqDeviceQueueCreateInfo info;
                    info.queueFamilyIndex   = m_videoEncode.family;
                    info.queueCount         = (uint32_t) videoEncWeights.size();
                    info.pQueuePriorities   = videoEncWeights.data();
                    qci.push_back(info);
                }
            }
            
            std::sort(qci.begin(), qci.end(), [](const VkDeviceQueueCreateInfo& a, const VkDeviceQueueCreateInfo& b) -> bool {
                return a.queueFamilyIndex < b.queueFamilyIndex;
            });
            
            for(size_t i=0;i<qci.size()-1;++i){
                VkDeviceQueueCreateInfo&    prev  = qci[i];
                VkDeviceQueueCreateInfo&    next  = qci[i+1];
                if(prev.queueFamilyIndex != next.queueFamilyIndex)
                    continue;
                
                //  carry the request forward
                if(next.queueCount < prev.queueCount){
                    //  steal the pointer
                    next.queueCount         = prev.queueCount;
                    next.pQueuePriorities   = prev.pQueuePriorities;
                }
                prev.queueFamilyIndex   = UINT32_MAX;
            }
            
            auto qitr = std::remove_if(qci.begin(), qci.end(), [](const VkDeviceQueueCreateInfo& a) -> bool {
                return a.queueFamilyIndex == UINT32_MAX;
            });
            if(qitr != qci.end())
                qci.erase(qitr, qci.end());
                    
            //  And with that, we have the queues all lined up, ready to be created.

            VkPhysicalDeviceFeatures    gpu_features{};
            if(vci.fill_non_solid)
                gpu_features.fillModeNonSolid    = VK_TRUE;

            VqDeviceCreateInfo          deviceCreateInfo;
            deviceCreateInfo.pQueueCreateInfos        = qci.data();
            deviceCreateInfo.queueCreateInfoCount     = (uint32_t) qci.size();
            deviceCreateInfo.pEnabledFeatures         = &gpu_features;
            
            const auto& layers = m_app->layers();
            
            deviceCreateInfo.enabledLayerCount          = (uint32_t) layers.size();
            if(deviceCreateInfo.enabledLayerCount)
                deviceCreateInfo.ppEnabledLayerNames    = layers.data();
        
            deviceCreateInfo.enabledExtensionCount      = (uint32_t) devExtensions.size();
            deviceCreateInfo.ppEnabledExtensionNames    = devExtensions.data();
            
            VqPhysicalDeviceVulkan12Features            v12features;
            v12features.bufferDeviceAddress = true;
            deviceCreateInfo.pNext          = &v12features;
            
            if(vkCreateDevice(m_physical, &deviceCreateInfo, nullptr, &m_device) != VK_SUCCESS)
                return create_error<"Unable to create vulkan (logical) device">();

            //  ================================
            //  GETTING THE QUEUES

            m_graphic.set(m_device, graphicWeights.size());
            m_present.set(m_device, presentWeights.size());
            if(m_compute.family != UINT32_MAX)
                m_compute.set(m_device, computeWeights.size());
            if(m_videoEncode.family != UINT32_MAX)
                m_videoEncode.set(m_device, videoEncWeights.size());
            if(m_videoDecode.family != UINT32_MAX)
                m_videoDecode.set(m_device, videoDecWeights.size());

            //  ================================
            //  ALLOCATOR

            VmaAllocatorCreateInfo      allocatorCreateInfo{};
            allocatorCreateInfo.instance                        = m_instance;
            allocatorCreateInfo.physicalDevice                  = m_physical;
            allocatorCreateInfo.device                          = m_device;
            allocatorCreateInfo.vulkanApiVersion                = m_app->app_info().vulkan_api;
            allocatorCreateInfo.preferredLargeHeapBlockSize     = (VkDeviceSize) vci.chunk_size;
            vmaCreateAllocator(&allocatorCreateInfo, &m_allocator);

            //  ================================
            //  DESCRIPTOR COUNTS
    
            m_descriptorCount   = std::max(MIN_DESCRIPTOR_COUNT, vci.descriptors);

            ec = _create(m_thread);
            if(ec)
                return ec;

            //  ================================
            //  RENDER PASS

            VkAttachmentDescription colorAttachment{};
            colorAttachment.format          = m_surfaceFormat;
            colorAttachment.samples         = VK_SAMPLE_COUNT_1_BIT;
            colorAttachment.loadOp          = VK_ATTACHMENT_LOAD_OP_CLEAR;
            colorAttachment.storeOp         = VK_ATTACHMENT_STORE_OP_STORE;        
            colorAttachment.stencilLoadOp   = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            colorAttachment.stencilStoreOp  = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            colorAttachment.initialLayout   = VK_IMAGE_LAYOUT_UNDEFINED;
            colorAttachment.finalLayout     = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
            
            VkAttachmentReference colorAttachmentRef{};
            colorAttachmentRef.attachment = 0;
            colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

            VkSubpassDescription subpass{};
            subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;        

            subpass.colorAttachmentCount = 1;
            subpass.pColorAttachments = &colorAttachmentRef;
            
            VqRenderPassCreateInfo renderPassInfo;
            renderPassInfo.attachmentCount = 1;
            renderPassInfo.pAttachments = &colorAttachment;
            renderPassInfo.subpassCount = 1;
            renderPassInfo.pSubpasses = &subpass;

            if (vkCreateRenderPass(m_device, &renderPassInfo, nullptr, &m_renderPass) != VK_SUCCESS) 
                return create_error<"Unable to create the render pass">();

            //  ================================
            //  PRESENT MODE

            m_presentMode               = m_presentModes.contains(vci.pmode) ? vci.pmode : PresentMode{ PresentMode::Fifo };

            for(auto& f : m_frames){
                ec = _create(f);
                if(ec)
                    return ec;
            }
                

            ec  = _create(m_swapchain);
            if(ec)
                return ec;
            return std::error_code();
        }
        
        void                        Visualizer::_dtor()
        {
            if(m_swapchain.swapchain){
                _destroy(m_swapchain);
                m_swapchain.swapchain   = nullptr;
            }
        
            for(auto& f : m_frames)
                _destroy(f);
        
            if(m_renderPass)
                vkDestroyRenderPass(m_device, m_renderPass, nullptr);
            
            _destroy(m_thread);
        
            //  At *this* point, we don't need the mutex... we're dying anyways
            for(auto& psh : m_shaders.hash)
                _destroy(psh.second);
            for(auto& psh : m_shaders.loose)
                _destroy(psh);
            m_shaders.clear();
            
        
            if(m_allocator){
                vmaDestroyAllocator(m_allocator);
                m_allocator = nullptr;
            }
        
            //  Generally in reverse order of above
            if(m_device){
                vkDestroyDevice(m_device, nullptr);
                m_device                = nullptr;
            }
            m_graphic                   = {};
            m_present                   = {};
            m_compute                   = {};
            m_videoEncode               = {};
            m_videoDecode               = {};

            if(m_surface){
                vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
                m_surface               = nullptr;
            }

            m_physical      = nullptr;
            m_instance      = nullptr;
            m_window        = nullptr;
            m_app           = nullptr;
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
        //  SUB CREATE/DESTROY

        std::error_code             Visualizer::_create(ViFrame&p)
        {
            try {
                VqCommandBufferAllocateInfo allocInfo;
                allocInfo.commandPool           = m_thread.graphic;
                allocInfo.level                 = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
                allocInfo.commandBufferCount    = 1;
                if (vkAllocateCommandBuffers(m_device, &allocInfo, &p.commandBuffer) != VK_SUCCESS) 
                    throw create_error<"Failed to allocate command buffers">();

                VqFenceCreateInfo   fci;
                fci.flags = VK_FENCE_CREATE_SIGNALED_BIT;
                if(vkCreateFence(m_device, &fci, nullptr,  &p.fence) != VK_SUCCESS)
                    throw create_error<"Unable to create fence">();

                VqSemaphoreCreateInfo   info;
                if(vkCreateSemaphore(m_device, &info, nullptr, &p.imageAvailable) != VK_SUCCESS)
                    throw create_error<"Unable to create semaphore!">();
                if(vkCreateSemaphore(m_device, &info, nullptr, &p.renderFinished) != VK_SUCCESS)
                    throw create_error<"Unable to create semaphore!">();
                return std::error_code();
            }
            catch(std::error_code ec)
            {
                _destroy(p);
                return ec;
            }
        }
        
        void                        Visualizer::_destroy(ViFrame&p)
        {
            if(p.commandBuffer && m_thread.graphic){
                vkFreeCommandBuffers(m_device, m_thread.graphic, 1, &p.commandBuffer);
                p.commandBuffer   = nullptr;
            }
            
            if(p.imageAvailable){
                vkDestroySemaphore(m_device, p.imageAvailable, nullptr);
                p.imageAvailable  = nullptr;
            }
            
            if(p.renderFinished){
                vkDestroySemaphore(m_device, p.renderFinished, nullptr);
                p.renderFinished  = nullptr;
            }
            
            if(p.fence){
                vkDestroyFence(m_device, p.fence, nullptr);
                p.fence   = nullptr;
            }
            
        }


        #if 0
        std::error_code          Visualizer::_create(ViPipeline&p, const PipelineConfig&cfg)
        {
            try {

                std::vector<VkPipelineShaderStageCreateInfo>    stages;
                p.shaders           = 0;
                for(auto& s : cfg.shaders){
                    Ref<const Shader>   sh  = Shader::decode(s);
                    if(!sh)
                        continue;
                    
                    auto  xvs       = shader_create(sh);
                    if(!xvs)
                        continue;
                    
                    VqPipelineShaderStageCreateInfo stage;
                    stage.stage     = xvs->mask;
                    stage.pName     = "main";
                    stage.module    = xvs->shader;
                    stages.push_back(stage);

                    p.shaders |= xvs->mask;
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
                    if(vkCreateDescriptorSetLayout(m_device, &layoutInfo, nullptr, &m_descriptorSetLayout) != VK_SUCCESS)
                        throw create_error<"Unable to create a descriptor set layout">();
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
                        push.size   = sizeof(tachyon::StdPushData);
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


                if (vkCreatePipelineLayout(m_device, &pipelineLayoutInfo, nullptr, &m_layout) != VK_SUCCESS) 
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
                if (vkCreateGraphicsPipelines(m_device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_pipeline) != VK_SUCCESS) 
                    throw VqException("Failed to create graphics pipeline!");
                
                    // if it's a fill polygon (typical), create a derivative wireframe pipeline
                if(cfg.polymode == PolygonMode::Fill){
                    pipelineInfo.flags  = VK_PIPELINE_CREATE_DERIVATIVE_BIT;
                    pipelineInfo.basePipelineHandle = m_pipeline;
                    pipelineInfo.basePipelineIndex  = -1;
                    rasterizer.polygonMode  = VK_POLYGON_MODE_LINE;
                    
                    if (vkCreateGraphicsPipelines(m_device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_wireframe) != VK_SUCCESS)
                        throw VqException("Failed to create wireframe pipeline!");
                }

                return p;
            }
            catch(std::error_code ec)
            {
                _destroy(p);
                return ec;
            }
                
        }
        #endif
        
        void                        Visualizer::_destroy(ViPipeline&p)
        {
            if(p.descriptors)
                vkDestroyDescriptorSetLayout(m_device, p.descriptors, nullptr);
            if(p.wireframe)
                vkDestroyPipeline(m_device, p.wireframe, nullptr);
            if(p.pipeline)
                vkDestroyPipeline(m_device, p.pipeline, nullptr);
            if(p.layout)
                vkDestroyPipelineLayout(m_device, p.layout, nullptr);
        }
        
        
        std::error_code            Visualizer::_create(ViShader& p, const Shader&sh)
        {
            p.mask  = VkShaderStageFlagBits{};
            switch(sh.shader_type()){
            case ShaderType::VERT:
                p.mask = VK_SHADER_STAGE_VERTEX_BIT;
                break;
            case ShaderType::TESC:
                p.mask = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
                break;
            case ShaderType::TESE:
                p.mask = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
                break;
            case ShaderType::FRAG:
                p.mask = VK_SHADER_STAGE_FRAGMENT_BIT;
                break;
            case ShaderType::GEOM:
                p.mask = VK_SHADER_STAGE_GEOMETRY_BIT;
                break;
            case ShaderType::COMP:
                p.mask = VK_SHADER_STAGE_COMPUTE_BIT;
                break;
            default:
                return create_error<"Shader needs a valid/supported type!">();
            }
                
            const ByteArray&    code    = sh.payload();
            VqShaderModuleCreateInfo createInfo;
            createInfo.codeSize = code.size();
            createInfo.pCode    = reinterpret_cast<const uint32_t*>(code.data());
            if (vkCreateShaderModule(m_device, &createInfo, nullptr, &p.shader) != VK_SUCCESS) 
                return create_error<"Shader creation failed">();
            return std::error_code();
        }
        
        void                        Visualizer::_destroy(ViShader&sh)
        {
            if(sh.shader)
                vkDestroyShaderModule(m_device, sh.shader, nullptr);
        }


        std::error_code             Visualizer::_create(ViSwapchain&p)
        {
            try {
                if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_physical, m_surface, &p.capabilities) != VK_SUCCESS)
                    return create_error<"Unable to get surface capabilities">();
                if (p.capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
                    p.extents = p.capabilities.currentExtent;
                } else {
                    int w, h;
                    glfwGetFramebufferSize(m_window, &w, &h);
                    p.extents = {};
                    p.extents.width  = std::clamp((uint32_t) w, p.capabilities.minImageExtent.width, p.capabilities.maxImageExtent.width);
                    p.extents.height = std::clamp((uint32_t) h, p.capabilities.minImageExtent.height, p.capabilities.maxImageExtent.height);
                }

                #if 0
                int w, h;
                glfwGetFramebufferSize(viz._window(), &w, &h);
                vqInfo << "init dymamic stuff\n"<<
                "Frame itself is [" << w << 'x' << h << "] vs\n" <<
                "Image extents is " << ds.extents << '\n' <<
                "Cur is " << capabilities.currentExtent << '\n' <<
                "Min is " << capabilities.minImageExtent << '\n' <<
                "Max is " << capabilities.maxImageExtent
                ;
                #endif

                p.minImageCount             = p.capabilities.minImageCount;
                if(p.minImageCount < 2)
                    p.minImageCount   = 2;
                p.imageCount                  = p.minImageCount + 1;
                if (p.capabilities.maxImageCount > 0 && p.imageCount > p.capabilities.maxImageCount) {
                    p.imageCount = p.capabilities.maxImageCount;
                }

                VqSwapchainCreateInfoKHR    swapInfo;
                swapInfo.surface          = m_surface;
                swapInfo.minImageCount    = p.imageCount;
                swapInfo.imageFormat      = m_surfaceFormat;
                swapInfo.imageColorSpace  = m_surfaceColorSpace;
                swapInfo.imageExtent      = p.extents;
                swapInfo.imageArrayLayers = 1;    // we're not steroscopic (YET)  <-- OCULUS HERE
                swapInfo.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
                
                uint32_t queueFamilyIndices[] = {m_graphic.family, m_present.family};
                if (m_graphic.family != m_present.family) {
                    swapInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
                    swapInfo.queueFamilyIndexCount = 2;
                    swapInfo.pQueueFamilyIndices = queueFamilyIndices;
                } else {
                    swapInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
                    swapInfo.queueFamilyIndexCount = 0; // Optional
                    swapInfo.pQueueFamilyIndices = nullptr; // Optional
                }        
                swapInfo.preTransform     = p.capabilities.currentTransform;
                swapInfo.compositeAlpha   = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
                swapInfo.presentMode      = (VkPresentModeKHR) m_presentMode.value();
                swapInfo.clipped          = VK_TRUE;
                
                swapInfo.oldSwapchain   = m_swapchain.swapchain;
                    
                if (vkCreateSwapchainKHR(m_device, &swapInfo, nullptr, &p.swapchain) != VK_SUCCESS)
                    throw create_error<"Failed to create the swapchain">();

                if(vkGetSwapchainImagesKHR(m_device, p.swapchain, &p.imageCount, nullptr) != VK_SUCCESS)
                    throw create_error<"Unable to get swapchain image count">();
                
                p.images.resize(p.imageCount, nullptr);
                if(vkGetSwapchainImagesKHR(m_device, p.swapchain, &p.imageCount, p.images.data()) != VK_SUCCESS)
                    throw create_error<"Unable to get swapchain images">();
                                
                p.imageViews.resize(p.imageCount, nullptr);

                VqImageViewCreateInfo       imageViewInfo;
                imageViewInfo.viewType     = VK_IMAGE_VIEW_TYPE_2D;
                imageViewInfo.format       = m_surfaceFormat;
                imageViewInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
                imageViewInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
                imageViewInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
                imageViewInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
                imageViewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
                imageViewInfo.subresourceRange.baseMipLevel = 0;
                imageViewInfo.subresourceRange.levelCount = 1;
                imageViewInfo.subresourceRange.baseArrayLayer = 0;
                imageViewInfo.subresourceRange.layerCount = 1;
                
                for(size_t i=0; i<p.imageCount; ++i){
                    imageViewInfo.image        = p.images[i];
                    if(vkCreateImageView(m_device, &imageViewInfo, nullptr, &p.imageViews[i]) != VK_SUCCESS) 
                        throw create_error<"Unable to create a swapchain image viewer">();
                }                
                
                p.frameBuffers.resize(p.imageCount, nullptr);

                VqFramebufferCreateInfo   frameBufferInfo;
                frameBufferInfo.renderPass       = m_renderPass;
                frameBufferInfo.attachmentCount  = 1;
                frameBufferInfo.width            = p.extents.width;
                frameBufferInfo.height           = p.extents.height;
                frameBufferInfo.layers           = 1;

                for(size_t i=0;i<p.imageCount;++i){
                    frameBufferInfo.pAttachments = &p.imageViews[i];
                    if (vkCreateFramebuffer(m_device, &frameBufferInfo, nullptr, &p.frameBuffers[i]) != VK_SUCCESS) 
                        throw create_error<"Failed to create a swapchain framebuffer">();
                }
                return std::error_code();
            }
            catch(std::error_code ec){
                _destroy(p);
                return ec;
            }
        }
        
        void                        Visualizer::_destroy(ViSwapchain&p)
        {
            for(size_t i=0;i<p.imageCount;++i){
                if((i < p.frameBuffers.size()) && p.frameBuffers[i])
                    vkDestroyFramebuffer(m_device, p.frameBuffers[i], nullptr);
                if((i < p.imageViews.size()) && p.imageViews[i])
                    vkDestroyImageView(m_device, p.imageViews[i], nullptr);
            }
            p.frameBuffers.clear();
            p.imageViews.clear();
            p.images.clear();
            if(p.swapchain){
                vkDestroySwapchainKHR(m_device, p.swapchain, nullptr);
                p.swapchain  = nullptr;
            }
        }

            
        std::error_code             Visualizer::_create(ViThread&p)
        {
            try {
                VkDescriptorPoolSize descriptorPoolSizes[] =
                {
                    { VK_DESCRIPTOR_TYPE_SAMPLER, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, m_descriptorCount },
                    { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, m_descriptorCount }
                };
                
                size_t  cntDPS  = sizeof(descriptorPoolSizes)/sizeof(VkDescriptorPoolSize);
                
                VqDescriptorPoolCreateInfo descriptorPoolInfo;
                descriptorPoolInfo.flags         = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
                descriptorPoolInfo.maxSets       = m_descriptorCount * cntDPS;
                descriptorPoolInfo.poolSizeCount = (uint32_t) cntDPS;
                descriptorPoolInfo.pPoolSizes    = descriptorPoolSizes;
                if(vkCreateDescriptorPool(m_device, &descriptorPoolInfo, nullptr, &p.descriptors) != VK_SUCCESS)
                    throw create_error<"Unable to allocate the descriptor pool">();

                VqCommandPoolCreateInfo poolInfo;
                poolInfo.flags                  = m_cmdPoolCreateFlags;
                
                if(m_graphic.valid()){
                    poolInfo.queueFamilyIndex   = m_graphic.family;
                    if (vkCreateCommandPool(m_device, &poolInfo, nullptr, &p.graphic) != VK_SUCCESS) 
                        throw create_error<"Failed to create a graphic command pool">();
                }
                if(m_compute.valid()){
                    poolInfo.queueFamilyIndex   = m_compute.family;
                    if (vkCreateCommandPool(m_device, &poolInfo, nullptr, &p.compute) != VK_SUCCESS) 
                        throw create_error<"Failed to create a compute command pool">();
                }
                return std::error_code();
            }
            catch(std::error_code ec)
            {
                _destroy(p);
                return ec;
            }
        }
        
        void                        Visualizer::_destroy(ViThread&p)
        {
            if(p.descriptors){
                vkDestroyDescriptorPool(m_device, p.descriptors, nullptr);
                p.descriptors = nullptr;
            }
            if(p.graphic){
                vkDestroyCommandPool(m_device, p.graphic, nullptr);
                p.graphic = nullptr;
            }
            if(p.compute){
                vkDestroyCommandPool(m_device, p.compute, nullptr);
                p.compute = nullptr;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        //  GETTERS/INFORMATION

        RGBA4F Visualizer::clear_color() const
        {
            VkClearValue    cv  = m_clearValue;
            return { 
                cv.color.float32[0], cv.color.float32[1], 
                cv.color.float32[2], cv.color.float32[3] 
            };
        }

        VkCommandBuffer Visualizer::command_buffer() const
        {
            return current_frame().commandBuffer;
        }

        VkCommandPool   Visualizer::command_pool() const
        {
            return m_thread.graphic;
        }

        VkQueue  Visualizer::compute_queue(uint32_t i) const
        {
            return m_compute[i];
        }
        
        uint32_t  Visualizer::compute_queue_count() const
        {
            return (uint32_t) m_compute.queues.size();
        }
        
        uint32_t  Visualizer::compute_queue_family() const
        {
            return m_compute.family;
        }

        bool    Visualizer::compute_queue_valid() const
        {
            return m_compute.valid();
        }

        ViFrame&            Visualizer::current_frame()
        {
            return m_frames[m_tick % MAX_FRAMES_IN_FLIGHT];
        }
        
        const ViFrame&      Visualizer::current_frame() const
        {
            return m_frames[m_tick % MAX_FRAMES_IN_FLIGHT];
        }

        VkDescriptorPool    Visualizer::descriptor_pool() const
        {
            return m_thread.descriptors;
        }
        

        std::string_view    Visualizer::gpu_name() const
        {
            return std::string_view(m_deviceInfo.deviceName, strnlen(m_deviceInfo.deviceName, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE));
        }

        VkPhysicalDeviceType    Visualizer::gpu_type() const
        {
            return m_deviceInfo.deviceType;
        }


        VkQueue     Visualizer::graphic_queue(uint32_t i) const
        {
            return m_graphic[i];
        }
        
        uint32_t    Visualizer::graphic_queue_count() const
        {
            return (uint32_t) m_graphic.queues.size();
        }
        
        uint32_t    Visualizer::graphic_queue_family() const
        {
            return m_graphic.family;
        }
        
        bool        Visualizer::graphic_queue_valid() const
        {
            return m_graphic.valid();
        }

        uint32_t    Visualizer::max_memory_allocation_count() const  
        { 
            return m_deviceInfo.limits.maxMemoryAllocationCount; 
        }
        
        uint32_t    Visualizer::max_push_constants_size() const 
        { 
            return m_deviceInfo.limits.maxPushConstantsSize; 
        }
        
        uint32_t    Visualizer::max_viewports() const 
        { 
            return m_deviceInfo.limits.maxViewports; 
        }

        VkQueue      Visualizer::present_queue(uint32_t i) const
        {
            return m_present[i];
        }
        
        uint32_t     Visualizer::present_queue_count() const
        {
            return (uint32_t) m_present.queues.size();
        }
        
        uint32_t     Visualizer::present_queue_family() const
        {
            return m_present.family;
        }

        bool        Visualizer::present_queue_valid() const
        {
            return m_present.valid();
        }
        
        VkRenderPass Visualizer::render_pass() const
        {
            return m_renderPass;
        }

        bool        Visualizer::supports_surface(VkFormat fmt) const
        {
            for(auto f : m_surfaceFormats)
                if(fmt == f.format)
                    return true;
            return false;
        }
        
        bool        Visualizer::supports_present(PresentMode pm) const
        {
            return m_presentModes.contains(pm);
        }

        Expect<VkSurfaceCapabilitiesKHR>    Visualizer::surface_capabilities() const
        {
            VkSurfaceCapabilitiesKHR    ret;
            if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_physical, m_surface, &ret) != VK_SUCCESS)
                return unexpected<"Unable to get surface capabilities">();
            return ret;
        }

        VkColorSpaceKHR Visualizer::surface_color_space(VkFormat fmt) const
        {
            for(auto& f : m_surfaceFormats)
                if(fmt == f.format)
                    return f.colorSpace;
            return VK_COLOR_SPACE_MAX_ENUM_KHR;
        }

        VkRect2D    Visualizer::swapchain_def_scissor() const
        {
            return m_swapchain.def_scissor();
        }
        
        VkViewport  Visualizer::swapchain_def_viewport() const
        {
            return m_swapchain.def_viewport();
        }

        uint32_t    Visualizer::swapchain_image_count() const
        {
            return m_swapchain.imageCount;
        }

        uint32_t    Visualizer::swapchain_height() const
        {
            return m_swapchain.height();
        }

        uint32_t    Visualizer::swapchain_min_image_count() const
        {
            return m_swapchain.minImageCount;
        }

        uint32_t    Visualizer::swapchain_width() const
        {
            return m_swapchain.width();
        }
                
        VkQueue   Visualizer::video_decode_queue(uint32_t i) const
        {
            return m_videoDecode[i];
        }
        
        uint32_t  Visualizer::video_decode_queue_count() const
        {
            return (uint32_t) m_videoDecode.queues.size();
        }
        
        uint32_t  Visualizer::video_decode_queue_family() const
        {
            return m_videoDecode.family;
        }

        bool        Visualizer::video_decode_queue_valid() const
        {
            return m_videoDecode.valid();
        }

        VkQueue   Visualizer::video_encode_queue(uint32_t i) const
        {
            return m_videoEncode[i];
        }
        
        uint32_t  Visualizer::video_encode_queue_count() const
        {
            return (uint32_t) m_videoEncode.queues.size();
        }

        uint32_t  Visualizer::video_encode_queue_family() const
        {
            return m_videoEncode.family;
        }

        bool        Visualizer::video_encode_queue_valid() const
        {
            return m_videoEncode.valid();
        }

        ////////////////////////////////////////////////////////////////////////////////
        //  SETTERS/MANIPULATORS

        bool        Visualizer::rebuild(bool force)
        {
            if(force){
                m_rebuildSwap   = false;
            } else {
                force       = m_rebuildSwap.exchange(false);
                if(!force)
                    return false;
            }
            
            vkDeviceWaitIdle(m_device);
            ViSwapchain newChain;
            _create(newChain);
            std::swap(newChain, m_swapchain);
            _destroy(newChain);
            return true;
        }

        ViShader    Visualizer::shader(uint64_t i) const
        {
            tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, false);
            auto j = m_shaders.hash.find(i);
            if(j != m_shaders.hash.end())
                return j->second;
            return ViShader();
        }
        
        Expect<ViShader>    Visualizer::shader_create(Ref<const Shader> sh)
        {
            if(!sh)
                return errors::null_pointer();
                
            {
                tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, false);
                auto j = m_shaders.hash.find(sh->id());
                if(j != m_shaders.hash.end())
                    return j->second;
            }
            
            ViShader    p;
            std::error_code ec = _create(p, *sh);
            if(ec)
                return unexpected(ec);
            
            ViShader    ret;
            
            {
                tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, true);
                auto [ j, f]    = m_shaders.hash.emplace(sh->id(), p);
                if(f) [[likely]]
                    return p;

                //  collision
                ret = j->second;
            }

            _destroy(p);
            return ret;
        }

        void        Visualizer::set_clear_color(const RGBA4F&i)
        {
            m_clearValue = VkClearValue{{{ i.red, i.green, i.blue, i.alpha }}};
        }

        void        Visualizer::set_present_mode(PresentMode pm)
        {
            if((pm != m_presentMode) && supports_present(pm)){
                m_presentMode   = pm;
                m_rebuildSwap   = true;
            }
        }

        void        Visualizer::trigger_rebuild()
        {
            m_rebuildSwap       = true;
        }

    }
}
