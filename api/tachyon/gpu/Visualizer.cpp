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

#include <yq/basic/AutoReset.hpp>
#include <0/basic/BasicBuffer.hpp>
#include <yq/basic/ErrorDB.hpp>
#include <yq/basic/errors.hpp>

#include <0/math/color/RGBA.hpp>

#include <tachyon/Buffer.hpp>
#include <tachyon/Image.hpp>
#include <tachyon/Shader.hpp>
#include <tachyon/Texture.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/gpu/ViContext.hpp>
#include <tachyon/gpu/VqApp.hpp>
#include <tachyon/gpu/VqUtils.hpp>
#include <tachyon/Perspective.hpp>
#include <tachyon/Render3D.hpp>
#include <tachyon/Scene.hpp>

#include <tachyon/ImageViewInfo.hpp>
#include <tachyon/Pipeline.hpp>
#include <tachyon/PushData.hpp>

#include <GLFW/glfw3.h>

#define LOCK        tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, false);
#define WLOCK       tbb::spin_rw_mutex::scoped_lock _lock(m_mutex, true);

namespace yq::tachyon {

    namespace errors {
        using namespace yq::errors;
        using INSUFFICIENT_GPU_MEMORY   = error_db::entry<"Insufficient GPU memory for requested operation">;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    
    bool    ViBO::update(Visualizer&viz, const BaseBOConfig&cfg, const void* p)
    {
        do {
            if(!cfg.fetch)
                return false;
            if(p ? (cfg.activity == DataActivity::COMMON) : (cfg.activity != DataActivity::COMMON))
                return false;
            if(!buffer)                                 // LOAD
                break;
            if(cfg.activity != DataActivity::DYNAMIC)   // LOAD
                break;
            if(!cfg.revision)
                return false;
            
            uint64_t    n   = cfg.revision(p);
            if(n == rev)
                return false;
            rev    = n;
        } while(false);
        
        BufferCPtr      c   = cfg.fetch(p);
        if(!c){     //  shouldn't really happen....
            yWarning() << "EMPTY BUFFER DETECTED!";
            return false;
        }
        
        Expect<ViBuffer> xvb    = viz.create(*c);
        if(xvb){
            const ViBuffer& vb  = *xvb;
            if(vb.buffer){
                buffer  = vb.buffer;
                count   = c->memory.count();
                return true;
            }
        }
        
        return false;
    }

