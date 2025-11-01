////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/ViRenderPass.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using render_pass_bad_state             = error_db::entry<"Render pass is in a bad state">;
        using render_pass_cant_create           = error_db::entry<"Unable to create render pass">;
        using render_pass_existing              = error_db::entry<"Render pass already created">;
    }

    ViRenderPass::ViRenderPass()
    {
    }
    
    #if 0
    ViRenderPass::ViRenderPass(ViVisualizer&viz, const RenderPass& rp)
    {
        if(viz.device()){
            std::error_code ec  = _init(viz, rp);
            if(ec != std::error_code()){
                _wipe();
            }
        }
    }
    
    ViRenderPass::ViRenderPass(ViVisualizer&viz, const RenderPassInfo&rpi)
    {
        if(viz.device()){
            std::error_code ec  = _init(viz, rpi);
            if(ec != std::error_code()){
                _wipe();
            }
        }
    }
    #endif

    ViRenderPass::ViRenderPass(ViVisualizer&viz, const VkRenderPassCreateInfo&rpci)
    {
        if(viz.device()){
            std::error_code ec  = _init(viz, rpci);
            if(ec != std::error_code()){
                _wipe();
            }
        }
    }

    ViRenderPass::ViRenderPass(ViVisualizer&viz, VkFormat fmt)
    {
        if(viz.device()){
            std::error_code ec  = _init(viz, fmt);
            if(ec != std::error_code()){
                _wipe();
            }
        }
    }
    
    ViRenderPass::~ViRenderPass()
    {
        kill();
    }

    std::error_code ViRenderPass::_init(ViVisualizer&viz, const VkRenderPassCreateInfo& rpci)
    {
        VkResult    res = vkCreateRenderPass(viz.device(), &rpci, nullptr, &m_renderPass);
        if(res != VK_SUCCESS){
            vizWarning << "vkRenderPassCreate(): vkResult " << (int64_t) res;
            return errors::render_pass_cant_create();
        }
        m_viz   = &viz;
        return {};
    }
    
    #if 0
    std::error_code ViRenderPass::_init(ViVisualizer&viz, const RenderPass&rp)
    {
        return _init(viz, rp.info);
    }
    
    std::error_code ViRenderPass::_init(ViVisualizer&viz, const RenderPassInfo&rpi)
    {
        std::vector<VkAttachmentDescription>    colorAttachments;
        std::vector<VkAttachmentReferences>     colarAttachmentRefs;
    }
    #endif
    
    std::error_code ViRenderPass::_init(ViVisualizer&viz, VkFormat fmt)
    {
        VkAttachmentDescription colorAttachment{};
        colorAttachment.format          = fmt;
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

        return _init(viz, renderPassInfo);
    }
    
    void            ViRenderPass::_kill()
    {
        if(m_renderPass){
            vkDestroyRenderPass(m_viz->device(), m_renderPass, nullptr);
            m_renderPass    = nullptr;
        }
    }
    
    void            ViRenderPass::_wipe()
    {
        m_viz           = nullptr;
        m_renderPass    = nullptr;
    }

    bool            ViRenderPass::consistent() const
    {
        return m_viz ? (m_renderPass && m_viz->device()) : !m_renderPass;
    }

    std::error_code         ViRenderPass::init(ViVisualizer& viz, const VkRenderPassCreateInfo&rpci)
    {
        if(m_viz){
            if(!consistent()){
                return errors::render_pass_bad_state();
            }
            return errors::render_pass_existing();
        }
        if(!viz.device()){
            return errors::visualizer_uninitialized();
        }
        
        std::error_code ec = _init(viz, rpci);
        if(ec != std::error_code()){
            _wipe();
        }
        return ec;
    }
    
    std::error_code         ViRenderPass::init(ViVisualizer& viz, VkFormat fmt)
    {
        if(m_viz){
            if(!consistent()){
                return errors::render_pass_bad_state();
            }
            return errors::render_pass_existing();
        }
        
        std::error_code ec = _init(viz, fmt);
        if(ec != std::error_code()){
            _wipe();
        }
        return ec;
    }

    void                    ViRenderPass::kill()
    {
        if(valid()){
            _kill();
        }
        _wipe();
    }

    bool            ViRenderPass::valid() const
    {
        return m_viz && m_renderPass && m_viz->device();
    }
}
