////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViFence.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/v/VqEnumerations.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    ViFence::ViFence()
    {
    }
    
    ViFence::ViFence(ViVisualizer&viz)
    {
        if(viz.device()){
            if(_init(viz) != std::error_code()){
                _wipe();
            }
        }
    }

    ViFence::~ViFence()
    {
        kill();
    }

    std::error_code ViFence::_init(ViVisualizer& viz)
    {
        VqFenceCreateInfo   fci;
        VkResult res = vkCreateFence(viz.device(), &fci, nullptr, &m_fence);
        if(res != VK_SUCCESS){
            vizWarning << "vkFenceCreate(1): " << to_string_view((VqResult) res);
            m_fence = nullptr;
            return errors::fence_cant_create();
        }
        
        m_viz   = &viz;
        return {};
    }
    
    void    ViFence::_kill()
    {
        vkDestroyFence(m_viz->device(), m_fence, nullptr);
    }
    
    std::error_code ViFence::_reset()
    {
        switch(vkResetFences(m_viz->device(), 1, &m_fence)){
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
        switch(vkWaitForFences(m_viz->device(), 1, &m_fence, VK_FALSE, timeout)){
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
        m_viz   = nullptr;
        m_fence = nullptr;
    }

    std::error_code ViFence::init(ViVisualizer&viz)
    {
        if(!consistent())
            return errors::fence_bad_state();
        if(valid())
            return errors::fence_existing();
        if(!viz.device())
            return errors::visualizer_uninitialized();
        return _init(viz);
    }
    
    bool            ViFence::consistent() const
    {
        return m_viz ? (m_fence && m_viz->device()) : !m_fence;
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
            
        switch(vkGetFenceStatus(m_viz->device(), m_fence)){
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
        return m_viz && m_fence && m_viz->device();
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