////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViCommandPool.hpp"
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yv/VqStructs.hpp>
#include <yq/tachyon/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    VkCommandPoolCreateInfo ViCommandPool::_info(uint32_t queueFamilyIndex, VqCommandPoolCreateFlags flags)
    {
        VqCommandPoolCreateInfo     cpci;
        cpci.queueFamilyIndex   = queueFamilyIndex;
        cpci.flags              = (VkCommandPoolCreateFlags) flags.value();
        return cpci;
    }

    ////////////////////////////////////////////////////////////////////////////////
    
    ViCommandPool::ViCommandPool()
    {
    }

    ViCommandPool::ViCommandPool(ViVisualizer& viz, uint32_t queueFamilyIndex, VqCommandPoolCreateFlags flags)
    {
        if(viz.device()){
            VkCommandPoolCreateInfo cpci = _info(queueFamilyIndex, flags);
            if(_init(viz, cpci) != std::error_code())
                _wipe();
        }
    }
    
    ViCommandPool::ViCommandPool(ViVisualizer& viz, const VkCommandPoolCreateInfo& cpci)
    {
        if(viz.device()){
            if(_init(viz, cpci) != std::error_code())
                _wipe();
        }
    }
    
    ViCommandPool::~ViCommandPool()
    {
        kill();
    }

    std::error_code ViCommandPool::_init(ViVisualizer&viz, const VkCommandPoolCreateInfo& cpci)
    {
        VkResult    res = vkCreateCommandPool(viz.device(), &cpci, nullptr, &m_pool);
        if(res != VK_SUCCESS){
            vizWarning << "vkCreateCommandPool(): vkResult " << (int64_t) res;
            m_pool  = nullptr;
            return errors::command_pool_cant_create();
        }
        
        m_viz       = &viz;
        return {};
    }
    
    void            ViCommandPool::_kill()
    {
            vkDestroyCommandPool(m_viz->device(), m_pool, nullptr);
    }
    
    std::error_code ViCommandPool::_reset(VkCommandPoolResetFlags flags)
    {
        VkResult res    = vkResetCommandPool(m_viz->device(), m_pool, flags);
        if(res != VK_SUCCESS)
            return errors::command_pool_cant_reset();
        return {};
    }
    
    void            ViCommandPool::_wipe()
    {
        m_pool  = nullptr;
        m_viz   = nullptr;
    }
    
    bool            ViCommandPool::consistent() const
    {
        return m_viz ? (m_pool && m_viz->device()) : !m_pool;
    }

    std::error_code ViCommandPool::init(ViVisualizer& viz, uint32_t queueFamilyIndex, VqCommandPoolCreateFlags cpcf)
    {   
        return init(viz, _info(queueFamilyIndex, cpcf));
    }
    
    std::error_code ViCommandPool::init(ViVisualizer& viz, const VkCommandPoolCreateInfo& cpci)
    {
        if(!consistent())
            return errors::command_pool_bad_state();

        if(m_viz || m_pool)
            return errors::command_pool_existing();
        
        if(!viz.device())
            return errors::visualizer_uninitialized();
        
        std::error_code ec = _init(viz, cpci);
        if(ec != std::error_code())
            _wipe();
        return ec;
    }
    
    void            ViCommandPool::kill()
    {
        if(valid()){
            _kill();
        }
        _wipe();
    }

    std::error_code ViCommandPool::reset(VqCommandPoolResetFlags cprf)
    {
        if(!consistent())
            return errors::command_pool_bad_state();
        if(!valid())
            return errors::command_pool_uninitialized();
        return _reset((VkCommandPoolResetFlags) cprf.value());
    }

    bool            ViCommandPool::valid() const
    {
        return m_viz && m_pool && m_viz->device();
    }
}

