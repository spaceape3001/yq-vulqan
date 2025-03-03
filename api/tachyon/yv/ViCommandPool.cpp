////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViCommandPool.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yv/VqStructs.hpp>
#include <yv/ViVisualizer.hpp>

namespace yq::tachyon {
    VkCommandPoolCreateInfo ViCommandPool::_info(ViQueueFamilyID qf, VqCommandPoolCreateFlags flags)
    {
        VqCommandPoolCreateInfo     cpci;
        cpci.queueFamilyIndex   = qf.index;
        cpci.flags              = (VkCommandPoolCreateFlags) flags.value();
        return cpci;
    }

    ////////////////////////////////////////////////////////////////////////////////
    
    ViCommandPool::ViCommandPool()
    {
    }

    ViCommandPool::ViCommandPool(VkDevice dev, ViQueueFamilyID queueFamilyIndex, VqCommandPoolCreateFlags flags)
    {
        if(dev){
            VkCommandPoolCreateInfo cpci = _info(queueFamilyIndex, flags);
            if(_init(dev, cpci) != std::error_code())
                _wipe();
        }
    }
    
    ViCommandPool::ViCommandPool(VkDevice dev, const VkCommandPoolCreateInfo& cpci)
    {
        if(dev){
            if(_init(dev, cpci) != std::error_code())
                _wipe();
        }
    }
    
    ViCommandPool::ViCommandPool(ViVisualizer& viz, ViQueueFamilyID queueFamilyIndex, VqCommandPoolCreateFlags flags) :
        ViCommandPool(viz.device(), queueFamilyIndex, flags)
    {
    }
    
    ViCommandPool::ViCommandPool(ViVisualizer& viz, const VkCommandPoolCreateInfo& cpci) :
        ViCommandPool(viz.device(), cpci)
    {
    }

    ViCommandPool::~ViCommandPool()
    {
        kill();
    }

    std::error_code ViCommandPool::_init(VkDevice dev, const VkCommandPoolCreateInfo& cpci)
    {
        VkResult    res = vkCreateCommandPool(dev, &cpci, nullptr, &m_pool);
        if(res != VK_SUCCESS){
            vizWarning << "vkCreateCommandPool(): vkResult " << (int64_t) res;
            m_pool  = nullptr;
            return errors::command_pool_cant_create();
        }
        
        m_device    = dev;
        return {};
    }
    
    void            ViCommandPool::_kill()
    {
        vkDestroyCommandPool(m_device, m_pool, nullptr);
    }
    
    std::error_code ViCommandPool::_reset(VkCommandPoolResetFlags flags)
    {
        VkResult res    = vkResetCommandPool(m_device, m_pool, flags);
        if(res != VK_SUCCESS)
            return errors::command_pool_cant_reset();
        return {};
    }
    
    void            ViCommandPool::_wipe()
    {
        m_device    = nullptr;
        m_pool      = nullptr;
    }
    
    bool            ViCommandPool::consistent() const
    {
        return m_device ? static_cast<bool>(m_pool) : !m_pool;
    }

    std::error_code ViCommandPool::init(VkDevice dev, ViQueueFamilyID queueFamilyIndex, VqCommandPoolCreateFlags cpcf)
    {   
        return init(dev, _info(queueFamilyIndex, cpcf));
    }
    
    std::error_code ViCommandPool::init(VkDevice dev, const VkCommandPoolCreateInfo& cpci)
    {
        if(!consistent())
            return errors::command_pool_bad_state();

        if(m_device || m_pool)
            return errors::command_pool_existing();
        
        if(!dev)
            return errors::visualizer_uninitialized();
        
        std::error_code ec = _init(dev, cpci);
        if(ec != std::error_code())
            _wipe();
        return ec;
    }
    
    std::error_code ViCommandPool::init(ViVisualizer& viz, ViQueueFamilyID queueFamilyIndex, VqCommandPoolCreateFlags cpcf)
    {   
        return init(viz.device(), _info(queueFamilyIndex, cpcf));
    }
    
    std::error_code ViCommandPool::init(ViVisualizer& viz, const VkCommandPoolCreateInfo& cpci)
    {
        return init(viz.device(), cpci);
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
        return m_device && m_pool;
    }
}

