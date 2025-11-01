////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/vulkan/ViFence.hpp>
#include <tachyon/errors.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/vulkan/VqStructs.hpp>
#include <tachyon/vulkan/ViDevice.hpp>
#include <yq/core/Ref.hpp>

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

    ViFence::ViFence(ViDevice& dev) : m_device(dev)
    {
        VqFenceCreateInfo   fci;
        VkResult res = vkCreateFence(m_device.device(), &fci, nullptr, &m_fence);
        if(res != VK_SUCCESS){
            vizWarning << "vkFenceCreate(1): vkResult " << (int64_t) res;
            m_fence = nullptr;
        }
    }

    ViFence::~ViFence()
    {
        if(m_fence){
            vkDestroyFence(m_device.device(), m_fence, nullptr);
            m_fence = nullptr;
        }
    }

    std::error_code ViFence::_reset()
    {
        switch(vkResetFences(m_device.device(), 1, &m_fence)){
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
        switch(vkWaitForFences(m_device.device(), 1, &m_fence, VK_FALSE, timeout)){
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

    std::error_code ViFence::reset()
    {
        if(!valid())
            return errors::fence_uninitialized();
        return _reset();
    }
    
    std::error_code ViFence::status() const
    {
        if(!valid())
            return errors::fence_uninitialized();
            
        switch(vkGetFenceStatus(m_device.device(), m_fence)){
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
    
    std::error_code ViFence::wait(uint64_t timeout)
    {
        if(!valid())
            return errors::fence_uninitialized();
        return _wait(timeout);
    }

}
