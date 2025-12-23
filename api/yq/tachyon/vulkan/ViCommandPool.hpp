////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <system_error>
#include <vulkan/vulkan_core.h>
#include <yq/core/Flags.hpp>
#include <yq/tachyon/typedef/vi_queue_id.hpp>
#include <yq/tachyon/vulkan/ViQueueType.hpp>

namespace yq::tachyon {
    class ViDevice;
    

    enum class VqCommandPoolCreateBit : uint8_t {
        Transient = 1,
        ResetCommandBuffer = 2,
        Protected = 3
    };

    enum class VqCommandPoolResetBit : uint8_t {
        ReleaseResources = 1
    };
    
    using VqCommandPoolCreateFlags = Flags<VqCommandPoolCreateBit>;
    using VqCommandPoolResetFlags = Flags<VqCommandPoolResetBit>;

    class ViCommandPool {
    public:
    
        ViCommandPool(ViDevice&, ViQueueType, VqCommandPoolCreateFlags={});
        ViCommandPool(ViDevice&, ViQueueFamilyID, VqCommandPoolCreateFlags={});
        ViCommandPool(ViDevice&, const VkCommandPoolCreateInfo&);
        ~ViCommandPool();
        
        operator VkCommandPool() const { return m_pool; }

        VkCommandPool   command_pool() const { return m_pool; }
        bool            valid() const { return static_cast<bool>(m_pool); }

        void            kill();
        std::error_code reset(VqCommandPoolResetFlags={});
        
    private:
        ViDevice&           m_device;
        VkCommandPool       m_pool      = nullptr;
        
        static VkCommandPoolCreateInfo _info(ViQueueFamilyID, VqCommandPoolCreateFlags);
        std::error_code _init(const VkCommandPoolCreateInfo&);
        void            _kill();
        void            _wipe();
        std::error_code _reset(VkCommandPoolResetFlags);
    };
}
