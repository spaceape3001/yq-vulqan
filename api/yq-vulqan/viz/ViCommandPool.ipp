////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViCommandPool.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    ViCommandPool::ViCommandPool()
    {
    }
    
    ViCommandPool::~ViCommandPool()
    {
    }
    
    bool            ViCommandPool::consistent() const
    {
        return m_viz ? (m_pool && m_viz->device()) : !m_pool;
    }

    std::error_code ViCommandPool::init(ViVisualizer& viz, uint32_t queueFamilyIndex, VqCommandPoolCreateFlags cpcf)
    {   
        VqCommandPoolCreateInfo     cpci;
        cpci.queueFamilyIndex   = queueFamilyIndex;
        cpci.flags              = (VkCommandPoolCreateFlags) cpcf.value();
        return init(viz, cpci);
    }
    
    std::error_code ViCommandPool::init(ViVisualizer& viz, const VkCommandPoolCreateInfo& cpci)
    {
        if(!consistent())
            return errors::BAD_STATE_COMMAND_POOL();

        if(m_viz || m_pool)
            return errors::EXISTING_COMMAND_POOL();
        
        if(!viz.device())
            return errors::UNINITIALIZED_VISUALIZER();
        
        if(vkCreateCommandPool(viz.device(), &cpci, nullptr, &m_pool) != VK_SUCCESS){
            m_pool  = nullptr;
            return errors::CANT_CREATE_COMMAND_POOL();
        }
        
        m_viz       = &viz;
        return {};
    }
    
    void            ViCommandPool::kill()
    {
        if(valid())
            vkDestroyCommandPool(m_viz->device(), m_pool, nullptr);
        m_pool  = nullptr;
        m_viz   = nullptr;
    }

    std::error_code ViCommandPool::reset(VqCommandPoolResetFlags cprf)
    {
        if(!consistent())
            return errors::BAD_STATE_COMMAND_POOL();
        if(!valid())
            return errors::UNINITIALIZED_COMMAND_POOL();
        
        VkResult res    = vkResetCommandPool(m_viz->device(), m_pool, (VkCommandPoolResetFlags) cprf.value());
        if(res != VK_SUCCESS)
            return errors::CANT_RESET_COMMAND_POOL();
        return {};
    }

    bool            ViCommandPool::valid() const
    {
        return m_viz && m_pool && m_viz->device();
    }
}

