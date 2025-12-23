////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/ViCommandPool.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViVisualizer.hpp>
#include <yq/core/Ref.hpp>

namespace yq::tachyon {
    VkCommandPoolCreateInfo ViCommandPool::_info(ViQueueFamilyID qf, VqCommandPoolCreateFlags flags)
    {
        VqCommandPoolCreateInfo     cpci;
        cpci.queueFamilyIndex   = qf.index;
        cpci.flags              = (VkCommandPoolCreateFlags) flags.value();
        return cpci;
    }

    ////////////////////////////////////////////////////////////////////////////////
    
    ViCommandPool::ViCommandPool(ViDevice&dev, ViQueueType queueType, VqCommandPoolCreateFlags flags) : ViCommandPool(dev, dev.queue_family(queueType), flags)
    {
    }

    ViCommandPool::ViCommandPool(ViDevice& dev, ViQueueFamilyID queueFamilyIndex, VqCommandPoolCreateFlags flags) : 
        m_device(dev)
    {
        VkCommandPoolCreateInfo cpci = _info(queueFamilyIndex, flags);
        if(_init(cpci) != std::error_code())
            _wipe();
    }
    
    ViCommandPool::ViCommandPool(ViDevice& dev, const VkCommandPoolCreateInfo& cpci) : m_device(dev)
    {
        if(_init(cpci) != std::error_code())
            _wipe();
    }

    ViCommandPool::~ViCommandPool()
    {
        kill();
    }

    std::error_code ViCommandPool::_init(const VkCommandPoolCreateInfo& cpci)
    {
        VkResult    res = vkCreateCommandPool(m_device.device(), &cpci, nullptr, &m_pool);
        if(res != VK_SUCCESS){
            vizWarning << "vkCreateCommandPool(): vkResult " << (int64_t) res;
            m_pool  = nullptr;
            return errors::command_pool_cant_create();
        }
        
        return {};
    }
    
    void            ViCommandPool::_kill()
    {
        vkDestroyCommandPool(m_device.device(), m_pool, nullptr);
    }
    
    std::error_code ViCommandPool::_reset(VkCommandPoolResetFlags flags)
    {
        VkResult res    = vkResetCommandPool(m_device.device(), m_pool, flags);
        if(res != VK_SUCCESS)
            return errors::command_pool_cant_reset();
        return {};
    }
    
    void            ViCommandPool::_wipe()
    {
        m_pool      = nullptr;
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
        if(!valid())
            return errors::command_pool_uninitialized();
        return _reset((VkCommandPoolResetFlags) cprf.value());
    }
}

