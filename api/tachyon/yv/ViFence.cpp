////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViFence.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yv/VqStructs.hpp>
#include <yv/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using fence_bad_state                   = error_db::entry<"Fence is in a bad state">;
        using fence_cant_create                 = error_db::entry<"Unable to create vulkan fence">;
        using fence_existing                    = error_db::entry<"Fence already created">;
        using fence_not_ready                   = error_db::entry<"Fence not ready">;
        using fence_timeout                     = error_db::entry<"Fence wait timed out">;
        using fence_uninitialized               = error_db::entry<"Attempting to use an uninitialized fence">;
        using fence_unknown                     = error_db::entry<"Unknown fence error">;
    }

    ViFence::ViFence()
    {
    }
    
    ViFence::ViFence(VkDevice dev)
    {
        if(dev){
            if(_init(dev) != std::error_code()){
                _wipe();
            }
        }
    }
    
    ViFence::ViFence(ViVisualizer&viz) : ViFence(viz.device())
    {
    }


    ViFence::~ViFence()
    {
        kill();
    }

    std::error_code ViFence::_init(VkDevice dev)
    {
        VqFenceCreateInfo   fci;
        VkResult res = vkCreateFence(dev, &fci, nullptr, &m_fence);
        if(res != VK_SUCCESS){
            vizWarning << "vkFenceCreate(1): vkResult " << (int64_t) res;
            m_fence = nullptr;
            return errors::fence_cant_create();
        }
        
        m_device    = dev;
        return {};
    }
    
    void    ViFence::_kill()
    {
        vkDestroyFence(m_device, m_fence, nullptr);
    }
    
    std::error_code ViFence::_reset()
    {
        switch(vkResetFences(m_device, 1, &m_fence)){
        case VK_SUCCESS:
            return {};
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:
            return errors::vulkan_out_of_device_memory();
        default:
            return errors::fence_unknown();
        }
    }

    std::error_code ViFence::_wait(uint64_t timeout)
    {
        switch(vkWaitForFences(m_device, 1, &m_fence, VK_FALSE, timeout)){
        case VK_SUCCESS:
            return {};
        case VK_TIMEOUT:
            return errors::fence_timeout();
        case VK_ERROR_OUT_OF_HOST_MEMORY:
            return errors::vulkan_out_of_host_memory();
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:
            return errors::vulkan_out_of_device_memory();
        case VK_ERROR_DEVICE_LOST:
            return errors::vulkan_device_lost();
        default:
            return errors::fence_unknown();
        }
    }

    void    ViFence::_wipe()
    {
        m_device    = nullptr;
        m_fence     = nullptr;
    }

    std::error_code ViFence::init(VkDevice dev)
    {
        if(!consistent())
            return errors::fence_bad_state();
        if(valid())
            return errors::fence_existing();
        if(!dev)
            return errors::visualizer_uninitialized();
        return _init(dev);
    }
    
    std::error_code ViFence::init(ViVisualizer&viz)
    {
        return init(viz.device());
    }
    
    bool            ViFence::consistent() const
    {
        return m_device ? static_cast<bool>(m_fence) : !m_fence;
    }

    void            ViFence::kill()
    {
        if(valid()){
            _kill();
        }
        _wipe();
    }

    std::error_code ViFence::reset()
    {
        if(!valid()){
            if(!consistent())
                return errors::fence_bad_state();
            return errors::fence_uninitialized();
        }
        return _reset();
    }
    
    std::error_code ViFence::status() const
    {
        if(!valid()){
            if(!consistent())
                return errors::fence_bad_state();
            return errors::fence_uninitialized();
        }
            
        switch(vkGetFenceStatus(m_device, m_fence)){
        case VK_SUCCESS:
            return {};
        case VK_NOT_READY:
            return errors::fence_not_ready();
        case VK_ERROR_DEVICE_LOST:
            return errors::vulkan_device_lost();
        default:
            return errors::fence_unknown();
        }
    }
    
    bool            ViFence::valid() const
    {
        return m_device && m_fence;
    }
    
    std::error_code ViFence::wait(uint64_t timeout)
    {
        if(!valid()){
            if(!consistent())
                return errors::fence_bad_state();
            return errors::fence_uninitialized();
        }
        return _wait(timeout);
    }

}
