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

#include <basic/AutoReset.hpp>
#include <basic/BasicBuffer.hpp>
#include <basic/ErrorDB.hpp>
#include <basic/errors.hpp>

#include <math/color/RGBA.hpp>

#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/gpu/ViContext.hpp>
#include <tachyon/gpu/VqApp.hpp>
#include <tachyon/gpu/VqUtils.hpp>
#include <tachyon/scene/Perspective.hpp>
#include <tachyon/scene/Render3D.hpp>
#include <tachyon/scene/Scene.hpp>

#include <tachyon/viz/Buffer.hpp>
#include <tachyon/viz/Image.hpp>
#include <tachyon/viz/ImageViewInfo.hpp>
#include <tachyon/viz/Pipeline.hpp>
#include <tachyon/viz/PushData.hpp>
#include <tachyon/viz/Shader.hpp>
#include <tachyon/viz/Texture.hpp>

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
    
    //  ViBO
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

    ViFrame::ViFrame(Visualizer&viz) : m_viz(viz)
    {
    }
    
    ViFrame::~ViFrame()
    {
        _dtor();
    }

    std::error_code     ViFrame::_ctor()
    {
        try {
            m_commandPool       = m_viz.command_pool();
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
            return std::error_code();
        }
        catch(std::error_code ec)
        {
            _dtor();
            return ec;
        }
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
                if(i->second->m_pipe.id == pipe.id())
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
                if(i->second->m_pipe.id == pipe.id()){
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
                if(i->second->m_pipe.id == pipe.id())
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
    //  ViQueues
    ////////////////////////////////////////////////////////////////////////////////

    void    ViQueues::set(VkDevice dev, uint32_t cnt)
    {
        queues.clear();
        queues.resize(cnt, nullptr);
        for(uint32_t i=0;i<cnt;++i)
            vkGetDeviceQueue(dev, family, i, &queues[i]);
    }
    
    VkQueue ViQueues::operator[](uint32_t i) const
    {
        if(i<queues.size()) [[likely]]
            return queues[i];
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
        auto& vc    = m_pipe.cfg.vbos;
        if(!vc.empty()){
            m_vbos.resize(vc.size());
            for(i=0;i<m_vbos.size();++i){
                m_vbos[i] = m_pipe.vbos[i];
                m_vbos[i].update(m_viz, vc[i], &m_object);
            }
        }
            
        auto& ic    = m_pipe.cfg.ibos;
        if(!ic.empty()){
            m_ibos.resize(ic.size());
            for(i=0;i<m_ibos.size();++i){
                m_ibos[i] = m_pipe.ibos[i];
                m_ibos[i].update(m_viz, ic[i], &m_object);
            }
        }
        
        auto& uc    = m_pipe.cfg.ubos;
        if(!uc.empty()){
            m_ubos.resize(uc.size());
            for(i=0;i<m_ubos.size();++i)
                m_ubos[i] = m_pipe.ubos[i];
            
            ds += uc.size();
        }
        
        if(ds){
            std::vector<VkDescriptorSetLayout>      layouts(ds, m_pipe.descriptors);    // TODO efficiency is to push this into ViPipeline
            VqDescriptorSetAllocateInfo allocInfo;
            allocInfo.descriptorPool        = m_viz.descriptor_pool();
            allocInfo.descriptorSetCount    = ds;
            allocInfo.pSetLayouts           = &m_pipe.descriptors;
            m_descriptors.resize(ds);
            if(vkAllocateDescriptorSets(m_viz.device(), &allocInfo, m_descriptors.data()) != VK_SUCCESS){
                yInfo() << "Unable to allocate descriptor sets!";
            }
            
            for(i=0;i<m_ubos.size();++i)
                _ubo(i);
        }
        return std::error_code();
    }
    
    void                ViRendered::_dtor()
    {
    }

    void    ViRendered::_ubo(size_t i)
    {
        if(i>=m_ubos.size())
            return ;
        
        if(!m_ubos[i].update(m_viz, m_pipe.cfg.ubos[i], &m_object))
            return ;
            
        VkDescriptorBufferInfo  bufferInfo;
        bufferInfo.buffer   = m_ubos[i].buffer;
        bufferInfo.offset   = 0;
        bufferInfo.range    = VK_WHOLE_SIZE;

        VqWriteDescriptorSet    descriptorWrite;
        descriptorWrite.dstSet              = m_descriptors[i];
        descriptorWrite.dstBinding          = i;
        descriptorWrite.dstArrayElement     = 0;
        descriptorWrite.descriptorType      = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrite.descriptorCount     = 1;
        descriptorWrite.pBufferInfo         = &bufferInfo;
        descriptorWrite.pImageInfo          = nullptr;
        descriptorWrite.pTexelBufferView    = nullptr;
        vkUpdateDescriptorSets(m_viz.device(), 1, &descriptorWrite, 0, nullptr);
    }
 
    void                ViRendered::update(ViContext& u)
    {
        size_t i;
        
        auto& vc    = m_pipe.cfg.vbos;
        for(i=0;i<m_vbos.size();++i)
            m_vbos[i].update(m_viz, vc[i], &m_object);
            
        auto& ic    = m_pipe.cfg.ibos;
        for(i=0;i<m_ibos.size();++i)
            m_ibos[i].update(m_viz, ic[i], &m_object);

        for(i=0;i<m_ubos.size();++i)
            _ubo(i);

        const Render3D* r3      = (m_pipe.cfg.push.type == PushConfigType::Full) ? dynamic_cast<const Render3D*>(&m_object) : nullptr;
        StdPushData*    push    = (r3 || (m_pipe.cfg.push.type == PushConfigType::View)) ? m_push.create_single<StdPushData>() : nullptr;
        if(push)
            push->time       = u.utime();
            
        switch(m_pipe.cfg.push.type){
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
            if(m_pipe.cfg.push.fetch)
                m_pipe.cfg.push.fetch(&m_object, m_push);
            break;
        case PushConfigType::None:
        default:
            break;
        }
    }

    void                ViRendered::record(ViContext&u)
    {
        const auto&         cfg     = m_pipe.cfg;
        if(cfg.binding != PipelineBinding::Graphics)     // filter out non-graphics (for now)
            return ;

            //  =================================================
            //      SET THE PIPELINE
        Tristate        wireframe   = (u.wireframe() == Tristate::INHERIT) ? m_object.wireframe() : u.wireframe();
        VkPipeline      vkpipe      = (wireframe == Tristate::YES) ? m_pipe.wireframe : m_pipe.pipeline;
        if(vkpipe && (vkpipe != u.m_pipeline)){
            vkCmdBindPipeline(u.command(), VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipe);
            u.m_pipeline    = vkpipe;
            u.m_layout      = m_pipe.layout;
        }

            //  =================================================
            //      PUSH THE CONSTANTS

        if(!m_push.empty())
            vkCmdPushConstants(u.command(), m_pipe.layout, m_pipe.shaders, 0, m_push.size(), m_push.data() );
        
        if(!m_descriptors.empty())
            vkCmdBindDescriptorSets(u.command(), VK_PIPELINE_BIND_POINT_GRAPHICS, u.m_layout, 0, m_descriptors.size(), m_descriptors.data(), 0, nullptr);
        
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
        //  UPLOAD
        ec  = _create(m_upload, m_graphic);
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

        m_frames.resize(vci.frames_in_flight);
        for(auto& f : m_frames){
            f   = std::make_unique<ViFrame>(*this);
            ec  = f->_ctor();
            if(ec)
                return ec;
        }
        
        set_clear_color(vci.clear);

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
    
        m_frames.clear();
    
        if(m_renderPass)
            vkDestroyRenderPass(m_device, m_renderPass, nullptr);
        
        _destroy(m_upload);
        _destroy(m_thread);
    
        for(auto& p : m_pipelines){
            if(p.second){
                _destroy(*(p.second));
                delete p.second;
            }
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
    
    std::error_code          Visualizer::_create(ViPipeline&p, const PipelineConfig&cfg)
    {
        try {
            std::vector<VkPipelineShaderStageCreateInfo>    stages;
            p.shaders           = 0;
            for(auto& s : cfg.shaders){
                Ref<const Shader>   sh  = Shader::decode(s);
                if(!sh)
                    continue;
                
                Expect<ViShader>    xvs = create(*sh);
                if(!xvs)
                    continue;
                
                const ViShader&     ssh = *xvs;
                
                VqPipelineShaderStageCreateInfo stage;
                stage.stage     = ssh.mask;
                stage.pName     = "main";
                stage.module    = ssh.shader;
                stages.push_back(stage);

                p.shaders      |= ssh.mask;
            }
        
            VqPipelineVertexInputStateCreateInfo    vertexInfo;
            VqPipelineLayoutCreateInfo              pipelineLayoutInfo;
            
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
yInfo() << "Creating pipeline with " << cfg.ubos.size() << " UBOs declared";            
                for(uint32_t    i   = 0;i<cfg.ubos.size();++i){
                    auto& u = cfg.ubos[i];
                    VkDescriptorSetLayoutBinding a;
                    a.binding           = i;
                    a.descriptorCount   = u.count;
                    a.descriptorType    = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
                    if(u.shaders){
                        a.stageFlags    = u.shaders;
                    } else
                        a.stageFlags    = p.shaders;
                    ubos.push_back(a);
                }
                
                VqDescriptorSetLayoutCreateInfo layoutInfo;
                layoutInfo.bindingCount = ubos.size();
                layoutInfo.pBindings    = ubos.data();
                if(vkCreateDescriptorSetLayout(m_device, &layoutInfo, nullptr, &p.descriptors) != VK_SUCCESS)
                    throw create_error<"Unable to create a descriptor set layout">();
                pipelineLayoutInfo.setLayoutCount   = 1;
                pipelineLayoutInfo.pSetLayouts      = &p.descriptors;
            }
                
            vertexInfo.vertexBindingDescriptionCount    = (uint32_t) vbos.size();
            vertexInfo.pVertexBindingDescriptions       = vbos.data();
            vertexInfo.vertexAttributeDescriptionCount  = (uint32_t) attrs.size();
            vertexInfo.pVertexAttributeDescriptions     = attrs.data();
            
            VqPipelineInputAssemblyStateCreateInfo  inputAssembly;
            inputAssembly.topology                  = (VkPrimitiveTopology) cfg.topology.value();
            inputAssembly.primitiveRestartEnable    = VK_FALSE;
            
            VkViewport viewport = m_swapchain.def_viewport();

            VkRect2D scissor = m_swapchain.def_scissor();
            
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
                    push.size   = sizeof(StdPushData);
                    break;
                case PushConfigType::Custom:
                    push.size   = cfg.push.size;
                    break;
                default:
                    break;
                }
            }
            
            pipelineLayoutInfo.setLayoutCount = 0; // Optional
            pipelineLayoutInfo.pSetLayouts = nullptr; // Optional
            if(push.size != 0){
                if(cfg.push.shaders)
                    push.stageFlags = cfg.push.shaders;
                else
                    push.stageFlags = p.shaders;
                pipelineLayoutInfo.pushConstantRangeCount = 1;
                pipelineLayoutInfo.pPushConstantRanges = &push;
            } else {
                pipelineLayoutInfo.pushConstantRangeCount = 0; // Optional
                pipelineLayoutInfo.pPushConstantRanges = nullptr; // Optional
            }
            if(p.descriptors){
                pipelineLayoutInfo.setLayoutCount   = 1;
                pipelineLayoutInfo.pSetLayouts      = &p.descriptors;
            }

            if (vkCreatePipelineLayout(m_device, &pipelineLayoutInfo, nullptr, &p.layout) != VK_SUCCESS) 
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
            pipelineInfo.layout                 = p.layout;
            pipelineInfo.renderPass             = m_renderPass;
            pipelineInfo.subpass                = 0;             
            pipelineInfo.basePipelineHandle     = VK_NULL_HANDLE; // Optional
            pipelineInfo.basePipelineIndex      = -1; // Optional        
            
            if(cfg.polymode == PolygonMode::Fill)
                pipelineInfo.flags  = VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT;
            if (vkCreateGraphicsPipelines(m_device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &p.pipeline) != VK_SUCCESS) 
                throw create_error<"Failed to create graphics pipeline!">();
            
                // if it's a fill polygon (typical), create a derivative wireframe pipeline
            if(cfg.polymode == PolygonMode::Fill){
                pipelineInfo.flags  = VK_PIPELINE_CREATE_DERIVATIVE_BIT;
                pipelineInfo.basePipelineHandle = p.pipeline;
                pipelineInfo.basePipelineIndex  = -1;
                rasterizer.polygonMode  = VK_POLYGON_MODE_LINE;
                
                if (vkCreateGraphicsPipelines(m_device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &p.wireframe) != VK_SUCCESS)
                    throw create_error<"Failed to create wireframe pipeline!">();
            }
            
            p.binding       = (VkPipelineBindPoint) cfg.binding.value();
            
            
            if(!cfg.vbos.empty()){
                for(auto& vb : cfg.vbos){
                    ViBO        bo;
                    bo.update(*this, vb, nullptr);
                    p.vbos.push_back(bo);
                }
            }
            
            if(!cfg.ibos.empty()){
                for(auto & ib : cfg.ibos){
                    ViBO        bo;
                    bo.update(*this, ib, nullptr);
                    p.ibos.push_back(bo);
                }
            }

            if(!cfg.ubos.empty()){
                for(auto & ub : cfg.ubos){
                    ViBO        bo;
                    bo.update(*this, ub, nullptr);
                    p.ubos.push_back(bo);
                }
            }
                
            p.cfg           = cfg;


            return std::error_code();
        }
        catch(std::error_code ec)
        {
            _destroy(p);
            return ec;
        }
            
    }
    
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

            VkImageViewCreateInfo       imageViewInfo = vqCreateInfo(ImageViewInfo());
            imageViewInfo.format       = m_surfaceFormat;
            
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

    std::error_code             Visualizer::_create(ViUpload&p, const ViQueues&q)
    {
        try {
            if(q.queues.empty())
                throw create_error<"Queues has no queues">();
        
            p.queue                     =   q.queues[0];
            VqCommandPoolCreateInfo poolInfo;
            poolInfo.queueFamilyIndex   =   q.family;
            if (vkCreateCommandPool(m_device, &poolInfo, nullptr, &p.pool) != VK_SUCCESS) 
                throw create_error<"Failed to create an upload command pool">();
                
            VqCommandBufferAllocateInfo allocInfo;
            allocInfo.commandPool           = p.pool;
            allocInfo.level                 = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
            allocInfo.commandBufferCount    = 1;
            if (vkAllocateCommandBuffers(m_device, &allocInfo, &p.commandBuffer) != VK_SUCCESS) 
                throw create_error<"Failed to allocate command buffers">();
                
            VqFenceCreateInfo   fci;
            if(vkCreateFence(m_device, &fci, nullptr,  &p.fence) != VK_SUCCESS)
                throw create_error<"Unable to create fence">();

            return std::error_code();
        }
        catch(std::error_code ec)
        {
            _destroy(p);
            return ec;
        }
    }
    
    void                        Visualizer::_destroy(ViUpload&p)
    {
        if(p.fence){
            vkDestroyFence(m_device, p.fence, nullptr);
            p.fence   = nullptr;
        }

        if(p.commandBuffer && p.pool){
            vkFreeCommandBuffers(m_device, p.pool, 1, &p.commandBuffer);
            p.commandBuffer    = nullptr;
        }

        if(p.pool){
            vkDestroyCommandPool(m_device, p.pool, nullptr);
            p.pool      = nullptr;
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
        return *(m_frames[m_tick % m_frames.size()]);
    }
    
    const ViFrame&      Visualizer::current_frame() const
    {
        return const_cast<Visualizer*>(this)->current_frame();
    }

    VkDescriptorPool    Visualizer::descriptor_pool() const
    {
        return m_thread.descriptors;
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
        
        ViPipeline* p   = new ViPipeline;
        _create(*p, v.config());
        ViPipeline* ret = nullptr;
        
        {
            WLOCK
            auto [j,f]  = m_pipelines.try_emplace(v.id(), p);
            if(f){
                std::swap(p, ret);
            } else
                ret     = j->second;
        }
        
        if(p){
            _destroy(*p);
            delete p;
        }
        
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
        ViSwapchain newChain;
        _create(newChain);
        std::swap(newChain, m_swapchain);
        _destroy(newChain);
    }

    std::error_code     Visualizer::_record(ViContext& u, uint32_t imageIndex, DrawFunction use)
    {
    
        VqCommandBufferBeginInfo beginInfo;
        beginInfo.flags = 0; // Optional
        beginInfo.pInheritanceInfo = nullptr; // Optional

        if (vkBeginCommandBuffer(u.command(), &beginInfo) != VK_SUCCESS)
            return create_error<"Failed to begin recording command buffer">();

        VqRenderPassBeginInfo renderPassInfo;
        renderPassInfo.renderPass = m_renderPass;
        renderPassInfo.framebuffer = m_swapchain.frameBuffers[imageIndex];
        renderPassInfo.renderArea.offset = {0, 0};
        renderPassInfo.renderArea.extent = m_swapchain.extents;

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
        res    = vkAcquireNextImageKHR(m_device, m_swapchain.swapchain, kMaxWait, f.m_imageAvailable, VK_NULL_HANDLE, &imageIndex);
        
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

        if (vkQueueSubmit(m_graphic[0], 1, &submitInfo, f.m_fence) != VK_SUCCESS) 
            return create_error<"Failed to submit draw command buffer">();
            
        VqPresentInfoKHR presentInfo;

        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = signalSemaphores;
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = &m_swapchain.swapchain;
        presentInfo.pImageIndices = &imageIndex;
        presentInfo.pResults = nullptr; // Optional
        vkQueuePresentKHR(m_present[0], &presentInfo);
        
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

    std::error_code    Visualizer::upload(CommandFunction&&fn)
    {
        std::error_code     ec;
        if(!fn)
            return create_error<"Bad function">();
        if(!m_upload.commandBuffer)
            return create_error<"Upload capability is uninitialized">();
    
        VqCommandBufferBeginInfo beginInfo;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; // Optional
        if(vkBeginCommandBuffer(m_upload.commandBuffer, &beginInfo) != VK_SUCCESS)
            return create_error<"Unable to begin the command buffer">();
            
        try {
            fn(m_upload.commandBuffer);
        }
        catch(std::error_code ec2) {
            ec      = ec2;
        }
        
        if(vkEndCommandBuffer(m_upload.commandBuffer) != VK_SUCCESS)
            return create_error<"Unable to end the command buffer">();
            
        VqSubmitInfo    subinfo;
        subinfo.pCommandBuffers = &m_upload.commandBuffer;
        subinfo.commandBufferCount  = 1;
        if(vkQueueSubmit(m_upload.queue, 1, &subinfo, m_upload.fence) != VK_SUCCESS)
            return create_error<"Unable to submit the task to the queue">();
        
        
        vkWaitForFences(m_device, 1, &m_upload.fence, true, 999'999'999ULL);
        vkResetFences(m_device, 1, &m_upload.fence);
        vkResetCommandPool(m_device, m_upload.pool, 0);
        return ec;
    }
    
}