    bool    ViTO::update(Visualizer&viz, const TexConfig&cfg, const void*p)
    {
        do {
            if(!cfg.fetch)
                return false;
            if(p ? (cfg.activity == DataActivity::COMMON) : (cfg.activity != DataActivity::COMMON))
                return false;
            if(!view || !sampler)                                 // LOAD
                break;
            if(cfg.activity != DataActivity::DYNAMIC)   // LOAD
                break;
            if(!cfg.revision)
                return false;
            
            uint64_t    n   = cfg.revision(p);
            if(n == rev)
                return false;
            rev    = n;
        } while(false);
        
        TextureCPtr      c   = cfg.fetch(p);
        if(!c){     //  shouldn't really happen....
            yWarning() << "EMPTY TEXTURE DETECTED!";
            return false;
        }
        
        Expect<ViTexture> xvb    = viz.create(*c);
        if(xvb){
            const ViTexture& vb  = *xvb;
            if(vb.view && vb.sampler){
                view    = vb.view;
                sampler = vb.sampler;
                return true;
            }
        }
        
        return false;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //  ViBuffer
    ////////////////////////////////////////////////////////////////////////////////

    std::error_code     ViBuffer::allocate(Visualizer&viz, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        if(!cb)
            return create_error<"Skipping zero sized buffer">();
        
        VqBufferCreateInfo  bufferInfo;
        bufferInfo.size         = cb;
        bufferInfo.usage        = buf & VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM;
        
        VmaAllocationCreateInfo vmaallocInfo = {};
        vmaallocInfo.usage = vmu;
        VmaAllocationInfo   vai;
        if(vmaCreateBuffer(viz.allocator(), &bufferInfo, &vmaallocInfo, &buffer, &allocation, &vai) != VK_SUCCESS)
            return errors::INSUFFICIENT_GPU_MEMORY();
        return std::error_code();
    }
    
    std::error_code     ViBuffer::create(Visualizer&viz, const Memory& v, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        std::error_code     ec  = allocate(viz, v.bytes(), buf, vmu);
        if(ec)
            return ec;
        
        void* dst = nullptr;
        vmaMapMemory(viz.allocator(), allocation, &dst);
        memcpy(dst, v.data(), v.bytes());
        vmaUnmapMemory(viz.allocator(), allocation);
        return std::error_code();
    }
    
    std::error_code     ViBuffer::create(Visualizer&viz, const Buffer& v)
    {
        return create(viz, v.memory, (VkBufferUsageFlags) v.usage.value(), VMA_MEMORY_USAGE_CPU_TO_GPU);
    }
    
    void                ViBuffer::destroy(Visualizer&viz)
    {
        if(allocation && buffer){
            vmaDestroyBuffer(viz.allocator(), buffer, allocation);
            allocation = nullptr;
            buffer = nullptr;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    //  ViContext
    ////////////////////////////////////////////////////////////////////////////////

    ViContext::ViContext() = default;
    ViContext::~ViContext() = default;

    ////////////////////////////////////////////////////////////////////////////////
    //  ViFrame
    ////////////////////////////////////////////////////////////////////////////////

    namespace {
        uint32_t    nextFrameId()
        {
            static std::atomic<uint32_t>    s_ret{0};
            return ++s_ret;
        }
    }

    ViFrame::ViFrame(Visualizer&viz) : m_viz(viz), m_id(nextFrameId())
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
    
    ViFrame::~ViFrame()
    {
        _dtor();
    }

    void    ViFrame::_ctor()
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
    }
    
    void                ViFrame::_dtor()
    {
        for(auto& i : m_rendereds){
            if(i.second)
                delete i.second;
        }
        m_rendereds.clear();

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
    
    
    ViRendered*         ViFrame::create(const Rendered&obj, const Pipeline& pipe)
    {
        {
            LOCK
            auto eq = m_rendereds.equal_range(obj.id());
            for(auto i = eq.first; i != eq.second; ++i){
                if(i->second->m_pipe.m_id == pipe.id())
                    return i->second;
            }
        }

        const ViPipeline*   vp   = m_viz.create(pipe);
        if(!vp)
            return nullptr;
        
        ViRendered* p   = new ViRendered(m_viz, *vp, obj);
        ViRendered* ret = nullptr;
        
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
    
    const ViRendered*   ViFrame::lookup(const Rendered&ren, const Pipeline& pipe) const
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

    ////////////////////////////////////////////////////////////////////////////////
    //  ViImage
    ////////////////////////////////////////////////////////////////////////////////

    std::error_code     ViImage::create(Visualizer&viz, const Image&img)
    {
        ViBuffer        local;
        
        std::error_code ec  = local.create(viz, img.memory, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VMA_MEMORY_USAGE_CPU_ONLY);
        if(ec)
            return ec;
        
        try {
            VqImageCreateInfo   imgInfo;
            imgInfo.imageType       = (VkImageType) img.info.type.value();
            imgInfo.extent.width    = (uint32_t) img.info.size.x;
            imgInfo.extent.height   = (uint32_t) img.info.size.y;
            imgInfo.extent.depth    = (uint32_t) img.info.size.z;
            imgInfo.mipLevels       = img.info.mipLevels;
            imgInfo.arrayLayers     = img.info.arrayLayers;
            imgInfo.samples         = VK_SAMPLE_COUNT_1_BIT;
            imgInfo.format          = (VkFormat) img.info.format.value();
            imgInfo.usage           = VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
            imgInfo.tiling          = (VkImageTiling) img.info.tiling.value();
            imgInfo.sharingMode     = VK_SHARING_MODE_EXCLUSIVE;
           
            VmaAllocationCreateInfo diai  = {};
            diai.usage    = VMA_MEMORY_USAGE_GPU_ONLY;
            
            if(vmaCreateImage(viz.allocator(), &imgInfo, &diai, &image, &allocation, nullptr) != VK_SUCCESS)
                return (std::error_code) errors::INSUFFICIENT_GPU_MEMORY();
                
            ec = viz.upload([&](VkCommandBuffer cmd){
                VkImageSubresourceRange range;
                range.aspectMask    = VK_IMAGE_ASPECT_COLOR_BIT;
                range.baseMipLevel = 0;
                range.levelCount = 1;
                range.baseArrayLayer = 0;
                range.layerCount = 1;
                
                VqImageMemoryBarrier imb;
                imb.oldLayout           = VK_IMAGE_LAYOUT_UNDEFINED;
                imb.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                imb.image               = image;
                imb.subresourceRange    = range;
                imb.srcAccessMask       = 0;
                imb.dstAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
                
                vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, nullptr, 0, nullptr, 1, &imb);

                VkBufferImageCopy creg = {};
                creg.bufferOffset = 0;
                creg.bufferRowLength = 0;
                creg.bufferImageHeight = 0;

                creg.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
                creg.imageSubresource.mipLevel = 0;
                creg.imageSubresource.baseArrayLayer = 0;
                creg.imageSubresource.layerCount = 1;
                creg.imageExtent = imgInfo.extent;

                //copy the buffer into the image
                vkCmdCopyBufferToImage(cmd, local.buffer, image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &creg);

                VkImageMemoryBarrier imb2 = imb;

                imb2.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                imb2.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

                imb2.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
                imb2.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;

                //barrier the image into the shader readable layout
                vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, nullptr, 0, nullptr, 1, &imb2);
            });
        }
        catch(std::error_code ec2)
        {
            ec  = ec2;
        }
        local.destroy(viz);
        return ec;
    }
    
    void                ViImage::destroy(Visualizer&viz)
    {
        if(image && allocation){
            vmaDestroyImage(viz.allocator(), image, allocation);
            image         = nullptr;
            allocation    = nullptr;
        }
    }


    ////////////////////////////////////////////////////////////////////////////////
    //  ViPipeline
    ////////////////////////////////////////////////////////////////////////////////

    ViPipeline::ViPipeline(Visualizer&viz, const Pipeline&p) : m_viz(viz), m_id(p.id()), m_cfg(p.config())
    {
    }
    
    ViPipeline::~ViPipeline()
    {
        _dtor();
    }
    
    std::error_code         ViPipeline::_ctor()
    {
        try {
            std::vector<VkPipelineShaderStageCreateInfo>    stages;
            m_shaders           = 0;
            for(auto& s : m_cfg.shaders){
                Ref<const Shader>   sh  = Shader::decode(s);
                if(!sh)
                    continue;
                
                Expect<ViShader>    xvs = m_viz.create(*sh);
                if(!xvs)
                    continue;
                
                const ViShader&     ssh = *xvs;
                
                VqPipelineShaderStageCreateInfo stage;
                stage.stage     = ssh.mask;
                stage.pName     = "main";
                stage.module    = ssh.shader;
                stages.push_back(stage);

                m_shaders      |= ssh.mask;
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
                    ViBO        bo;
                    bo.update(m_viz, vb, nullptr);
                    m_vbos.push_back(bo);
                }
            }
            
            if(!m_cfg.ibos.empty()){
                for(auto & ib : m_cfg.ibos){
                    ViBO        bo;
                    bo.update(m_viz, ib, nullptr);
                    m_ibos.push_back(bo);
                }
            }

            if(!m_cfg.ubos.empty()){
                for(auto & ub : m_cfg.ubos){
                    ViBO        bo;
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
    
    void                    ViPipeline::_dtor()
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

    ////////////////////////////////////////////////////////////////////////////////
    //  ViQueues
    ////////////////////////////////////////////////////////////////////////////////
    
    namespace {
        size_t          count(const ViQueueSpec& qs)
        {
            if( std::get_if<std::monostate>(&qs) != nullptr)
                return 0;
            if(const std::vector<float>*p = std::get_if<std::vector<float>>(&qs))
                return p->size();
            if(const uint32_t* p = std::get_if<uint32_t>(&qs))  
                return *p;
            if(const bool* p = std::get_if<bool>(&qs))
                return *p ? 1 : 0;
            return 0;
        }

        bool            is_empty(const ViQueueSpec& qs)
        {
            if( std::get_if<std::monostate>(&qs) != nullptr)
                return true;
            if(const std::vector<float>*p = std::get_if<std::vector<float>>(&qs))
                return p->empty();
            if(const uint32_t* p = std::get_if<uint32_t>(&qs))
                return *p == 0;
            if(const bool* p = std::get_if<bool>(&qs))
                return !*p;
            return true;
        }

        const ViQueueSpec&   biggest(const ViewerCreateInfo& vci, Flags<QueueType> which)
        {
            size_t  g       = 0;
            size_t  c       = 0;
            size_t  p       = 0;
            size_t  ve      = 0;
            size_t  vd      = 0;
            size_t  mx     = 0;
            
            if(which.is_set(QueueType::Graphic)){
                mx  = g   = std::max((size_t) 1,count(vci.graphic));
            }
            if(which.is_set(QueueType::Present)){
                p   = std::max((size_t) 1,count(vci.present));
                mx  = std::max(p,mx);
            };
            if(which.is_set(QueueType::Compute)){
                c   = count(vci.compute);
                mx  = std::max(c,mx);
            }
            if(which.is_set(QueueType::VideoEncode)){
                ve  = count(vci.video_encode);
                mx  = std::max(ve,mx);
            }
            if(which.is_set(QueueType::VideoDecode)){
                vd  = count(vci.video_decode);
                mx  = std::max(vd,mx);
            }
            
            if(g==mx)
                return vci.graphic;
            if(p==mx)
                return vci.present;
            if(c==mx)
                return vci.compute;
            if(vd==mx)
                return vci.video_decode;
            if(ve==mx)
                return vci.video_encode;
            throw create_error<"No queues remaining">();
        }
    }

    ViQueues::ViQueues(Visualizer&viz, const ViewerCreateInfo& vci, uint32_t fi, const VkQueueFamilyProperties&prop, Flags<QueueType> left) :
        m_viz(viz), m_family(fi)
    {
        m_availableQueueCount           = prop.queueCount;
        m_timestampValidBits            = prop.timestampValidBits;
        m_minImageTransferGranularity   = prop.minImageTransferGranularity;
        m_vkFlags                       = prop.queueFlags;

        if(left.is_set(QueueType::Graphic) && (m_vkFlags & VK_QUEUE_GRAPHICS_BIT))
            m_type.set(QueueType::Graphic);
        if(left.is_set(QueueType::Compute) && (m_vkFlags & VK_QUEUE_COMPUTE_BIT))
            m_type.set(QueueType::Compute);
        if(left.is_set(QueueType::VideoEncode) && (m_vkFlags & VK_QUEUE_VIDEO_ENCODE_BIT_KHR))
            m_type.set(QueueType::VideoEncode);
        if(left.is_set(QueueType::VideoDecode) && (m_vkFlags & VK_QUEUE_VIDEO_DECODE_BIT_KHR))
            m_type.set(QueueType::VideoDecode);
        if(left.is_set(QueueType::Present)){
            VkBool32 presentSupport = false;
            vkGetPhysicalDeviceSurfaceSupportKHR(viz.physical(), fi, viz.surface(), &presentSupport);
            if(presentSupport)
                m_type.set(QueueType::Present);
        }
        
        const ViQueueSpec&  spec    = biggest(vci, m_type);
        if(const std::vector<float>*p = std::get_if<std::vector<float>>(&spec)){
            if(!p->empty())
                m_weights   = *p;
        }
        if(const uint32_t* p = std::get_if<uint32_t>(&spec))
            m_weights.resize(*p, 1.);
        if(m_weights.empty())
            m_weights.push_back(1.);
        m_queues.resize(m_weights.size(), nullptr);
    }
    
    ViQueues::~ViQueues()
    {
    }
    
    VkDeviceQueueCreateInfo ViQueues::info()
    {
        VqDeviceQueueCreateInfo  ret;
        ret.queueFamilyIndex   = m_family;
        ret.queueCount         = (uint32_t) m_weights.size();
        ret.pQueuePriorities   = m_weights.data();
        return ret;
    }

    void        ViQueues::init()
    {
        if(m_queues.size() != m_weights.size())
            throw create_error<"Queues size does not match weight sizes">();
        for(uint32_t i=0;i<m_queues.size();++i)
            vkGetDeviceQueue(m_viz.device(), m_family, i, &m_queues[i]);
    }
    
    VkQueue     ViQueues::queue(uint32_t i) const
    {
        if(i<m_queues.size()) [[likely]]
            return m_queues[i];
        return nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //  ViRendered
    ////////////////////////////////////////////////////////////////////////////////

    ViRendered::ViRendered(Visualizer&_viz, const ViPipeline& _pipe, const Rendered& _obj) : m_viz(_viz), m_pipe(_pipe), m_object(_obj)
    {
        _ctor();
    }
    
    ViRendered::~ViRendered()
    {
        _dtor();
    }

    std::error_code     ViRendered::_ctor()
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
            std::vector<VkDescriptorSetLayout>      layouts(ds, m_pipe.m_descriptors);    // TODO efficiency is to push this into ViPipeline
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
    
    void                ViRendered::_dtor()
    {
    }

    void    ViRendered::_ubo(size_t i)
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

    void    ViRendered::_tex(size_t i)
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

    void                ViRendered::descriptors(ViContext& u)
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
 
    void                ViRendered::update(ViContext& u)
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
                push->matrix    = u.world2eye() * r3->model2world();
                break;
            }
            [[fallthrough]];
        case PushConfigType::View:
            push->matrix = u.world2eye();
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

    void                ViRendered::record(ViContext&u)
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
    
    ////////////////////////////////////////////////////////////////////////////////
    //  ViRenderPass
    ////////////////////////////////////////////////////////////////////////////////

    ViRenderPass::ViRenderPass(Visualizer&viz) : m_viz(viz)
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
    
    ViRenderPass::~ViRenderPass()
    {
        _dtor();
    }

    void    ViRenderPass::_ctor()
    {
        if(m_renderPass)
            throw create_error<"Render pass already initialized">();
    
        VkAttachmentDescription colorAttachment{};
        colorAttachment.format          = m_viz.surface_format();
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

        if (vkCreateRenderPass(m_viz.device(), &renderPassInfo, nullptr, &m_renderPass) != VK_SUCCESS) 
            throw create_error<"Unable to create the render pass">();
    }
    
    void    ViRenderPass::_dtor()
    {
        if(m_renderPass){
            vkDestroyRenderPass(m_viz.device(), m_renderPass, nullptr);
            m_renderPass    = nullptr;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    //  ViShader
    ////////////////////////////////////////////////////////////////////////////////

    std::error_code     ViShader::create(VkDevice dev, const Shader& sh)
    {
        mask  = VkShaderStageFlagBits{};
        switch(sh.type){
        case ShaderType::VERT:
            mask    = VK_SHADER_STAGE_VERTEX_BIT;
            break;
        case ShaderType::TESC:
            mask    = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
            break;
        case ShaderType::TESE:
            mask    = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
            break;
        case ShaderType::FRAG:
            mask    = VK_SHADER_STAGE_FRAGMENT_BIT;
            break;
        case ShaderType::GEOM:
            mask    = VK_SHADER_STAGE_GEOMETRY_BIT;
            break;
        case ShaderType::COMP:
            mask    = VK_SHADER_STAGE_COMPUTE_BIT;
            break;
        default:
            return create_error<"Shader needs a valid/supported type!">();
        }
            
        VqShaderModuleCreateInfo createInfo;
        createInfo.codeSize = sh.payload.bytes();
        createInfo.pCode    = reinterpret_cast<const uint32_t*>(sh.payload.data());
        if (vkCreateShaderModule(dev, &createInfo, nullptr, &shader) != VK_SUCCESS) {
            shader  = nullptr;
            return create_error<"Shader creation failed">();
        }
        return std::error_code();
    }
    
    void                ViShader::destroy(VkDevice dev)
    {
        if(shader){
            vkDestroyShaderModule(dev, shader, nullptr);
            shader  = nullptr;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    //  ViSwapchain
    ////////////////////////////////////////////////////////////////////////////////

    ViSwapchain::ViSwapchain(Visualizer&viz, const ViRenderPass&rp, const ViSwapchain*old) : m_viz(viz)
    {
        try {
            _ctor(rp, old);
        }
        catch(std::error_code ec)
        {
            _dtor();
            throw;
        }
    }
    
    ViSwapchain::~ViSwapchain()
    {
        _dtor();
    }
    
    void    ViSwapchain::_ctor(const ViRenderPass& rp, const ViSwapchain* old)
    {
        if(m_swapchain)
            throw create_error<"Swapchain is already initialized">();
    
        if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_viz.physical(), m_viz.surface(), &m_capabilities) != VK_SUCCESS)
            throw create_error<"Unable to get surface capabilities">();
        if (m_capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
            m_extents = m_capabilities.currentExtent;
        } else {
            int w, h;
            glfwGetFramebufferSize(m_viz._window(), &w, &h);
            m_extents = {};
            m_extents.width  = std::clamp((uint32_t) w, m_capabilities.minImageExtent.width, m_capabilities.maxImageExtent.width);
            m_extents.height = std::clamp((uint32_t) h, m_capabilities.minImageExtent.height, m_capabilities.maxImageExtent.height);
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

        m_minImageCount             = m_capabilities.minImageCount;
        if(m_minImageCount < 2)
            m_minImageCount   = 2;
        m_imageCount                  = m_minImageCount + 1;
        if (m_capabilities.maxImageCount > 0 && m_imageCount > m_capabilities.maxImageCount) {
            m_imageCount = m_capabilities.maxImageCount;
        }

        VqSwapchainCreateInfoKHR    swapInfo;
        swapInfo.surface          = m_viz.surface();
        swapInfo.minImageCount    = m_imageCount;
        swapInfo.imageFormat      = m_viz.surface_format();
        swapInfo.imageColorSpace  = m_viz.surface_color_space();
        swapInfo.imageExtent      = m_extents;
        swapInfo.imageArrayLayers = 1;    // we're not steroscopic (YET)  <-- OCULUS HERE
        swapInfo.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        
        uint32_t queueFamilyIndices[] = {m_viz.graphic_queue_family(), m_viz.present_queue_family()};
        if (m_viz.graphic_queue_family() != m_viz.present_queue_family()) {
            swapInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
            swapInfo.queueFamilyIndexCount = 2;
            swapInfo.pQueueFamilyIndices = queueFamilyIndices;
        } else {
            swapInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
            swapInfo.queueFamilyIndexCount = 0; // Optional
            swapInfo.pQueueFamilyIndices = nullptr; // Optional
        }        
        swapInfo.preTransform     = m_capabilities.currentTransform;
        swapInfo.compositeAlpha   = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        swapInfo.presentMode      = (VkPresentModeKHR) m_viz.present_mode().value();
        swapInfo.clipped          = VK_TRUE;
        
        if(old)
            swapInfo.oldSwapchain   = old -> m_swapchain;
            
        if (vkCreateSwapchainKHR(m_viz.device(), &swapInfo, nullptr, &m_swapchain) != VK_SUCCESS)
            throw create_error<"Failed to create the swapchain">();

        if(vkGetSwapchainImagesKHR(m_viz.device(), m_swapchain, &m_imageCount, nullptr) != VK_SUCCESS)
            throw create_error<"Unable to get swapchain image count">();
        
        m_images.resize(m_imageCount, nullptr);
        if(vkGetSwapchainImagesKHR(m_viz.device(), m_swapchain, &m_imageCount, m_images.data()) != VK_SUCCESS)
            throw create_error<"Unable to get swapchain images">();
                        
        m_imageViews.resize(m_imageCount, nullptr);

        VkImageViewCreateInfo       imageViewInfo = vqCreateInfo(ImageViewInfo());
        imageViewInfo.format       = m_viz.surface_format();
        
        for(size_t i=0; i<m_imageCount; ++i){
            imageViewInfo.image        = m_images[i];
            if(vkCreateImageView(m_viz.device(), &imageViewInfo, nullptr, &m_imageViews[i]) != VK_SUCCESS) 
                throw create_error<"Unable to create a swapchain image viewer">();
        }                
        
        m_frameBuffers.resize(m_imageCount, nullptr);

        VqFramebufferCreateInfo   frameBufferInfo;
        frameBufferInfo.renderPass       = rp.m_renderPass;
        frameBufferInfo.attachmentCount  = 1;
        frameBufferInfo.width            = m_extents.width;
        frameBufferInfo.height           = m_extents.height;
        frameBufferInfo.layers           = 1;

        for(size_t i=0;i<m_imageCount;++i){
            frameBufferInfo.pAttachments = &m_imageViews[i];
            if (vkCreateFramebuffer(m_viz.device(), &frameBufferInfo, nullptr, &m_frameBuffers[i]) != VK_SUCCESS) 
                throw create_error<"Failed to create a swapchain framebuffer">();
        }
    }
    
    void            ViSwapchain::_dtor()
    {
        for(size_t i=0;i<m_imageCount;++i){
            if((i < m_frameBuffers.size()) && m_frameBuffers[i])
                vkDestroyFramebuffer(m_viz.device(), m_frameBuffers[i], nullptr);
            if((i < m_imageViews.size()) && m_imageViews[i])
                vkDestroyImageView(m_viz.device(), m_imageViews[i], nullptr);
        }
        m_frameBuffers.clear();
        m_imageViews.clear();
        m_images.clear();
        if(m_swapchain){
            vkDestroySwapchainKHR(m_viz.device(), m_swapchain, nullptr);
            m_swapchain  = nullptr;
        }
    }

    VkRect2D  ViSwapchain::def_scissor() const
    {
        VkRect2D    ret{};
        ret.offset  = { 0, 0 };
        ret.extent  = m_extents;
        return ret;
    }
    
    VkViewport  ViSwapchain::def_viewport() const
    {
        VkViewport  ret{};
        ret.x = 0.0f;
        ret.y = 0.0f;
        ret.width = (float) m_extents.width;
        ret.height = (float) m_extents.height;
        ret.minDepth = 0.0f;
        ret.maxDepth = 1.0f;
        return ret;
    }
    
    uint32_t  ViSwapchain::width() const 
    { 
        return m_extents.width; 
    }
    
    uint32_t  ViSwapchain::height() const 
    { 
        return m_extents.height; 
    }

    ////////////////////////////////////////////////////////////////////////////////
    //  ViThread
    ////////////////////////////////////////////////////////////////////////////////
    
    ViThread::ViThread(Visualizer&viz) : m_viz(viz)
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
    
    ViThread::~ViThread()
    {
        _dtor();
    }
    
    void    ViThread::_ctor()
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
            if (vkCreateCommandPool(m_viz.device(), &poolInfo, nullptr, &m_graphic) != VK_SUCCESS) 
                throw create_error<"Failed to create a graphic command pool">();
        }
        if(m_viz.compute_queue_valid()){
            poolInfo.queueFamilyIndex   = m_viz.compute_queue_family();
            if (vkCreateCommandPool(m_viz.device(), &poolInfo, nullptr, &m_compute) != VK_SUCCESS) 
                throw create_error<"Failed to create a compute command pool">();
        }
    }
    
    void    ViThread::_dtor()
    {
        if(m_descriptors){
            vkDestroyDescriptorPool(m_viz.device(), m_descriptors, nullptr);
            m_descriptors = nullptr;
        }
        if(m_graphic){
            vkDestroyCommandPool(m_viz.device(), m_graphic, nullptr);
            m_graphic = nullptr;
        }
        if(m_compute){
            vkDestroyCommandPool(m_viz.device(), m_compute, nullptr);
            m_compute = nullptr;
        }
    }
    

    ////////////////////////////////////////////////////////////////////////////////
    //  ViUpload
    ////////////////////////////////////////////////////////////////////////////////

    ViUpload::ViUpload(Visualizer&viz, const ViQueues&qu) : m_viz(viz)
    {
        try {
            _ctor(qu);
        }
        catch(std::error_code ec)
        {
            _dtor();
            throw;
        }
    }
    
    ViUpload::~ViUpload()
    {
        _dtor();
    }
    
    void    ViUpload::_ctor(const ViQueues&qu)
    {
        if(m_fence)
            throw create_error<"Upload already initialized">();
            
        if(qu.m_queues.empty())
            throw create_error<"Queues has no queues">();
    
        m_queue                         = qu.queue(0);
        VqCommandPoolCreateInfo poolInfo;
        poolInfo.queueFamilyIndex       = qu.m_family;
        if (vkCreateCommandPool(m_viz.device(), &poolInfo, nullptr, &m_pool) != VK_SUCCESS) 
            throw create_error<"Failed to create an upload command pool">();
            
        VqCommandBufferAllocateInfo allocInfo;
        allocInfo.commandPool           = m_pool;
        allocInfo.level                 = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandBufferCount    = 1;
        if (vkAllocateCommandBuffers(m_viz.device(), &allocInfo, &m_commandBuffer) != VK_SUCCESS) 
            throw create_error<"Failed to allocate command buffers">();
            
        VqFenceCreateInfo   fci;
        if(vkCreateFence(m_viz.device(), &fci, nullptr,  &m_fence) != VK_SUCCESS)
            throw create_error<"Unable to create fence">();
    }
    
    void    ViUpload::_dtor()
    {
        if(m_fence){
            vkDestroyFence(m_viz.device(), m_fence, nullptr);
            m_fence   = nullptr;
        }

        if(m_commandBuffer && m_pool){
            vkFreeCommandBuffers(m_viz.device(), m_pool, 1, &m_commandBuffer);
            m_commandBuffer    = nullptr;
        }

        if(m_pool){
            vkDestroyCommandPool(m_viz.device(), m_pool, nullptr);
            m_pool      = nullptr;
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
        
        vkGetPhysicalDeviceFeatures(m_physical, &m_deviceFeatures);
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

            //  And we need to create them... so request
        std::vector<VkDeviceQueueCreateInfo> qci;
        
        Flags<QueueType>        wantQueue({QueueType::Graphic, QueueType::Present});
        Flags<QueueType>        hasQueue{};

        if(!is_empty(vci.compute)){
        yInfo() << " Want compute queue with " << count(vci.compute) << " queues";
            wantQueue.set(QueueType::Compute);
        }
        if(!is_empty(vci.video_decode))
            wantQueue.set(QueueType::VideoDecode);
        if(!is_empty(vci.video_encode))
            wantQueue.set(QueueType::VideoEncode);
        
        std::vector<VkQueueFamilyProperties> qfp = vqGetPhysicalDeviceQueueFamilyProperties(m_physical);
        for(uint32_t i=0;i<qfp.size();++i){
            if(wantQueue == hasQueue)
                break;
            Ref<ViQueues>   r   = new ViQueues(*this, vci, i, qfp[i], wantQueue & ~hasQueue );
            hasQueue |= r->m_type;
            if(r->m_type.is_set(QueueType::Graphic)){
            yInfo() << "Discovered graphics queue " << i;
                m_graphic       = r.ptr();
            }
            if(r->m_type.is_set(QueueType::Compute)){
            yInfo() << "Discovered compute queue " << i;
                m_compute       = r.ptr();
            }
            if(r->m_type.is_set(QueueType::VideoEncode)){
            yInfo() << "Discovered video encode queue " << i;
                m_videoEncode   = r.ptr();
            }
            if(r->m_type.is_set(QueueType::VideoDecode)){
            yInfo() << "Discovered video decode queue " << i;
                m_videoDecode   = r.ptr();
            }
            if(r->m_type.is_set(QueueType::Present)){
            yInfo() << "Discovered present queue " << i;
                m_present       = r.ptr();
            }
            qci.push_back(r->info());
            m_queues.push_back(r);
        }
        
        if(!m_graphic)
            return create_error<"Missing graphic queue">();
        if(!m_present)
            return create_error<"Missing present queue">();
        if(wantQueue.is_set(QueueType::Compute) && !m_compute)
            return create_error<"Missing compute queue">();
        if(wantQueue.is_set(QueueType::VideoEncode) && !m_videoEncode)
            return create_error<"Missing video encode queue">();
        if(wantQueue.is_set(QueueType::VideoDecode) && !m_videoDecode)
            return create_error<"Missing video decode queue">();
        
                
        //  And with that, we have the queues all lined up, ready to be created.

        VkPhysicalDeviceFeatures    gpu_features{};
        if(vci.fill_non_solid)
            gpu_features.fillModeNonSolid    = VK_TRUE;
        gpu_features.samplerAnisotropy          = VK_TRUE;

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

        for(auto& r : m_queues)
            r->init();

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

        m_thread            = std::make_unique<ViThread>(*this);


        //  ================================
        //  UPLOAD
        m_upload            = std::make_unique<ViUpload>(*this, *m_graphic);

        //  ================================
        //  RENDER PASS

        m_renderPass        = std::make_unique<ViRenderPass>(*this);

        //  ================================
        //  PRESENT MODE

        m_presentMode               = m_presentModes.contains(vci.pmode) ? vci.pmode : PresentMode{ PresentMode::Fifo };


        m_frames.reserve(vci.frames_in_flight);
        for(size_t i=0;i<vci.frames_in_flight;++i)
            m_frames.push_back(std::make_unique<ViFrame>(*this));

        set_clear_color(vci.clear);

        m_swapchain = std::make_unique<ViSwapchain>(*this, *m_renderPass);
            
        return std::error_code();
    }
    
    void                        Visualizer::_dtor()
    {
        m_swapchain     = {};
        m_frames.clear();
        
        m_renderPass    = {};

        m_upload        = {};
        m_thread        = {};
    
        for(auto& p : m_pipelines){
            if(p.second)
                delete p.second;
        }
        m_pipelines.clear();
        
        for(auto& tex : m_textures)
            _destroy(tex.second);
        for(auto& img : m_images)
            img.second.destroy(*this);
        m_images.clear();
    
        //  At *this* point, we don't need the mutex... we're dying anyways
        for(auto& psh : m_shaders)
            psh.second.destroy(m_device);
        m_shaders.clear();
        
        if(m_allocator){
            for(auto& b : m_buffers)
                b.second.destroy(*this);
            m_buffers.clear();
            vmaDestroyAllocator(m_allocator);
            m_allocator = nullptr;
        }
    
        //  Generally in reverse order of above
        if(m_device){
            vkDestroyDevice(m_device, nullptr);
            m_device                = nullptr;
        }
        m_graphic                   = nullptr;
        m_present                   = nullptr;
        m_compute                   = nullptr;
        m_videoEncode               = nullptr;
        m_videoDecode               = nullptr;
        m_queues.clear();

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
    
    std::error_code             Visualizer::_create(ViTexture&p, const ViImage& img, const Texture&tex)
    {
        std::error_code ec;
    
        try {
            VkImageViewCreateInfo   ivci = vqCreateInfo(tex.view);
            ivci.format     = (VkFormat) tex.image->info.format.value(); 
            ivci.image      = img.image;
            
            if(vkCreateImageView(m_device, &ivci, nullptr, &p.view) != VK_SUCCESS)
                throw create_error<"Unable to create image view">();
            
            VkSamplerCreateInfo sci = vqCreateInfo(tex.sampler);
            sci.anisotropyEnable        = VK_TRUE;
            sci.maxAnisotropy           = m_deviceInfo.limits.maxSamplerAnisotropy;
            
            if(vkCreateSampler(m_device, &sci, nullptr, &p.sampler) != VK_SUCCESS)
                throw create_error<"Unable to create sampler">();
            return std::error_code();
        } 
        catch(std::error_code ec2){
            ec  = ec2;
        }
        
        _destroy(p);
        return ec;
    }
    
    void                        Visualizer::_destroy(ViTexture&p)
    {
        if(p.sampler){
            vkDestroySampler(m_device, p.sampler, nullptr);
            p.sampler   = nullptr;
        }
        
        if(p.view){
            vkDestroyImageView(m_device, p.view, nullptr);
            p.view = nullptr;
        }
    }
        



    ////////////////////////////////////////////////////////////////////////////////
    //  GETTERS/INFORMATION

    Expect<ViBuffer> Visualizer::buffer(uint64_t i) const
    {
        {
            LOCK
            auto j = m_buffers.find(i);
            if(j != m_buffers.end())
                return j->second;
        }
        
        return unexpected<"Unable to located specified buffer">();
    }

    RGBA4F Visualizer::clear_color() const
    {
        VkClearValue    cv;
        {
            LOCK
            cv = m_clearValue;
        }
        return vqExtractRGBA4F(cv);
    }

    VkCommandBuffer Visualizer::command_buffer() const
    {
        return current_frame().m_commandBuffer;
    }

    VkCommandPool   Visualizer::command_pool() const
    {
        return m_thread->m_graphic;
    }

    VkQueue  Visualizer::compute_queue(uint32_t i) const
    {
        return m_compute ? m_compute->queue(i) : nullptr;
    }
    
    uint32_t  Visualizer::compute_queue_count() const
    {
        return m_compute ? (uint32_t) m_compute->m_queues.size() : 0;
    }
    
    uint32_t  Visualizer::compute_queue_family() const
    {
        return m_compute ? m_compute->m_family : UINT32_MAX;
    }

    bool    Visualizer::compute_queue_valid() const
    {
        return m_compute != nullptr;
    }

    ViFrame&            Visualizer::current_frame()
    {
        return *(m_frames[m_tick % m_frames.size()]);
    }
    
    const ViFrame&      Visualizer::current_frame() const
    {
        return const_cast<Visualizer*>(this)->current_frame();
    }

    VkDescriptorPool    Visualizer::descriptor_pool() const
    {
        return m_thread->m_descriptors;
    }

    Expect<VkFormat>    Visualizer::find_depth_format() const
    {
        return find_supported_format(
            {VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT}, 
            VK_IMAGE_TILING_OPTIMAL,
            VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT
        );
    }

    Expect<VkFormat>    Visualizer::find_supported_format(std::initializer_list<VkFormat> candidates, VkImageTiling tiling, VkFormatFeatureFlags features) const
    {
        return find_supported_format(span(candidates), tiling, features);
    }
    
    Expect<VkFormat>    Visualizer::find_supported_format(std::span<const VkFormat> candidates, VkImageTiling tiling, VkFormatFeatureFlags features) const
    {
        for(VkFormat format : candidates){
            VkFormatProperties props;
            vkGetPhysicalDeviceFormatProperties(m_physical, format, &props);
            
            switch(tiling){
            case VK_IMAGE_TILING_LINEAR:
                if((props.linearTilingFeatures & features) == features)
                    return format;
                break;
            case VK_IMAGE_TILING_OPTIMAL:
                if((props.optimalTilingFeatures & features) == features)
                    return format;
                break;
            default:
                break;
            }            
        }
        
        return unexpected<"Failed to find supported format">();
    }

    
    ViFrame&            Visualizer::frame(int32_t i)
    {
        uint64_t    tick    = (uint64_t)((int64_t) m_tick + i);
        return *(m_frames[tick % m_frames.size() ]);
    }
    
    const ViFrame&      Visualizer::frame(int32_t i) const
    {
        return const_cast<Visualizer*>(this)->frame(i);
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
        return m_graphic ? m_graphic->queue(i) : nullptr;
    }
    
    uint32_t    Visualizer::graphic_queue_count() const
    {
        return m_graphic ? (uint32_t) m_graphic->m_queues.size() : 0;
    }
    
    uint32_t    Visualizer::graphic_queue_family() const
    {
        return m_graphic ? m_graphic->m_family : UINT32_MAX;
    }
    
    bool        Visualizer::graphic_queue_valid() const
    {
        return m_graphic != nullptr;
    }

    Expect<ViImage> Visualizer::image(uint64_t i) const
    {
        {
            LOCK
            auto j = m_images.find(i);
            if(j != m_images.end())
                return j->second;
        }
        
        return unexpected<"Unable to find specified image">();
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

    ViFrame&            Visualizer::next_frame()
    {
        return *(m_frames[(m_tick+1) % m_frames.size()]);
    }
    
    const ViFrame&      Visualizer::next_frame() const
    {
        return const_cast<Visualizer*>(this)->next_frame();
    }

    const ViPipeline* Visualizer::pipeline(uint64_t i) const
    {
        {
            LOCK
            auto j = m_pipelines.find(i);
            if(j != m_pipelines.end())
                return (j->second);
        }
        return nullptr;
    }

    VkQueue      Visualizer::present_queue(uint32_t i) const
    {
        return m_present ? m_present->queue(i) : nullptr;
    }
    
    uint32_t     Visualizer::present_queue_count() const
    {
        return m_present ? (uint32_t) m_present->m_queues.size() : 0;
    }
    
    uint32_t     Visualizer::present_queue_family() const
    {
        return m_present ? m_present->m_family : UINT32_MAX;
    }

    bool        Visualizer::present_queue_valid() const
    {
        return m_present != nullptr;
    }
    
    VkRenderPass Visualizer::render_pass() const
    {
        return m_renderPass -> m_renderPass;
    }


    Expect<ViShader> Visualizer::shader(uint64_t i) const
    {
        {
            LOCK
            auto j=m_shaders.find(i);
            if(j != m_shaders.end())
                return j->second;
        }
        
        return unexpected<"Unable to find the specified shader">();
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
        return m_swapchain->def_scissor();
    }
    
    VkViewport  Visualizer::swapchain_def_viewport() const
    {
        return m_swapchain->def_viewport();
    }

    uint32_t    Visualizer::swapchain_image_count() const
    {
        return m_swapchain->m_imageCount;
    }

    uint32_t    Visualizer::swapchain_height() const
    {
        return m_swapchain->height();
    }

    uint32_t    Visualizer::swapchain_min_image_count() const
    {
        return m_swapchain->m_minImageCount;
    }

    uint32_t    Visualizer::swapchain_width() const
    {
        return m_swapchain->width();
    }

    Expect<ViTexture> Visualizer::texture(uint64_t i) const
    {
        {
            LOCK
            auto j = m_textures.find(i);
            if(j != m_textures.end())
                return j->second;
        }
        
        return unexpected<"Unable to find requested texture">();
    }
            
    VkQueue   Visualizer::video_decode_queue(uint32_t i) const
    {
        return m_videoDecode ? m_videoDecode->queue(i) : nullptr;
    }
    
    uint32_t  Visualizer::video_decode_queue_count() const
    {
        return m_videoDecode ? (uint32_t) m_videoDecode->m_queues.size() : 0;
    }
    
    uint32_t  Visualizer::video_decode_queue_family() const
    {
        return m_videoDecode ? m_videoDecode->m_family : UINT32_MAX;
    }

    bool        Visualizer::video_decode_queue_valid() const
    {
        return m_videoDecode != nullptr;
    }

    VkQueue   Visualizer::video_encode_queue(uint32_t i) const
    {
        return m_videoEncode ? m_videoEncode->queue(i) : nullptr;
    }
    
    uint32_t  Visualizer::video_encode_queue_count() const
    {
        return m_videoEncode ? (uint32_t) m_videoEncode->m_queues.size() : 0;
    }

    uint32_t  Visualizer::video_encode_queue_family() const
    {
        return m_videoEncode ? m_videoEncode->m_family : UINT32_MAX;
    }

    bool        Visualizer::video_encode_queue_valid() const
    {
        return m_videoEncode != nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //  SETTERS/MANIPULATORS

    Expect<ViBuffer>    Visualizer::create(const Buffer& v)
    {
        {
            LOCK
            auto j = m_buffers.find(v.id());
            if(j != m_buffers.end())
                return j->second;
        }
        
        ViBuffer p, ret;
        auto ec = p.create(*this, v);
        if(ec)
            return unexpected(ec);
        
        {
            WLOCK
            auto [j,f]  = m_buffers.try_emplace(v.id(), p);
            if(f){
                std::swap(p, ret);
            } else
                ret = j->second;
        }
        
        if(p.buffer)
            p.destroy(*this);
        return ret;
    }
    
    Expect<ViImage>     Visualizer::create(const Image&v)
    {
        {
            LOCK
            auto j = m_images.find(v.id());
            if(j != m_images.end())
                return j->second;
        }
        
        ViImage     p, ret;
        auto ec = p.create(*this, v);
        if(ec)
            return unexpected(ec);
        
        {
            WLOCK
            auto [j,f]  = m_images.try_emplace(v.id(), p);
            if(f){
                std::swap(p, ret);
            } else
                ret     = j->second;
        }
        
        if(p.image)
            p.destroy(*this);
        return ret;
    }

    
    const ViPipeline*  Visualizer::create(const Pipeline& v)
    {
        {
            LOCK
            auto j = m_pipelines.find(v.id());
            if(j != m_pipelines.end())
                return j->second;
        }
        
        ViPipeline* p   = new ViPipeline(*this, v);
        p -> _ctor();
        ViPipeline* ret = nullptr;
        
        {
            WLOCK
            auto [j,f]  = m_pipelines.try_emplace(v.id(), p);
            if(f){
                std::swap(p, ret);
            } else
                ret     = j->second;
        }
        
        if(p)
            delete p;
        
        return ret;
    }

    Expect<ViShader>    Visualizer::create(const Shader& v)
    {
        {
            LOCK
            auto j = m_shaders.find(v.id());
            if(j != m_shaders.end())
                return j->second;
        }
        
        ViShader    p, ret;
        auto ec = p.create(m_device, v);
        if(ec)
            return unexpected(ec);
        
        {
            WLOCK
            auto [j,f]  = m_shaders.try_emplace(v.id(), p);
            if(f){
                std::swap(p, ret);
            } else {
                ret = j->second;
            }
        }
        
        if(p.shader)
            p.destroy(m_device);
        return ret;
    }

    Expect<ViTexture>       Visualizer::create(const Texture& t)
    {
        {
            LOCK
            auto j = m_textures.find(t.id());
            if(j != m_textures.end())
                return j->second;
        }
        
        if(!t.image)
            return unexpected<"No image, no texture">();
        
        Expect<ViImage> img = create(*(t.image));
        if(!img)
            return unexpected(img.error());
        
        ViTexture   p, ret;
        
        std::error_code ec  = _create(p, *img, t);
        if(ec)
            return unexpected(ec);
            
        {
            WLOCK
            auto [j,f]  = m_textures.try_emplace(t.id(), p);
            if(f){
                std::swap(p, ret);
            } else
                ret     = j->second;
        }
        
        _destroy(p);
        return ret;
    }

    void        Visualizer::erase(const Buffer& v)
    {
        ViBuffer    vb;
        
        {
            WLOCK
            auto j = m_buffers.find(v.id());
            if(j != m_buffers.end()){
                vb      = j->second;
                m_buffers.erase(j);
            }
        }
        
        if(vb.buffer)
            vb.destroy(*this);
    }

    void        Visualizer::set_clear_color(const RGBA4F&i)
    {   
        VkClearValue    cc  = vqClearValue(i);

        WLOCK
        m_clearValue    = cc;
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

    ////////////////////////////////////////////////////////////////////////////////
    //  RENDERING

    void                Visualizer::_rebuild()
    {
        vkDeviceWaitIdle(m_device);
        m_swapchain     = std::make_unique<ViSwapchain>(*this, *m_renderPass, m_swapchain.get());
    }

    std::error_code     Visualizer::_record(ViContext& u, uint32_t imageIndex, DrawFunction use)
    {
        VqCommandBufferBeginInfo beginInfo;
        beginInfo.flags = 0; // Optional
        beginInfo.pInheritanceInfo = nullptr; // Optional

        if (vkBeginCommandBuffer(u.command(), &beginInfo) != VK_SUCCESS)
            return create_error<"Failed to begin recording command buffer">();

        VqRenderPassBeginInfo renderPassInfo;
        renderPassInfo.renderPass = m_renderPass -> m_renderPass;
        renderPassInfo.framebuffer = m_swapchain->m_frameBuffers[imageIndex];
        renderPassInfo.renderArea.offset = {0, 0};
        renderPassInfo.renderArea.extent = m_swapchain->m_extents;

        renderPassInfo.clearValueCount = 1;
        VkClearValue                cv  = m_clearValue;
        renderPassInfo.pClearValues = &cv;
        vkCmdBeginRenderPass(u.command(), &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

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
            
        vkCmdEndRenderPass(u.command());
        if (vkEndCommandBuffer(u.command()) != VK_SUCCESS)
            return create_error<"Failed to record command buffer">();
        return ret;
    }

    std::error_code     Visualizer::draw(ViContext& u, DrawFunction use)
    {
        static constexpr const uint64_t     kMaxWait = 100'000'000ULL;
    
    
        auto    r1 = auto_reset(u.m_viz, this);
        ViFrame&    f   = current_frame();
        auto    r2  = auto_reset(u.m_command, f.m_commandBuffer);
        auto    r3  = auto_reset(u.m_frame, &f);

        VkResult        res = VK_SUCCESS;
        
        res = vkWaitForFences(m_device, 1, &f.m_fence, VK_TRUE, kMaxWait);   // 100ms is 10Hz
        if(res == VK_TIMEOUT)
            return create_error<"Fence timeout">();

        bool    rebuildFlag = m_rebuildSwap.exchange(false);
        if(rebuildFlag){
            _rebuild();
            return std::error_code();
        }

        uint32_t imageIndex = 0;
        res    = vkAcquireNextImageKHR(m_device, m_swapchain->m_swapchain, kMaxWait, f.m_imageAvailable, VK_NULL_HANDLE, &imageIndex);
        
        switch(res){
        case VK_TIMEOUT:
            return create_error<"Acquire image timeout">();
        case VK_ERROR_OUT_OF_DATE_KHR:
        case VK_SUBOPTIMAL_KHR:
            _rebuild();
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
        vkResetCommandBuffer(u.command(), 0);
        
    
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

        if (vkQueueSubmit(m_graphic->queue(0), 1, &submitInfo, f.m_fence) != VK_SUCCESS) 
            return create_error<"Failed to submit draw command buffer">();
            
        VqPresentInfoKHR presentInfo;

        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = signalSemaphores;
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = &m_swapchain->m_swapchain;
        presentInfo.pImageIndices = &imageIndex;
        presentInfo.pResults = nullptr; // Optional
        vkQueuePresentKHR(m_present->queue(0), &presentInfo);
        
        ++m_tick;
        return std::error_code();
    }

    void    Visualizer::_draw(ViContext&u, const Rendered&r, const Pipeline&p, Tristate w)
    {
        const auto&         cfg     = p.config();
        if(cfg.binding != PipelineBinding::Graphics)     // filter out non-graphics (for now)
            return ;
        
        u.m_wireframe       = w;
            
        // TODO ... reduce this down to a single pipeline lookup.... (as the next one is implicit)
        
        //  FOR NOW....
        ViRendered*         thing   = current_frame().create(r, p);
        if(!thing)
            return;
        thing -> update(u);
        thing -> record(u);
    }

    void    Visualizer::draw_object(ViContext&u, const Rendered&r, Tristate w)
    {
        PipelineCPtr    pipe    = r.pipeline();
        if(!pipe)
            return ;

        _draw(u, r, *pipe, w);
    }

    void    Visualizer::draw_object(ViContext&u, const Rendered&r, const Pipeline& p, Tristate w)
    {
        #if 0
            // SMARTER (later, if it becomes an issue)
        const CompoundInfo*     info    = p.config().object;
        if(info){
            if(info->is_type()){
                
            } else if(info->is_object()){
            }
        
            const RenderedInfo& ri  = r.metaInfo();
            if((&ri != info) && !ri->is_base(*info))
                return ;
        }
        #endif
        
        _draw(u,r,p,w);
    }

    void    Visualizer::draw_scene(ViContext& u, const Scene&sc, const Perspective& p)
    {
        if(u.m_viz != this) //  fast reject
            return ;
        if(!p.camera)
            return ;
            
        auto r1 = auto_reset(u.m_utime, sc.utime);
        
        Camera::Params      cparams;
        if(p.screen){
            cparams.screen = *p.screen;
        } else {
            int         w, h;
            glfwGetFramebufferSize(m_window, &w, &h);
            cparams.screen  = Size2D((double) w, (double) h);
        }
        
        auto r2 = auto_reset(u.m_world2eye, p.camera->world2screen(cparams));
        
        for(auto& r : sc.things){
            if(!r)
                continue;
            draw_object(u, *r, p.wireframe);
        }
    }

    void               Visualizer::update(ViContext&u, const Scene&sc)
    {
        if(u.m_frame){
            for(auto& r : sc.things){
                const Pipeline*pipe    = r->pipeline();
                if(!pipe)
                    continue;
                ViRendered* rr  = u.m_frame -> create(*r, *pipe);
                if(!rr)
                    continue;
                rr -> descriptors(u);
            }
        }
    }

    std::error_code    Visualizer::upload(CommandFunction&&fn)
    {
        std::error_code     ec;
        if(!fn)
            return create_error<"Bad function">();
        if(!m_upload->m_commandBuffer)
            return create_error<"Upload capability is uninitialized">();
    
        VqCommandBufferBeginInfo beginInfo;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; // Optional
        if(vkBeginCommandBuffer(m_upload->m_commandBuffer, &beginInfo) != VK_SUCCESS)
            return create_error<"Unable to begin the command buffer">();
            
        try {
            fn(m_upload->m_commandBuffer);
        }
        catch(std::error_code ec2) {
            ec      = ec2;
        }
        
        if(vkEndCommandBuffer(m_upload->m_commandBuffer) != VK_SUCCESS)
            return create_error<"Unable to end the command buffer">();
            
        VqSubmitInfo    subinfo;
        subinfo.pCommandBuffers = &m_upload->m_commandBuffer;
        subinfo.commandBufferCount  = 1;
        if(vkQueueSubmit(m_upload->m_queue, 1, &subinfo, m_upload->m_fence) != VK_SUCCESS)
            return create_error<"Unable to submit the task to the queue">();
        
        
        vkWaitForFences(m_device, 1, &m_upload->m_fence, true, 999'999'999ULL);
        vkResetFences(m_device, 1, &m_upload->m_fence);
        vkResetCommandPool(m_device, m_upload->m_pool, 0);
        return ec;
    }
    
}
